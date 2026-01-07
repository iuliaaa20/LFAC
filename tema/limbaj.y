%{
#include <iostream>
#include <string>
#include <vector>

#include "SymTableHelp.h"  
#include "AST.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext; 
extern FILE* yyin; 
void yyerror(const char * s); 

%}

/* Blocul code requires este necesar pentru ca header-ul sa stie de vector si ASTNode */
%code requires {
    #include <vector>
    #include "AST.h"
}

%union {
    std::string* Str;
    class ASTNode* Node;           
    std::vector<class ASTNode*>* List;
}; 

%token BGIN END CLASS_BC  NEW_BC FN_BC ACCES VOID_BC // aici am pus void bc pt elf lenes
%token IF_BC ELSE_BC WHILE_BC RETURN_BC PRINT_BC 
%token ASSIGN_GIFT ATELIER_AND_COR DECORATIUNI_OR_COLINDE EQ_GIFTS NEQ_GIFTS LE_GIFTS GE_GIFTS LT_GIFTS GT_GIFTS NOT_BC

%token <Str> INT_BC FLOAT_BC STRING_BC BOOL_BC 
%token <Str> ID_BC STRING_VAL BOOL_VAL_BC NR FLOAT_NR 

/* Definim tipurile returnate de neterminali */
%type <Str> type return_type 
%type <Node> e e_bool call_fn statement 
%type <List> statement_list 


%left DECORATIUNI_OR_COLINDE  
%left ATELIER_AND_COR         
%left EQ_GIFTS NEQ_GIFTS      
%left LT_GIFTS GT_GIFTS LE_GIFTS GE_GIFTS 
%left '+' '-' 
%left '*' '/'
%left ACCES
%right NOT_BC

%start progr

%%


progr : { SymTableHelp::Init(); } orice main_bc { 
            cout << "Sintaxa corecta. Mos Craciun a ajuns" << endl;
            SymTableHelp::Clean(); 
        }
      ; 

orice: orice elem 
      |
      ;

elem : decl 
     | class_decl 
     | fn_decl
     | statement // am adaugat ca sa putem asigna si in global scope
 
     ;

type : INT_BC    { SymTableHelp::SetType("int_gift");   $$ = new std::string("int_gift"); }
     | FLOAT_BC  { SymTableHelp::SetType("float_snow"); $$ = new std::string("float_snow"); }
     | STRING_BC { SymTableHelp::SetType("str_letter"); $$ = new std::string("str_letter"); }
     | BOOL_BC   { SymTableHelp::SetType("bool");       $$ = new std::string("bool"); }
     | NEW_BC ID_BC {    
      SymTableHelp::CheckClassExists(*$2);
      SymTableHelp::SetType(*$2); 
      $$ = new std::string(*$2);
      }
     | VOID_BC    {SymTableHelp::SetType("lenes");  $$=new std::string("lenes");}
 
     ; 
 
return_type : type ; 

decl : type list_variabile ';' {delete $1;} ; // am pus delete aici sa prevenim memory leak

list_variabile : ID_BC { SymTableHelp::AddVar(*$1, "variabila"); delete $1; }
               | list_variabile ',' ID_BC { SymTableHelp::AddVar(*$3, "variabila"); delete $3; }
               ;


class_decl : CLASS_BC ID_BC { 
                SymTableHelp::SetType("definitie_clasa");        
                SymTableHelp::AddVar(*$2, "clasa");        
                SymTableHelp::EnterScope("Class_" + *$2);  
                
                SymTableHelp::AddClassScope(*$2, SymTableHelp::currentScope);
             } 
             '[' class_body ']' { 
                SymTableHelp::ExitScope();                
             }
           ;

class_body : class_body decl      
           | class_body fn_decl 
           | 
           ;

header_fn: FN_BC return_type ID_BC {
           SymTableHelp::currentFuncName = *$3; 
           SymTableHelp::SetType(*$2); 
           SymTableHelp::AddVar(*$3, "functie"); 
           SymTableHelp::EnterScope("Func_" + *$3);
         }
         ;

fn_decl : header_fn '^' list_param '^' { SymTableHelp::SaveParams(); }'[' fn_body ']' { SymTableHelp::ExitScope(); }
        | header_fn '^' '^' { SymTableHelp::SaveParams(); } '[' fn_body ']' { SymTableHelp::ExitScope(); }
        ;

list_param : param 
           | list_param ',' param ;

param : type ID_BC { SymTableHelp::AddParam(*$2); delete $1; delete $2;} ; // am pus delete si aici


fn_body : declarations statement_list 
        ;
declarations : declarations decl 
            |
            ;


main_bc : BGIN { SymTableHelp::EnterScope("Main"); } statement_list END 
               { 
            // AICI SE FACE EXECUTIA AST 
            if ($3 != NULL) {
                 for(ASTNode* n : *$3) 
                   if(n) n->eval(SymTableHelp::currentScope);
            }
            SymTableHelp::ExitScope(); 
        } ;

statement_list : { $$ = new std::vector<ASTNode*>(); } 
               | statement_list statement { 
                   if ($2 != NULL) $1->push_back($2);
                   $$ = $1;
               }
               ;

statement : ID_BC ASSIGN_GIFT e ';' { 
          SymTableHelp::CheckId(*$1); 
          string tipSt=SymTableHelp::GetType(*$1);
          // Verificam NULL pentru a preveni segfault daca expresia e gresita
          string tipDr = ($3 != NULL) ? $3->type : "eroare"; 

          if(tipSt!=tipDr && tipDr!="eroare"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui valoarea de tip "<<tipDr<<" variabilei "<<*$1<<" de tip "<<tipSt<<endl;
          }
          
          // CONSTRUIM NODUL DE ATRIBUIRE
          // Trebuie sa recream nodul variabilei din stanga (pentru ca $1 e doar string)
          // Constructor: ASTNode(tip, nume_var)
          ASTNode* leftNode = new ASTNode(tipSt, *$1);
          
          // Constructor General: ASTNode(tip, ROOT=":=", left, right)
          $$ = new ASTNode(tipSt, ":=", leftNode, $3);
          
          delete $1;
          }
          | ID_BC ACCES ID_BC ASSIGN_GIFT e ';' { 
            SymTableHelp::CheckId(*$1); 
            if(SymTableHelp::CheckClassMember(*$1,*$3)){
              string tipMembru=SymTableHelp::GetClassMemberType(*$1,*$3);
              string tipE = ($5 != NULL) ? $5->type : "eroare";

              if(tipMembru!=tipE && tipE!="eroare"){
                cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui "<<tipE<<" campului "<<*$3<<" ("<<tipMembru<<")"<<endl;
              }
            }
            // Aici ramane OTHER pentru ca nu implementam logica complexa de clase
            $$ = new ASTNode("void", "OTHER"); 
            delete $1; delete $3;
            }
          |ID_BC ASSIGN_GIFT e_bool ';' { 
              SymTableHelp::CheckId(*$1); 
              string tipSt=SymTableHelp::GetType(*$1);
              string tipDr = ($3 != NULL) ? $3->type : "eroare";

              if(tipSt!=tipDr && tipDr!="eroare"){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui valoarea de tip "<<tipDr<<" variabilei "<<*$1<<" de tip "<<tipSt<<endl;
              }
              
              // Constructie nod := pentru bool
              ASTNode* leftNode = new ASTNode(tipSt, *$1);
              $$ = new ASTNode(tipSt, ":=", leftNode, $3);
              
              delete $1;
          }
          | ID_BC ACCES ID_BC ASSIGN_GIFT e_bool ';' { 
            SymTableHelp::CheckId(*$1); 
            if(SymTableHelp::CheckClassMember(*$1,*$3)){
              string tipMembru=SymTableHelp::GetClassMemberType(*$1,*$3);
              string tipE = ($5 != NULL) ? $5->type : "eroare";

              if(tipMembru!=tipE && tipE!="eroare"){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui "<<tipE<<" campului "<<*$3<<" ("<<tipMembru<<")"<<endl;
              }
            }
           $$ = new ASTNode("void", "OTHER"); 
           delete $1; delete $3;
            }
          
          // CONTROL FLOW returneaza NULL conform cerintei
          | IF_BC '(' e_bool ')' '{' statement_list '}'{$$=NULL;}
          | IF_BC '(' e_bool ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'{$$=NULL;} // am adaugat if si while pt e aici ca sa putem face if(id_de_bool)
          | IF_BC '(' e ')' '{' statement_list '}'{
            if($3!=NULL){
              if($3->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'if' trebuie sa fie de tip bool, nu "<<$3->type<<endl;
            }
            $$=NULL;
            }
          | IF_BC '(' e ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'{
             if($3!=NULL){
              if($3->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'if' trebuie sa fie de tip bool, nu "<<$3->type<<endl;
            }
            $$=NULL;
            }
          | WHILE_BC '(' e_bool ')' '{' statement_list '}'{$$=NULL;}
          | WHILE_BC '(' e ')' '{' statement_list '}'{
            if($3!=NULL){
              if($3->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'while' trebuie sa fie de tip bool, nu "<<$3->type<<endl;
            }            
            $$=NULL;}
          
          | PRINT_BC '(' e ')' ';'{
              $$ = new ASTNode("void", "PRINT", $3, NULL);
          } 
          | PRINT_BC '(' e_bool ')' ';'{
              $$ = new ASTNode("void", "PRINT", $3, NULL);
          } 
          | call_fn ';'{$$=$1;}
          | RETURN_BC e ';' { // la returnuri am pus verificarea daca tipul functiei este si acela returnat si sunt tratate si cazurile cu 'lenes'
            std::string tipReturn=($2!=NULL)?$2->type:"eroare";
            std::string tipFct=SymTableHelp::GetType(SymTableHelp::currentFuncName);

            if(tipFct!="eroare" && tipReturn!="eroare"){
              if(tipFct!=tipReturn){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<SymTableHelp::currentFuncName<<" este de tip "<<tipFct<<" dar returneaza o valoare de tip "<<tipReturn<<endl;            
                }
            }

            if(tipFct=="lenes"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": O functie de tip lenes nu poate returna o valoare"<<endl;  
            }

            $$=NULL;
            } 
          | RETURN_BC e_bool ';' {
            std::string tipReturn="bool";
            std::string tipFct=SymTableHelp::GetType(SymTableHelp::currentFuncName);

            if(tipFct!="eroare"){
              if(tipFct!="bool"){
               std::cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<SymTableHelp::currentFuncName<<" este de tip "<<tipFct<<" dar returneaza o valoare de tip bool"<<endl;
              }
            }
            if(tipFct=="lenes"){
              std::cout<<"Eroare semantica la linia "<<yylineno<<": O functie de tip lenes nu poate returna o valoare"<<endl;
            }

            $$=NULL;
            }
            //aici regula pt fct void
          | RETURN_BC ';' {
            std::string tipFct=SymTableHelp::GetType(SymTableHelp::currentFuncName);

            if(tipFct!="lenes" && tipFct !="eroare"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<SymTableHelp::currentFuncName<<" este de tip "<<tipFct<<" si trebuie sa returneze o valoare"<<endl;
            }
            
            $$=NULL;}
          ;

e_bool: e EQ_GIFTS e {
        string t1 = ($1 != NULL) ? $1->type : "eroare";
        string t3 = ($3 != NULL) ? $3->type : "eroare";

        if(t1 != t3 && t1 != "eroare" && t3 != "eroare") {
            cout << "Eroare semantica la linia " << yylineno << ": Nu se pot compara tipuri diferite (" << t1 << " == " << t3 << ")" << endl;
             // Facem un nod dummy cu tipul eroare pentru a nu crapa mai sus
             $$ = new ASTNode("eroare", "OTHER");
             if($1) delete $1; if($3) delete $3;
        }
        else{
            $$ = new ASTNode("bool", "==", $1, $3);
       }
      }
 | e NEQ_GIFTS e {
        string t1 = ($1 != NULL) ? $1->type : "eroare";
        string t3 = ($3 != NULL) ? $3->type : "eroare";

        if(t1 != t3 && t1 != "eroare" && t3 != "eroare") {
            cout << "Eroare semantica la linia " << yylineno << ": Nu se pot compara tipuri diferite (" << t1 << " != " << t3 << ")" << endl;
            $$ = new ASTNode("eroare", "OTHER");
            if($1) delete $1; if($3) delete $3;
        }
        else{
            $$ = new ASTNode("bool", "!=", $1, $3); 
        }        
  }
  | e LE_GIFTS e {
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " <= " << t3 << ")" << endl;
      }
      $$ = new ASTNode("eroare", "OTHER");
      if($1) delete $1; if($3) delete $3;
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia "<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       $$ = new ASTNode("eroare", "OTHER");
       if($1) delete $1; if($3) delete $3;
    }
      else
      { 
         $$ = new ASTNode("bool", "<=", $1, $3);
      }
    }    
  | e GE_GIFTS e {
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";
    
    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
        cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " >= " << t3 << ")" << endl;
      }
      $$ = new ASTNode("eroare", "OTHER");
      if($1) delete $1; if($3) delete $3;
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia "<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       $$ = new ASTNode("eroare", "OTHER");
       if($1) delete $1; if($3) delete $3;
    }
      else
      { 
          $$ = new ASTNode("bool", ">=", $1, $3); 
      }
    }    
  | e LT_GIFTS e {
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " < " << t3 << ")" << endl;
      }
      $$ = new ASTNode("eroare", "OTHER");
      if($1) delete $1; if($3) delete $3;
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia"<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       $$ = new ASTNode("eroare", "OTHER");
       if($1) delete $1; if($3) delete $3;
    }
      else
      { 
          $$ = new ASTNode("bool", "<", $1, $3); 
      }
    }    
  | e GT_GIFTS e {
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " > " << t3 << ")" << endl;
      }
      $$ = new ASTNode("eroare", "OTHER");
      if($1) delete $1; if($3) delete $3;
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia"<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       $$ = new ASTNode("eroare", "OTHER");
       if($1) delete $1; if($3) delete $3;
    }
      else
      { 
          $$ = new ASTNode("bool", ">", $1, $3);
      }
    }    
  | '(' e_bool ')' { $$ = $2; }

  | e_bool EQ_GIFTS e_bool{
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";
    
    if (t1 == "eroare" || t3 == "eroare") {
          $$ = new ASTNode("eroare", "OTHER");
          if($1) delete $1; if($3) delete $3;
      } else {
        $$ = new ASTNode("bool", "==", $1, $3);
      }
  }
  | e_bool NEQ_GIFTS e_bool{
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if (t1 == "eroare" || t3 == "eroare") {
          $$ = new ASTNode("eroare", "OTHER");
          if($1) delete $1; if($3) delete $3;
      } else {
       $$ = new ASTNode("bool", "!=", $1, $3);
      }
  }
  | e_bool EQ_GIFTS e { 
    std::string t3=($3 !=NULL)? $3->type : "eroare";

    if(t3=="bool"){
       $$ = new ASTNode("bool", "==", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite (bool =="<< t3 << " )" << endl;
          $$ = new ASTNode("eroare", "OTHER");
    }}
  | e_bool NEQ_GIFTS e {
    std::string t3=($3 !=NULL)? $3->type : "eroare";

    if(t3=="bool"){
       $$ = new ASTNode("bool", "!=", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite (bool !="<< t3 << " )" << endl;
          $$ = new ASTNode("eroare", "OTHER");
    }
   }
  | e EQ_GIFTS e_bool { 
    std::string t1=($1 !=NULL)? $1->type : "eroare";

    if(t1=="bool"){
       $$ = new ASTNode("bool", "==", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " == bool)" << endl;
          $$ = new ASTNode("eroare", "OTHER");
    }
  }
    | e NEQ_GIFTS e_bool { 
      std::string t1=($1 !=NULL)? $1->type : "eroare";

    if(t1=="bool"){
       $$ = new ASTNode("bool", "!=", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " != bool)" << endl;
          $$ = new ASTNode("eroare", "OTHER");
    }
   }
  | e_bool ATELIER_AND_COR e_bool{ 
     $$ = new ASTNode("bool", "&&", $1, $3);
  }
  | e ATELIER_AND_COR e{
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if(t1=="bool" && t3=="bool")
     {$$ = new ASTNode("bool", "&&", $1, $3);} //am pus astea si acum merge if(v1 && v2)
    else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit "<<t1<<" si "<<t3<<endl;
        //facem nod dummy ca sa nu crape apoi
        $$=new ASTNode("eroare","OTHER");
    }
  }
  | e_bool ATELIER_AND_COR e{ 
    std::string t3=($3 != NULL)?$3->type:"eroare";
    if(t3=="bool"){
      $$=new ASTNode("bool","&&",$1,$3);
    }else{
          std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit bool si "<<t3<<endl;
        $$=new ASTNode("eroare","OTHER");
    }
  }
  | e ATELIER_AND_COR e_bool{
    std::string t1=($1 != NULL)?$1->type:"eroare";
    if(t1=="bool"){
      $$ = new ASTNode("bool", "&&", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit "<<t1<<" si bool"<<endl;
        $$=new ASTNode("eroare","OTHER");
    }
  }
  | e_bool DECORATIUNI_OR_COLINDE e_bool { // toate combinatiile pt or ca sa fie posibil id (de bool )or nice 
     $$ = new ASTNode("bool", "||", $1, $3);
  }
  | e DECORATIUNI_OR_COLINDE e {
    string t1 = ($1 != NULL) ? $1->type : "eroare";
    string t3 = ($3 != NULL) ? $3->type : "eroare";

    if(t1=="bool" && t3=="bool")
     {$$ = new ASTNode("bool", "||", $1, $3);} 
    else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit "<<t1<<" si "<<t3<<endl;
        $$=new ASTNode("eroare","OTHER");
    }}
  | e_bool DECORATIUNI_OR_COLINDE e {
      std::string t3=($3 != NULL)?$3->type:"eroare";
    if(t3=="bool"){
      $$=new ASTNode("bool","||",$1,$3);
    }else{
          std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit bool si "<<t3<<endl;
        $$=new ASTNode("eroare","OTHER");
    }
  }
  | e DECORATIUNI_OR_COLINDE e_bool {
     std::string t1=($1 != NULL)?$1->type:"eroare";
    if(t1=="bool"){
      $$ = new ASTNode("bool", "||", $1, $3);
    }else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit "<<t1<<" si bool"<<endl;
        $$=new ASTNode("eroare","OTHER");
    }
  }
  | BOOL_VAL_BC {
      Val v;
      if(*$1 == "nice") v.bval = true; else v.bval = false; 
      v.tip = MY_BOOL; 
   
      // Constructor Constanta
  $$ = new ASTNode(v, "bool");
      delete $1;
  }
  | NOT_BC e_bool { 
      // Operator Unar (Copilul stang e expresia, drept e NULL)
      $$ = new ASTNode("bool", "!", $2, NULL);
  }
  | NOT_BC e{ // daca avem tot asa un id de valoare bool
    std::string t=($2!=NULL)? $2->type:"eroare";
    if(t=="bool"){
      $$=new ASTNode("bool","!",$2,NULL);
    } else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'not' cere tipul bool, dar a primit "<<t<<endl;
      $$=new ASTNode("eroare","OTHER");
    }
  }
  ;

e : e '+' e {
      std::string tipSt = ($1 != NULL) ? $1->type : "eroare";
      std::string tipDr = ($3 != NULL) ? $3->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow" || tipSt == "str_letter"){
           // Construim Nodul Adunare (+)
          $$ = new ASTNode(tipSt, "+", $1, $3);
        }
        else{
            std::cout<<"Eroare semantica la linia "<< yylineno <<": Adunarea nu este permisa pentru tipul "<<tipSt<<endl;
            $$ = new ASTNode("eroare", "OTHER");
             if($1) delete $1; if($3) delete $3;   
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa adunarea de tipuri diferite ("<<tipSt<<" + "<<tipDr<<")"<<endl;
        $$ = new ASTNode("eroare", "OTHER");
        if($1) delete $1; if($3) delete $3;
      }
      
}
  | e '-' e {
      std::string tipSt = ($1 != NULL) ? $1->type : "eroare";
      std::string tipDr = ($3 != NULL) ? $3->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
         $$ = new ASTNode(tipSt, "-", $1, $3); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Scaderea nu este permisa pentru tipul "<<tipSt<<endl;
            $$ = new ASTNode("eroare", "OTHER");   
            if($1) delete $1; if($3) delete $3;   
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa scaderea de tipuri diferite"<<endl;
        $$ = new ASTNode("eroare", "OTHER");
        if($1) delete $1; if($3) delete $3;
      }
  }
  | e '*' e {
      std::string tipSt = ($1 != NULL) ? $1->type : "eroare";
      std::string tipDr = ($3 != NULL) ? $3->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
         $$ = new ASTNode(tipSt, "*", $1, $3); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Inmultirea nu este permisa pentru tipul "<<tipSt<<endl;
            $$ = new ASTNode("eroare", "OTHER"); 
            if($1) delete $1; if($3) delete $3;     
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa inmultirea de tipuri diferite"<<endl;
        $$ = new ASTNode("eroare", "OTHER");
        if($1) delete $1; if($3) delete $3;
      }
  } 
  | e '/' e {
      std::string tipSt = ($1 != NULL) ? $1->type : "eroare";
      std::string tipDr = ($3 != NULL) ? $3->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
          $$ = new ASTNode(tipSt, "/", $1, $3); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Impartirea nu este permisa pentru tipul "<<tipSt<<endl;
            $$ = new ASTNode("eroare", "OTHER");  
            if($1) delete $1; if($3) delete $3;    
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa impartirea de tipuri diferite"<<endl;
        $$ = new ASTNode("eroare", "OTHER");
        if($1) delete $1; if($3) delete $3;
      }
  } 
  | '(' e ')' { $$ = $2; }
  
  | NR  {
      int val = stoi(*$1);
      Val v(val);
      // Constructor Constanta
$$ = new ASTNode(v, "int_gift");
      delete $1; 
  }
  | FLOAT_NR {
      float val = stof(*$1);
      Val v(val);
      // Constructor Constanta
     $$ = new ASTNode(v, "float_snow");
      delete $1;
  }
  | STRING_VAL {
      Val v(*$1);
      // Constructor Constanta
      $$ = new ASTNode( v,"str_letter");
      delete $1;
  }
  | ID_BC { 
        if(SymTableHelp::CheckId(*$1))
        {
          string tip = SymTableHelp::GetType(*$1);
          // Constructor Variabila (Root = nume)
          $$ = new ASTNode(tip, *$1);
        }
        else{
          $$ = new ASTNode("eroare", "OTHER");
        }
        delete $1;
   }  
  | ID_BC ACCES ID_BC {
    SymTableHelp::CheckId(*$1);
    string tip = "eroare";
    if(SymTableHelp::CheckClassMember(*$1,*$3)){
       tip = SymTableHelp::GetClassMemberType(*$1,*$3);
    }
    // Acces clasa -> Nod OTHER
    $$ = new ASTNode(tip, "OTHER");
    delete $1; delete $3;
  }
  | call_fn { $$ = $1; } 
  ;
// aici avem mesaje cu eroare semantica in SymTableHelp cica si daca punem si aici se dubleaza
// function calls returneaza ASTNode cu root OTHER
call_fn: ID_BC '(' {SymTableHelp::ClearCallArg(); } wishlist ')' { 
      //bool exists = SymTableHelp::CheckId(*$1);  
      //Facem aici modificari ca sa se afiseze mesajul corect pt cand nu e declarata o functie
      bool exists = SymTableHelp::CheckFunctionExists(*$1);
      bool checkParams = false;
      if(exists){
        checkParams= SymTableHelp::CheckFunctionCall(*$1);
      }

      if(exists && checkParams){
        string tip = SymTableHelp::GetType(*$1);
      
        $$ = new ASTNode(tip, "OTHER");
      }
      else{
        $$ = new ASTNode("eroare", "OTHER");
      }
      delete $1;
      }
       | ID_BC '(' ')' { 
            SymTableHelp::ClearCallArg();
            bool exists = SymTableHelp::CheckFunctionExists(*$1); 
            bool checkParams = false;
                  
            if(exists){
              checkParams= SymTableHelp::CheckFunctionCall(*$1);
            }

            if(exists && checkParams){
              string tip = SymTableHelp::GetType(*$1);
              $$ = new ASTNode(tip, "OTHER");
            }
            else{
              $$ = new ASTNode("eroare", "OTHER");
            }
            delete $1;
       }
       | ID_BC ACCES ID_BC '('{SymTableHelp::ClearCallArg();} wishlist ')'{
            if(SymTableHelp::CheckId(*$1)){
              if(SymTableHelp::CheckClassMethodCall(*$1,*$3)){
                 string tip = SymTableHelp::GetClassMemberType(*$1,*$3);
                 $$ = new ASTNode(tip, "OTHER");
              }else{
               //? std::cout<<"Eroare semantica la linia "<<yylineno<< ": Metoda nu exista sau argumente gresite";
                $$ = new ASTNode("eroare", "OTHER");
              }
          }
          else{
            $$ = new ASTNode("eroare", "OTHER");
          }
          delete $1; delete $3;
          }
       | ID_BC ACCES ID_BC '(' ')'{
        if(SymTableHelp::CheckId(*$1)){
          SymTableHelp::ClearCallArg();
          if(SymTableHelp::CheckClassMethodCall(*$1,*$3)){
            string tip = SymTableHelp::GetClassMemberType(*$1,*$3);
            $$ = new ASTNode(tip, "OTHER");
          }
          else{
            $$ = new ASTNode("eroare", "OTHER");
          }
        }
        else{
          $$ = new ASTNode("eroare", "OTHER");
        }
        delete $1; delete $3;
       }
       ;


wishlist : e {SymTableHelp::AddCallArg(($1 != NULL) ? $1->type : "eroare");}
         |  wishlist ',' e {SymTableHelp::AddCallArg(($3 != NULL) ? $3->type : "eroare");}
         | e_bool {SymTableHelp::AddCallArg(($1 != NULL) ? $1->type : "eroare");}
         |  wishlist ',' e_bool {SymTableHelp::AddCallArg(($3 != NULL) ? $3->type : "eroare");}
         ; 


%%

void yyerror(const char * s){
    std::cout << "Eroare la linia " << yylineno << ": " << s << std::endl;
}

int main(int argc, char** argv){
    if(argc > 1) yyin = fopen(argv[1], "r");
    yyparse();  
    return 0;
}
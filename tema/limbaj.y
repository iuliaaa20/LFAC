%{
#include <iostream>
#include <string>
#include "SymTableHelp.h"  

using namespace std;

//declaratii externe pentru a lega yacc-ul de lexer
extern int yylex();
extern int yylineno;
extern char* yytext; 
extern FILE* yyin; //asta i pointerul cu care umbla lexul prin programul care se compileaza
void yyerror(const char * s); //functia standard pt erori de sintaxa

%}

%union {
    std::string* Str;
}; //momentan folosim doar string pointer pentru a plimba numele si tipurile

//tokens 
%token BGIN END CLASS_BC  NEW_BC FN_BC ACCES
%token IF_BC ELSE_BC WHILE_BC RETURN_BC PRINT_BC 
%token ASSIGN_GIFT ATELIER_AND_COR DECORATIUNI_OR_COLINDE EQ_GIFTS NEQ_GIFTS LE_GIFTS GE_GIFTS LT GT NOT_BC

//tokeni care au si valoare (numele lor sau valoarea numerica, retinuta in Str):
%token <Str> INT_BC FLOAT_BC STRING_BC BOOL_BC 
%token <Str> ID_BC STRING_VAL BOOL_VAL_BC NR FLOAT_NR 

// aici ii spunem ca regulile 'type' si 'return_type' returneaza un pointer la string (<Str>)
// asta ne permite sa folosim $$ = ... in ele si *$2 in regulile parinte fara sa primim erori de compilare
%type <Str> type return_type 

//prioritate operatori :
%left DECORATIUNI_OR_COLINDE  
%left ATELIER_AND_COR         
%left EQ_GIFTS NEQ_GIFTS      
%left LT GT LE_GIFTS GE_GIFTS 
%left '+' '-' 
%left '*' '/'
%left ACCES
%right NOT_BC

%start progr

%%


progr : { SymTableHelp::Init(); } orice main_bc { 
            cout << "Sintaxa corecta. Mos Craciun a ajuns" << endl;
            SymTableHelp::Clean(); //la final curatam memoria si inchidem fisierul
        }
      ; 
//regula recursiva pentru blocul global 
orice: orice elem 
      |
      ;

elem : decl 
     | class_decl 
     | fn_decl 
     ;


//1. Seteaza tipul curent in SymTableHelp (pt declaratii de variabile simple)
//2. Returneaza string-ul tipului prin $$ (pt a fi folosit mai sus in header_fn sau params)
type : INT_BC    { SymTableHelp::SetType("int_gift");   $$ = new std::string("int_gift"); }
     | FLOAT_BC  { SymTableHelp::SetType("float_snow"); $$ = new std::string("float_snow"); }
     | STRING_BC { SymTableHelp::SetType("str_letter"); $$ = new std::string("str_letter"); }
     | BOOL_BC   { SymTableHelp::SetType("bool");       $$ = new std::string("bool"); }
     | NEW_BC ID_BC {    SymTableHelp::SetType(*$2);  $$ = new std::string(*$2); //propag numele clasei mai departe
 } 
     ; 
 
return_type : type ; 

decl : type list_variabile ';' ;

//adaugam variabile in scope-ul curent 
list_variabile : ID_BC { SymTableHelp::AddVar(*$1, "variabila"); }
               | list_variabile ',' ID_BC { SymTableHelp::AddVar(*$3, "variabila"); }
               ;


//cand intalnesc o clasa, intru in scope-ul ei, parsez corpul, si apoi ies
class_decl : CLASS_BC ID_BC { 
                SymTableHelp::AddVar(*$2, "clasa");        
                SymTableHelp::EnterScope("Class_" + *$2);  
             } 
             '[' class_body ']' { 
                SymTableHelp::ExitScope();                
             }
           ;

class_body : class_body decl      
           | class_body fn_decl 
           | 
           ;

//regula ajutatoare pentru functii
//Aici folosim *$2 care contine tipul returnat de regula 'return_type'
header_fn: FN_BC return_type ID_BC {
           SymTableHelp::currentFuncName = *$3; //retin numele functiei pt a-i atasa parametrii mai tarziu
           SymTableHelp::SetType(*$2); 
           SymTableHelp::AddVar(*$3, "functie"); 
           SymTableHelp::EnterScope("Func_" + *$3);
         }
         ;

//dupa ce am citit lista de parametri, apelez SaveParams
//aceasta muta parametrii din bufferul temporar in definitia functiei din scope-ul parinte
fn_decl : header_fn '^' list_param '^' { SymTableHelp::SaveParams(); }'[' fn_body ']' { SymTableHelp::ExitScope(); }
        | header_fn '^' '^' { SymTableHelp::SaveParams(); } '[' fn_body ']' { SymTableHelp::ExitScope(); }
        ;

list_param : param 
           | list_param ',' param ;

param : type ID_BC { SymTableHelp::AddParam(*$2); } ;


fn_body : declarations statement_list 
        ;
declarations : declarations decl 
            |
            ;


main_bc : BGIN { SymTableHelp::EnterScope("Main"); } statement_list END { SymTableHelp::ExitScope(); } ;

statement_list :
               | statement_list statement
                ;


// folosim CheckId pentru a verifica daca variabilele au fost declarate inainte de utilizare
statement : ID_BC ASSIGN_GIFT e ';' { SymTableHelp::CheckId(*$1); }
          | ID_BC ACCES ID_BC ASSIGN_GIFT e ';' { SymTableHelp::CheckId(*$1); }
          | IF_BC '(' e_bool ')' '{' statement_list '}'
          | IF_BC '(' e_bool ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'
          | WHILE_BC '(' e_bool ')' '{' statement_list '}'
          | PRINT_BC '(' e ')' ';'
          | RETURN_BC e ';'
          |RETURN_BC e_bool ';'
          ;

e_bool: e EQ_GIFTS e 
  | e NEQ_GIFTS e 
  | e LE_GIFTS e 
  | e GE_GIFTS e 
  | e LT e 
  | e GT e
  | '(' e_bool ')'
  | e_bool  EQ_GIFTS e_bool
  | e_bool NEQ_GIFTS e_bool
  | e_bool ATELIER_AND_COR e_bool
  | e_bool DECORATIUNI_OR_COLINDE e_bool 
  | BOOL_VAL_BC
  | NOT_BC e_bool
  ;


e : e '+' e
  | e '-' e 
  | e '*' e  
  | e '/' e  
  | '(' e ')'
  | NR 
  | FLOAT_NR 
  | STRING_VAL 
  | ID_BC { SymTableHelp::CheckId(*$1); }  
  | ID_BC ACCES ID_BC
  | call_fn
  ;

//(momentan verificam doar daca numele functiei exista)
//verificarea parametrilor la apel tre sa o facem la analiza semantica
call_fn: ID_BC '(' wishlist ')' { SymTableHelp::CheckId(*$1); }
       | ID_BC '(' ')' { SymTableHelp::CheckId(*$1); }
       | ID_BC ACCES ID_BC '(' wishlist ')'
       | ID_BC ACCES ID_BC '(' ')'
       ;

wishlist : e 
         |  wishlist ',' e 
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

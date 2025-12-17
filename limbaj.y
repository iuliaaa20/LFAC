%{
#include <iostream>
#include <string>
#include "SymTableHelp.h"  

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char * s); 

%}
%union {
    std::string* Str;
};

%token BGIN END CLASS_BC  NEW_BC FN_BC ACCES
%token IF_BC ELSE_BC WHILE_BC RETURN_BC PRINT_BC
%token ASSIGN_GIFT ATELIER_AND_COR DECORATIUNI_OR_COLINDE EQ_GIFTS NEQ_GIFTS LE_GIFTS GE_GIFTS LT GT
%token <Str> INT_BC FLOAT_BC STRING_BC BOOL_BC 
%token <Str> ID_BC STRING_VAL BOOL_VAL_BC NR FLOAT_NR 


%left DECORATIUNI_OR_COLINDE  
%left ATELIER_AND_COR         
%left EQ_GIFTS NEQ_GIFTS      
%left LT GT LE_GIFTS GE_GIFTS 
%left '+' '-' 
%left '*' '/'
%left ACCES

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
     ;


type : INT_BC    { SymTableHelp::SetType("int_gift"); }
     | FLOAT_BC  { SymTableHelp::SetType("float_snow"); }
     | STRING_BC { SymTableHelp::SetType("str_letter"); }
     | BOOL_BC   { SymTableHelp::SetType("bool"); }
     ;

return_type : type ; 

decl : type list_variabile ';' ;

list_variabile : ID_BC { SymTableHelp::AddVar(*$1, "variabila"); }
               | list_variabile ',' ID_BC { SymTableHelp::AddVar(*$3, "variabila"); }
               ;

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

header_fn: FN_BC return_type ID_BC {
             SymTableHelp::AddVar(*$3, "functie");    
             SymTableHelp::EnterScope("Func_" + *$3);   
         }
         ;

fn_decl : header_fn '^' list_param '^' '[' fn_body ']' { SymTableHelp::ExitScope(); }
        | header_fn '^' '^' '[' fn_body ']' { SymTableHelp::ExitScope(); }
        ;

list_param : param 
           | list_param ',' param ;

param : type ID_BC { SymTableHelp::AddVar(*$2, "parametru"); } ;

fn_body : declarations statement_list 
        ;
declarations : declarations decl 
            |
            ;


main_bc : BGIN { SymTableHelp::EnterScope("Main"); } statement_list END { SymTableHelp::ExitScope(); } ;

statement_list :
               | statement_list statement
                ;



statement : ID_BC ASSIGN_GIFT e ';' { SymTableHelp::CheckId(*$1); }
          | ID_BC ACCES ID_BC ASSIGN_GIFT e ';' { SymTableHelp::CheckId(*$1); }
          | IF_BC '(' e ')' '{' statement_list '}'
          | IF_BC '(' e ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'
          | WHILE_BC '(' e ')' '{' statement_list '}'
          | PRINT_BC '(' e ')' ';'
          | RETURN_BC e ';'
          | call_fn ';'
          ;

e : e '+' e
  | e '-' e 
  | e '*' e  
  | e '/' e  
  | '(' e ')'
  | NR 
  | FLOAT_NR 
  | STRING_VAL 
  | BOOL_VAL_BC
  | ID_BC { SymTableHelp::CheckId(*$1); }  
  | e EQ_GIFTS e 
  | e NEQ_GIFTS e 
  | e LE_GIFTS e 
  | e GE_GIFTS e 
  | e LT e 
  | e GT e
  | e ATELIER_AND_COR e 
  | e DECORATIUNI_OR_COLINDE e
  | ID_BC ACCES ID_BC
  | NEW_BC ID_BC 
  | call_fn
  ;

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

%{
#include <iostream>
#include <string>
using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char * s);

%}

/* DEFINITII BISON */
%union {
    std::string* Str;
}



/* cuv cheie*/
%token BGIN END 
%token CLASS_BC PUBLIC_BC SECRET_SANTA 
%token IF_BC ELSE_BC WHILE_BC RETURN_BC PRINT_BC

/*tipuri de date:*/
%token <Str> INT_BC FLOAT_BC STRING_BC BOOL_BC VOID_BC

/* valori si identificatori */
%token <Str> ID_BC STRING_VAL BOOL_VAL_BC NR FLOAT_NR

%token ASSIGN_GIFT 
%token EQ_GIFTS NEQ_GIFTS LE_GIFTS GE_GIFTS LT GT
%token ATELIER_AND_COR DECORATIUNI_OR_COLINDE

%start progr

/* precedenta operatorilor */
%left DECORATIUNI_OR_COLINDE  
%left ATELIER_AND_COR         
%left EQ_GIFTS NEQ_GIFTS      
%left LT GT LE_GIFTS GE_GIFTS 
%left '+' '-' 
%left '*' '/'

%%

progr : orice main { 
            std::cout << "Sintaxa este corecta. (Mos Craciun a ajuns)" << std::endl;
        }
      ;


orice : orice elem
      | 
        ;

elem  : decl
      | class_decl
      | fn_decl
      ;

type : INT_BC | FLOAT_BC | STRING_BC | BOOL_BC ;




/* o singura declaratie:  */
decl : type ID_BC ';' 
     ;

classes :classes class_decl
        | 
        ;


class_decl : CLASS_BC ID_BC '{' class_body '}' 
           ;

class_body : class_body restr decl      
           | class_body restr fn_decl 
           | 
           ;

restr      : PUBLIC_BC 
           | SECRET_SANTA 
           |
           ;

functions : functions fn_decl
          | 
          ;


return_type : type | VOID_BC ;

/* Antet + Corp */
fn_decl : return_type ID_BC '(' list_param ')' '{' fn_body '}'
          ;

list_param : param
           | list_param ',' param
           | 
           ;

param : type ID_BC 
      ;

/*  Variabilele locale doar la inceput, apoi instructiuni. */
fn_body : declarations statement_list 
        ;

/* begin_xmas ... end_xmas */

main : BGIN statement_list END 
           ;

statement_list : 
               | statement_list statement
               ;

statement : /*de completat*/
        
e: /*de completat*/



call_fn: /*de completat*/

%%

void yyerror(const char * s){
    std::cout << "Eroare Sintactica: " << s << " la linia " << yylineno << std::endl;
}

int main(int argc, char** argv){
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(!yyin) {
            std::cerr << "Nu pot deschide fisierul: " << argv[1] << std::endl;
            return 1;
        }
    }
    
    
    return 0;
}

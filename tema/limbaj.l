%{
#include <stdio.h>
#include <string>
#include "limbaj.tab.h"
%}
%option noyywrap

%%

"//".* ;  
"begin_xmas"   { return BGIN; }
"end_xmas"     { return END; }
"class"        { return CLASS_BC; }
"if"           { return IF_BC; }
"else"         { return ELSE_BC; }      
"while"        { return WHILE_BC; }
"return"       { return RETURN_BC; }
"Print"        { return PRINT_BC; }
"elf"          { return FN_BC; }
"create_gift"  { return NEW_BC; }
"and"          { return ATELIER_AND_COR; }
"or"           { return DECORATIUNI_OR_COLINDE; }
"int_gift"     { yylval.Str = new std::string(yytext); return INT_BC; }
"float_snow"   { yylval.Str = new std::string(yytext); return FLOAT_BC; }
"str_letter"   { yylval.Str = new std::string(yytext); return STRING_BC; }
"bool"         { yylval.Str = new std::string(yytext); return BOOL_BC; }
"nice"|"naughty" { 
    yylval.Str = new std::string(yytext); 
    return BOOL_VAL_BC; 
}
"not"   {return NOT_BC;}
[a-zA-Z][a-zA-Z0-9_]* { 
    yylval.Str = new std::string(yytext); 
    return ID_BC; 
}

"="     { return ASSIGN_GIFT; }
"=="    { return EQ_GIFTS; }
"!="    { return NEQ_GIFTS; }
"<="    { return LE_GIFTS; }
">="    { return GE_GIFTS; }
"<"     { return LT_GIFTS;  }
">"     { return GT_GIFTS;  }
"->"    { return ACCES; }


[0-9]+\.[0-9]+  { yylval.Str = new std::string(yytext); return FLOAT_NR; }
[0-9]+          { yylval.Str = new std::string(yytext); return NR; }
\"[^"]*\"      { yylval.Str = new std::string(yytext); return STRING_VAL; }
[ \t] ;
\n { yylineno++; }
. { return yytext[0]; }

%%
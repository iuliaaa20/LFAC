/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "limbaj.y"

    #include <vector>
    

#line 54 "limbaj.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BGIN = 258,                    /* BGIN  */
    END = 259,                     /* END  */
    CLASS_BC = 260,                /* CLASS_BC  */
    NEW_BC = 261,                  /* NEW_BC  */
    FN_BC = 262,                   /* FN_BC  */
    ACCES = 263,                   /* ACCES  */
    VOID_BC = 264,                 /* VOID_BC  */
    OWN_BC = 265,                  /* OWN_BC  */
    IF_BC = 266,                   /* IF_BC  */
    ELSE_BC = 267,                 /* ELSE_BC  */
    WHILE_BC = 268,                /* WHILE_BC  */
    RETURN_BC = 269,               /* RETURN_BC  */
    PRINT_BC = 270,                /* PRINT_BC  */
    ASSIGN_GIFT = 271,             /* ASSIGN_GIFT  */
    ATELIER_AND_COR = 272,         /* ATELIER_AND_COR  */
    DECORATIUNI_OR_COLINDE = 273,  /* DECORATIUNI_OR_COLINDE  */
    EQ_GIFTS = 274,                /* EQ_GIFTS  */
    NEQ_GIFTS = 275,               /* NEQ_GIFTS  */
    LE_GIFTS = 276,                /* LE_GIFTS  */
    GE_GIFTS = 277,                /* GE_GIFTS  */
    LT_GIFTS = 278,                /* LT_GIFTS  */
    GT_GIFTS = 279,                /* GT_GIFTS  */
    NOT_BC = 280,                  /* NOT_BC  */
    INT_BC = 281,                  /* INT_BC  */
    FLOAT_BC = 282,                /* FLOAT_BC  */
    STRING_BC = 283,               /* STRING_BC  */
    BOOL_BC = 284,                 /* BOOL_BC  */
    ID_BC = 285,                   /* ID_BC  */
    STRING_VAL = 286,              /* STRING_VAL  */
    BOOL_VAL_BC = 287,             /* BOOL_VAL_BC  */
    NR = 288,                      /* NR  */
    FLOAT_NR = 289                 /* FLOAT_NR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "limbaj.y"

    std::string* Str;
    class ASTNode* Node;           
    std::vector<class ASTNode*>* List;

#line 111 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */

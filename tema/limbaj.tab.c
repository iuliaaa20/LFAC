/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

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


#line 89 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_CLASS_BC = 5,                   /* CLASS_BC  */
  YYSYMBOL_NEW_BC = 6,                     /* NEW_BC  */
  YYSYMBOL_FN_BC = 7,                      /* FN_BC  */
  YYSYMBOL_ACCES = 8,                      /* ACCES  */
  YYSYMBOL_VOID_BC = 9,                    /* VOID_BC  */
  YYSYMBOL_OWN_BC = 10,                    /* OWN_BC  */
  YYSYMBOL_IF_BC = 11,                     /* IF_BC  */
  YYSYMBOL_ELSE_BC = 12,                   /* ELSE_BC  */
  YYSYMBOL_WHILE_BC = 13,                  /* WHILE_BC  */
  YYSYMBOL_RETURN_BC = 14,                 /* RETURN_BC  */
  YYSYMBOL_PRINT_BC = 15,                  /* PRINT_BC  */
  YYSYMBOL_ASSIGN_GIFT = 16,               /* ASSIGN_GIFT  */
  YYSYMBOL_ATELIER_AND_COR = 17,           /* ATELIER_AND_COR  */
  YYSYMBOL_DECORATIUNI_OR_COLINDE = 18,    /* DECORATIUNI_OR_COLINDE  */
  YYSYMBOL_EQ_GIFTS = 19,                  /* EQ_GIFTS  */
  YYSYMBOL_NEQ_GIFTS = 20,                 /* NEQ_GIFTS  */
  YYSYMBOL_LE_GIFTS = 21,                  /* LE_GIFTS  */
  YYSYMBOL_GE_GIFTS = 22,                  /* GE_GIFTS  */
  YYSYMBOL_LT_GIFTS = 23,                  /* LT_GIFTS  */
  YYSYMBOL_GT_GIFTS = 24,                  /* GT_GIFTS  */
  YYSYMBOL_NOT_BC = 25,                    /* NOT_BC  */
  YYSYMBOL_INT_BC = 26,                    /* INT_BC  */
  YYSYMBOL_FLOAT_BC = 27,                  /* FLOAT_BC  */
  YYSYMBOL_STRING_BC = 28,                 /* STRING_BC  */
  YYSYMBOL_BOOL_BC = 29,                   /* BOOL_BC  */
  YYSYMBOL_ID_BC = 30,                     /* ID_BC  */
  YYSYMBOL_STRING_VAL = 31,                /* STRING_VAL  */
  YYSYMBOL_BOOL_VAL_BC = 32,               /* BOOL_VAL_BC  */
  YYSYMBOL_NR = 33,                        /* NR  */
  YYSYMBOL_FLOAT_NR = 34,                  /* FLOAT_NR  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* '^'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_progr = 49,                     /* progr  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_orice = 51,                     /* orice  */
  YYSYMBOL_elem = 52,                      /* elem  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_return_type = 54,               /* return_type  */
  YYSYMBOL_decl = 55,                      /* decl  */
  YYSYMBOL_list_variabile = 56,            /* list_variabile  */
  YYSYMBOL_class_decl = 57,                /* class_decl  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_class_body = 59,                /* class_body  */
  YYSYMBOL_header_constr = 60,             /* header_constr  */
  YYSYMBOL_constr_decl = 61,               /* constr_decl  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_header_fn = 64,                 /* header_fn  */
  YYSYMBOL_fn_decl = 65,                   /* fn_decl  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_list_param = 68,                /* list_param  */
  YYSYMBOL_param = 69,                     /* param  */
  YYSYMBOL_fn_body_list = 70,              /* fn_body_list  */
  YYSYMBOL_statement_list = 71,            /* statement_list  */
  YYSYMBOL_main_bc = 72,                   /* main_bc  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_e_bool = 75,                    /* e_bool  */
  YYSYMBOL_e = 76,                         /* e  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_call_fn = 79,                   /* call_fn  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_wishlist = 82                   /* wishlist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,    37,    35,    40,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    56,    62,    63,    66,    67,    68,    71,
      72,    73,    74,    75,    85,    89,    91,    93,    94,    98,
      98,   110,   111,   112,   113,   116,   125,   125,   126,   126,
     129,   137,   137,   138,   138,   141,   142,   144,   146,   147,
     151,   157,   158,   165,   165,   176,   193,   207,   222,   235,
     251,   268,   269,   270,   277,   284,   285,   292,   295,   299,
     311,   332,   348,   358,   372,   385,   405,   425,   445,   465,
     467,   478,   489,   498,   508,   518,   528,   531,   543,   552,
     561,   564,   574,   583,   592,   600,   604,   615,   637,   657,
     677,   697,   699,   706,   713,   718,   730,   740,   755,   756,
     756,   773,   773,   789,   789,   808,   826,   826,   841,   860,
     861,   862,   863
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "CLASS_BC", "NEW_BC", "FN_BC", "ACCES", "VOID_BC", "OWN_BC", "IF_BC",
  "ELSE_BC", "WHILE_BC", "RETURN_BC", "PRINT_BC", "ASSIGN_GIFT",
  "ATELIER_AND_COR", "DECORATIUNI_OR_COLINDE", "EQ_GIFTS", "NEQ_GIFTS",
  "LE_GIFTS", "GE_GIFTS", "LT_GIFTS", "GT_GIFTS", "NOT_BC", "INT_BC",
  "FLOAT_BC", "STRING_BC", "BOOL_BC", "ID_BC", "STRING_VAL", "BOOL_VAL_BC",
  "NR", "FLOAT_NR", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'['", "']'",
  "'^'", "'('", "')'", "'{'", "'}'", "$accept", "progr", "$@1", "orice",
  "elem", "type", "return_type", "decl", "list_variabile", "class_decl",
  "$@2", "class_body", "header_constr", "constr_decl", "$@3", "$@4",
  "header_fn", "fn_decl", "$@5", "$@6", "list_param", "param",
  "fn_body_list", "statement_list", "main_bc", "$@7", "statement",
  "e_bool", "e", "$@8", "$@9", "call_fn", "$@10", "$@11", "wishlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,    19,  -164,  -164,   434,  -164,   -26,   534,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,     0,  -164,  -164,    11,  -164,
    -164,  -164,  -164,  -164,    17,  -164,    -2,   234,    80,    34,
    -164,  -164,    46,  -164,    57,    61,  -164,  -164,    89,    44,
      55,   106,    67,     4,  -164,    66,  -164,  -164,    65,  -164,
     534,  -164,    83,   141,   141,    95,   122,   141,     5,  -164,
    -164,  -164,  -164,  -164,   141,   145,   448,  -164,   141,   111,
     141,    97,  -164,   210,  -164,  -164,   107,   136,    22,   325,
      62,   354,   109,   126,  -164,   550,   127,   115,   383,   141,
     141,   141,   141,  -164,   141,   141,   141,   141,   149,   149,
     149,   149,   149,   149,   149,   149,  -164,   236,   412,    -8,
     313,   456,  -164,   141,   540,  -164,  -164,   133,  -164,  -164,
     265,  -164,   141,   112,   131,   132,   135,   147,  -164,   150,
    -164,  -164,    26,   389,    98,   518,  -164,   550,  -164,   550,
      26,   389,    98,   518,  -164,   550,  -164,   550,   149,   151,
     151,   151,   151,    33,    33,  -164,  -164,   161,   167,   141,
     171,  -164,  -164,   336,   510,   -18,   169,   240,     4,  -164,
    -164,  -164,   275,   347,   479,  -164,  -164,  -164,  -164,   176,
     141,   261,  -164,  -164,   376,   487,  -164,   141,   141,  -164,
    -164,   103,  -164,  -164,  -164,    -4,   188,   194,   200,  -164,
     -17,  -164,  -164,    29,   336,   510,   193,  -164,   232,   233,
    -164,  -164,  -164,  -164,  -164,   205,   204,   211,   299,  -164,
    -164,  -164,  -164,   309,   212,   218,  -164,  -164,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     0,    43,     0,     0,    14,     9,
      10,    11,    12,    13,     4,     0,     6,     7,     0,     8,
       3,    41,    19,    15,     0,    17,     0,     0,     0,     0,
      30,    16,     0,    33,     0,     0,    35,    44,     0,     0,
       0,     0,     0,     0,    42,     0,    24,    18,     0,    37,
       0,    31,     0,     0,     0,     0,     0,     0,    95,    94,
      84,    92,    93,    62,     0,     0,     0,    98,     0,     0,
       0,   103,    59,     0,    38,    36,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,   105,     0,     0,    20,    21,     0,    23,    22,
       0,    38,     0,     0,     0,     0,     0,   101,    97,    96,
      69,    91,    76,    78,    80,    82,    70,    72,    71,    73,
      79,    77,    83,    81,    74,    63,    75,    64,     0,    65,
      66,    67,    68,    87,    88,    89,    90,     0,     0,     0,
     106,    47,    45,   111,   109,     0,    13,     0,    13,    34,
      40,    39,     0,     0,     0,    41,    41,    41,    41,     0,
       0,     0,    58,    57,     0,     0,   108,     0,     0,   104,
      28,     0,    32,    50,    49,     0,     0,     0,     0,   100,
       0,    48,    46,     0,   112,   110,     0,    26,    51,    53,
      55,    56,   102,   107,    38,     0,     0,     0,     0,    38,
      41,    41,    29,     0,     0,     0,    27,    52,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,    -6,  -164,    -1,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,   178,  -164,  -164,
      91,   221,  -116,  -143,  -164,  -164,  -104,    32,   -39,  -164,
    -164,   -28,  -164,  -164,  -163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,    14,    15,    24,   170,    26,    17,
      29,    73,   117,   118,   215,   206,    18,    19,    76,    48,
      35,    36,   120,    28,    20,    21,    44,   163,   164,   179,
     180,    67,   113,   187,   165
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    23,    66,    16,    22,   172,    38,    39,   159,    40,
      41,    42,    69,    86,    79,    81,   171,   200,    85,     3,
      70,    34,   188,   188,   203,    88,    43,   189,   212,   108,
      25,   111,   195,   196,   197,   198,   160,    31,    32,    89,
      90,    91,    92,   208,    34,    91,    92,    30,    71,    71,
     133,   135,   137,   139,    27,   141,   143,   145,   147,   149,
     150,   151,   152,   153,   154,   155,   156,   123,   171,   188,
     104,   105,   116,    65,   213,    46,    47,   224,   225,    89,
      90,    91,    92,   174,    37,    78,    80,    49,    53,    84,
      38,    39,    45,    40,    41,    42,    87,    52,   218,    54,
     107,    50,   110,   223,    51,    72,    74,   125,    23,   181,
      43,    68,    55,    77,   171,    89,    56,    91,    92,   171,
     185,   132,   134,   136,   138,    82,   140,   142,   144,   146,
      83,    57,    89,    90,    91,    92,    58,    59,    60,    61,
      62,   109,   112,    50,    45,    63,   207,    55,   121,   205,
      64,    56,   122,   127,   173,    55,   128,   129,   175,    56,
     130,    34,    89,    90,    91,    92,    57,    45,    45,    45,
      45,    58,    59,    60,    61,    62,   167,   176,   177,    58,
      59,   178,    61,    62,    93,    64,   102,   103,   104,   105,
      45,   184,   -99,   148,   160,    45,    45,    45,    38,    39,
     182,    40,    41,    42,    38,    39,   183,    40,    41,    42,
      38,    39,   -25,    40,    41,    42,   186,   114,    43,     8,
     204,   199,    38,    39,    43,    40,    41,    42,    38,    39,
      43,    40,    41,    42,   214,   209,     9,    10,    11,    12,
      13,   210,    43,     8,   216,   217,   219,   211,    43,     8,
     220,   119,   115,    89,    90,    91,    92,   221,   191,   227,
       9,    10,    11,    12,    13,   228,     9,    10,    11,    12,
      13,    75,     0,     0,     8,    38,    39,    33,    40,    41,
      42,   157,     0,   190,     8,    38,    39,     0,    40,    41,
      42,     9,    10,    11,    12,   168,   102,   103,   104,   105,
       0,     9,    10,    11,    12,   168,   131,   169,     8,    38,
      39,     0,    40,    41,    42,     0,     0,   192,     8,    38,
      39,     0,    40,    41,    42,     9,    10,    11,    12,   168,
      89,    90,    91,    92,     0,     9,    10,    11,    12,   168,
       0,   222,    94,    95,    96,    97,    98,    99,   100,   101,
       0,   226,   161,    89,    90,    91,    92,     0,     0,     0,
     102,   103,   104,   105,    89,    90,    91,    92,     0,     0,
     124,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,   193,     0,     0,   102,
     103,   104,   105,    89,    90,    91,    92,     0,     0,   126,
      94,    95,    96,    97,    98,    99,   100,   101,    96,    97,
      98,    99,   100,   101,     0,   201,     0,     0,   102,   103,
     104,   105,     0,     0,   102,   103,   104,   105,   131,    94,
      95,    96,    97,    98,    99,   100,   101,     5,     0,     6,
       0,     7,     0,     8,     0,     0,     0,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       9,    10,    11,    12,    13,    94,    95,    96,    97,    98,
      99,   100,   101,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,     0,     0,
       0,   102,   103,   104,   105,   162,    94,    95,    96,    97,
      98,    99,   100,   101,    94,    95,    96,    97,    98,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   194,     0,
       0,     0,   102,   103,   104,   105,   202,    94,    95,    96,
      97,    98,    99,   100,   101,    94,     0,    96,    97,    98,
      99,   100,   101,     8,     0,   102,   103,   104,   105,     8,
       0,     0,     0,   102,   103,   104,   105,     0,     0,     0,
       9,    10,    11,    12,    13,     0,     9,    10,    11,    12,
     166,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      28,     7,    41,     4,    30,   121,    10,    11,    16,    13,
      14,    15,     8,     8,    53,    54,   120,   180,    57,     0,
      16,    27,    40,    40,   187,    64,    30,    45,    45,    68,
      30,    70,   175,   176,   177,   178,    44,    39,    40,    17,
      18,    19,    20,    47,    50,    19,    20,    30,    44,    44,
      89,    90,    91,    92,    43,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    45,   172,    40,
      37,    38,    73,    41,    45,    41,    30,   220,   221,    17,
      18,    19,    20,   122,     4,    53,    54,    30,    44,    57,
      10,    11,   120,    13,    14,    15,    64,     8,   214,    44,
      68,    40,    70,   219,    43,    39,    41,    45,   114,   148,
      30,    44,     6,    30,   218,    17,    10,    19,    20,   223,
     159,    89,    90,    91,    92,    30,    94,    95,    96,    97,
       8,    25,    17,    18,    19,    20,    30,    31,    32,    33,
      34,    30,    45,    40,   172,    39,    43,     6,    41,   188,
      44,    10,    16,    44,   122,     6,    30,    30,    46,    10,
      45,   167,    17,    18,    19,    20,    25,   195,   196,   197,
     198,    30,    31,    32,    33,    34,    43,    46,    46,    30,
      31,    46,    33,    34,    39,    44,    35,    36,    37,    38,
     218,   159,    45,    44,    44,   223,   224,   225,    10,    11,
      39,    13,    14,    15,    10,    11,    39,    13,    14,    15,
      10,    11,    43,    13,    14,    15,    45,     7,    30,     9,
     188,    45,    10,    11,    30,    13,    14,    15,    10,    11,
      30,    13,    14,    15,    41,    47,    26,    27,    28,    29,
      30,    47,    30,     9,    12,    12,    41,    47,    30,     9,
      46,    73,    42,    17,    18,    19,    20,    46,   167,    47,
      26,    27,    28,    29,    30,    47,    26,    27,    28,    29,
      30,    50,    -1,    -1,     9,    10,    11,    43,    13,    14,
      15,    45,    -1,    43,     9,    10,    11,    -1,    13,    14,
      15,    26,    27,    28,    29,    30,    35,    36,    37,    38,
      -1,    26,    27,    28,    29,    30,    45,    42,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    42,     9,    10,
      11,    -1,    13,    14,    15,    26,    27,    28,    29,    30,
      17,    18,    19,    20,    -1,    26,    27,    28,    29,    30,
      -1,    42,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    42,    39,    17,    18,    19,    20,    -1,    -1,    -1,
      35,    36,    37,    38,    17,    18,    19,    20,    -1,    -1,
      45,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    35,
      36,    37,    38,    17,    18,    19,    20,    -1,    -1,    45,
      17,    18,    19,    20,    21,    22,    23,    24,    19,    20,
      21,    22,    23,    24,    -1,    39,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    35,    36,    37,    38,    45,    17,
      18,    19,    20,    21,    22,    23,    24,     3,    -1,     5,
      -1,     7,    -1,     9,    -1,    -1,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      26,    27,    28,    29,    30,    17,    18,    19,    20,    21,
      22,    23,    24,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    17,    18,    19,
      20,    21,    22,    23,    24,    17,    -1,    19,    20,    21,
      22,    23,    24,     9,    -1,    35,    36,    37,    38,     9,
      -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    26,    27,    28,    29,
      30,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,    51,     3,     5,     7,     9,    26,
      27,    28,    29,    30,    52,    53,    55,    57,    64,    65,
      72,    73,    30,    53,    54,    30,    56,    43,    71,    58,
      30,    39,    40,    43,    53,    68,    69,     4,    10,    11,
      13,    14,    15,    30,    74,    79,    41,    30,    67,    30,
      40,    43,     8,    44,    44,     6,    10,    25,    30,    31,
      32,    33,    34,    39,    44,    75,    76,    79,    44,     8,
      16,    44,    39,    59,    41,    69,    66,    30,    75,    76,
      75,    76,    30,     8,    75,    76,     8,    75,    76,    17,
      18,    19,    20,    39,    17,    18,    19,    20,    21,    22,
      23,    24,    35,    36,    37,    38,    39,    75,    76,    30,
      75,    76,    45,    80,     7,    42,    55,    60,    61,    65,
      70,    41,    16,    45,    45,    45,    45,    44,    30,    30,
      45,    45,    75,    76,    75,    76,    75,    76,    75,    76,
      75,    76,    75,    76,    75,    76,    75,    76,    44,    76,
      76,    76,    76,    76,    76,    76,    76,    45,    45,    16,
      44,    39,    39,    75,    76,    82,    30,    43,    30,    42,
      55,    74,    70,    75,    76,    46,    46,    46,    46,    77,
      78,    76,    39,    39,    75,    76,    45,    81,    40,    45,
      43,    68,    42,    39,    39,    71,    71,    71,    71,    45,
      82,    39,    39,    82,    75,    76,    63,    43,    47,    47,
      47,    47,    45,    45,    41,    62,    12,    12,    70,    41,
      46,    46,    42,    70,    71,    71,    42,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    54,    55,    56,    56,    58,
      57,    59,    59,    59,    59,    60,    62,    61,    63,    61,
      64,    66,    65,    67,    65,    68,    68,    69,    70,    70,
      70,    71,    71,    73,    72,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      76,    78,    76,    80,    79,    79,    81,    79,    79,    82,
      82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     0,
       6,     2,     2,     2,     0,     2,     0,     8,     0,     7,
       3,     0,     8,     0,     7,     1,     3,     2,     0,     2,
       2,     0,     2,     0,     4,     4,     6,     4,     6,     6,
       6,     7,    11,     7,    11,     7,     7,     5,     5,     2,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     1,     0,
       5,     0,     6,     0,     5,     3,     0,     7,     5,     1,
       3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 56 "limbaj.y"
        { SymTableHelp::Init(); }
#line 1379 "limbaj.tab.c"
    break;

  case 3: /* progr: $@1 orice main_bc  */
#line 56 "limbaj.y"
                                                { 
            cout << "Sintaxa corecta. Mos Craciun a ajuns" << endl;
            SymTableHelp::Clean(); 
        }
#line 1388 "limbaj.tab.c"
    break;

  case 9: /* type: INT_BC  */
#line 71 "limbaj.y"
                 { SymTableHelp::SetType("int_gift");   (yyval.Str) = new std::string("int_gift"); }
#line 1394 "limbaj.tab.c"
    break;

  case 10: /* type: FLOAT_BC  */
#line 72 "limbaj.y"
                 { SymTableHelp::SetType("float_snow"); (yyval.Str) = new std::string("float_snow"); }
#line 1400 "limbaj.tab.c"
    break;

  case 11: /* type: STRING_BC  */
#line 73 "limbaj.y"
                 { SymTableHelp::SetType("str_letter"); (yyval.Str) = new std::string("str_letter"); }
#line 1406 "limbaj.tab.c"
    break;

  case 12: /* type: BOOL_BC  */
#line 74 "limbaj.y"
                 { SymTableHelp::SetType("bool");       (yyval.Str) = new std::string("bool"); }
#line 1412 "limbaj.tab.c"
    break;

  case 13: /* type: ID_BC  */
#line 75 "limbaj.y"
             {    
          if (!SymTableHelp::CheckClassExists(*(yyvsp[0].Str))) {
              std::cout << "Eroare la linia " << yylineno << ": Tipul '" << *(yyvsp[0].Str) << "' nu este definit (nu este o clasa)." << std::endl;
              SymTableHelp::SetType("eroare");
              (yyval.Str) = new std::string("eroare");
          } else {
              SymTableHelp::SetType(*(yyvsp[0].Str)); 
              (yyval.Str) = new std::string(*(yyvsp[0].Str));
          }
      }
#line 1427 "limbaj.tab.c"
    break;

  case 14: /* type: VOID_BC  */
#line 85 "limbaj.y"
                  {SymTableHelp::SetType("lenes");  (yyval.Str)=new std::string("lenes");}
#line 1433 "limbaj.tab.c"
    break;

  case 16: /* decl: type list_variabile ';'  */
#line 91 "limbaj.y"
                               {delete (yyvsp[-2].Str);}
#line 1439 "limbaj.tab.c"
    break;

  case 17: /* list_variabile: ID_BC  */
#line 93 "limbaj.y"
                       { SymTableHelp::AddVar(*(yyvsp[0].Str), "variabila"); delete (yyvsp[0].Str); }
#line 1445 "limbaj.tab.c"
    break;

  case 18: /* list_variabile: list_variabile ',' ID_BC  */
#line 94 "limbaj.y"
                                          { SymTableHelp::AddVar(*(yyvsp[0].Str), "variabila"); delete (yyvsp[0].Str); }
#line 1451 "limbaj.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 98 "limbaj.y"
                            { 
                SymTableHelp::SetType("definitie_clasa");        
                SymTableHelp::AddVar(*(yyvsp[0].Str), "clasa");        
                SymTableHelp::EnterScope("Class_" + *(yyvsp[0].Str));  
                
                SymTableHelp::AddClassScope(*(yyvsp[0].Str), SymTableHelp::currentScope);
             }
#line 1463 "limbaj.tab.c"
    break;

  case 20: /* class_decl: CLASS_BC ID_BC $@2 '[' class_body ']'  */
#line 105 "limbaj.y"
                                { 
                SymTableHelp::ExitScope();                
             }
#line 1471 "limbaj.tab.c"
    break;

  case 25: /* header_constr: FN_BC ID_BC  */
#line 116 "limbaj.y"
                          {
      SymTableHelp::CheckConstructorName(*(yyvsp[0].Str));
      SymTableHelp::currentFuncName = *(yyvsp[0].Str);
      SymTableHelp::SetType("constructor"); 
      SymTableHelp::AddVar(*(yyvsp[0].Str), "functie"); 
      SymTableHelp::EnterScope("Func_" + *(yyvsp[0].Str));
      }
#line 1483 "limbaj.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 125 "limbaj.y"
                                               {SymTableHelp::SaveParams();}
#line 1489 "limbaj.tab.c"
    break;

  case 27: /* constr_decl: header_constr '^' list_param '^' $@3 '[' fn_body_list ']'  */
#line 125 "limbaj.y"
                                                                                                  {SymTableHelp::ExitScope();}
#line 1495 "limbaj.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 126 "limbaj.y"
                                    {SymTableHelp::SaveParams();}
#line 1501 "limbaj.tab.c"
    break;

  case 29: /* constr_decl: header_constr '^' '^' $@4 '[' fn_body_list ']'  */
#line 126 "limbaj.y"
                                                                                       {SymTableHelp::ExitScope();}
#line 1507 "limbaj.tab.c"
    break;

  case 30: /* header_fn: FN_BC return_type ID_BC  */
#line 129 "limbaj.y"
                                   {
           SymTableHelp::currentFuncName = *(yyvsp[0].Str); 
           SymTableHelp::SetType(*(yyvsp[-1].Str)); 
           SymTableHelp::AddVar(*(yyvsp[0].Str), "functie"); 
           SymTableHelp::EnterScope("Func_" + *(yyvsp[0].Str));
         }
#line 1518 "limbaj.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 137 "limbaj.y"
                                       { SymTableHelp::SaveParams(); }
#line 1524 "limbaj.tab.c"
    break;

  case 32: /* fn_decl: header_fn '^' list_param '^' $@5 '[' fn_body_list ']'  */
#line 137 "limbaj.y"
                                                                                           { SymTableHelp::ExitScope(); }
#line 1530 "limbaj.tab.c"
    break;

  case 33: /* $@6: %empty  */
#line 138 "limbaj.y"
                            { SymTableHelp::SaveParams(); }
#line 1536 "limbaj.tab.c"
    break;

  case 34: /* fn_decl: header_fn '^' '^' $@6 '[' fn_body_list ']'  */
#line 138 "limbaj.y"
                                                                                 { SymTableHelp::ExitScope(); }
#line 1542 "limbaj.tab.c"
    break;

  case 37: /* param: type ID_BC  */
#line 144 "limbaj.y"
                   { SymTableHelp::AddParam(*(yyvsp[0].Str)); delete (yyvsp[-1].Str); delete (yyvsp[0].Str);}
#line 1548 "limbaj.tab.c"
    break;

  case 38: /* fn_body_list: %empty  */
#line 146 "limbaj.y"
               { (yyval.List) = new std::vector<ASTNode*>(); }
#line 1554 "limbaj.tab.c"
    break;

  case 39: /* fn_body_list: fn_body_list statement  */
#line 147 "limbaj.y"
                                      { 
                 if ((yyvsp[0].Node) != NULL) (yyvsp[-1].List)->push_back((yyvsp[0].Node)); 
                 (yyval.List) = (yyvsp[-1].List); 
             }
#line 1563 "limbaj.tab.c"
    break;

  case 40: /* fn_body_list: fn_body_list decl  */
#line 151 "limbaj.y"
                                 { 
                 
                 (yyval.List) = (yyvsp[-1].List); 
             }
#line 1572 "limbaj.tab.c"
    break;

  case 41: /* statement_list: %empty  */
#line 157 "limbaj.y"
                 { (yyval.List) = new std::vector<ASTNode*>(); }
#line 1578 "limbaj.tab.c"
    break;

  case 42: /* statement_list: statement_list statement  */
#line 158 "limbaj.y"
                                          { 
                   if ((yyvsp[0].Node) != NULL) (yyvsp[-1].List)->push_back((yyvsp[0].Node)); 
                   (yyval.List) = (yyvsp[-1].List); 
               }
#line 1587 "limbaj.tab.c"
    break;

  case 43: /* $@7: %empty  */
#line 165 "limbaj.y"
               { SymTableHelp::EnterScope("Main"); }
#line 1593 "limbaj.tab.c"
    break;

  case 44: /* main_bc: BGIN $@7 statement_list END  */
#line 166 "limbaj.y"
               { 
      
            if ((yyvsp[-1].List) != NULL) {
                 for(ASTNode* n : *(yyvsp[-1].List)) 
                   if(n) n->eval(SymTableHelp::currentScope);
            }
            SymTableHelp::ExitScope(); 
        }
#line 1606 "limbaj.tab.c"
    break;

  case 45: /* statement: ID_BC ASSIGN_GIFT e ';'  */
#line 176 "limbaj.y"
                                    { 
          SymTableHelp::CheckId(*(yyvsp[-3].Str)); 
          string tipSt=SymTableHelp::GetType(*(yyvsp[-3].Str));
          
          string tipDr = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare"; 

          if(tipSt!=tipDr && tipDr!="eroare"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui valoarea de tip "<<tipDr<<" variabilei "<<*(yyvsp[-3].Str)<<" de tip "<<tipSt<<endl;
          }

          ASTNode* leftNode = new ASTNode(tipSt, *(yyvsp[-3].Str));
          
          // Constructor General: ASTNode(tip, ROOT=":=", left, right)
          (yyval.Node) = new ASTNode(tipSt, ":=", leftNode, (yyvsp[-1].Node));
          
          delete (yyvsp[-3].Str);
          }
#line 1628 "limbaj.tab.c"
    break;

  case 46: /* statement: ID_BC ACCES ID_BC ASSIGN_GIFT e ';'  */
#line 193 "limbaj.y"
                                                { 
            SymTableHelp::CheckId(*(yyvsp[-5].Str)); 
            if(SymTableHelp::CheckClassMember(*(yyvsp[-5].Str),*(yyvsp[-3].Str))){
              string tipMembru=SymTableHelp::GetClassMemberType(*(yyvsp[-5].Str),*(yyvsp[-3].Str));
              string tipE = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare";

              if(tipMembru!=tipE && tipE!="eroare"){
                cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui "<<tipE<<" campului "<<*(yyvsp[-3].Str)<<" ("<<tipMembru<<")"<<endl;
              }
            }
            // Aici ramane OTHER pentru ca nu implementam logica complexa de clase
            (yyval.Node) = new ASTNode("void", "OTHER"); 
            delete (yyvsp[-5].Str); delete (yyvsp[-3].Str);
            }
#line 1647 "limbaj.tab.c"
    break;

  case 47: /* statement: ID_BC ASSIGN_GIFT e_bool ';'  */
#line 207 "limbaj.y"
                                        { 
              SymTableHelp::CheckId(*(yyvsp[-3].Str)); 
              string tipSt=SymTableHelp::GetType(*(yyvsp[-3].Str));
              string tipDr = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare";

              if(tipSt!=tipDr && tipDr!="eroare"){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui valoarea de tip "<<tipDr<<" variabilei "<<*(yyvsp[-3].Str)<<" de tip "<<tipSt<<endl;
              }
              
              // Constructie nod := pentru bool
              ASTNode* leftNode = new ASTNode(tipSt, *(yyvsp[-3].Str));
              (yyval.Node) = new ASTNode(tipSt, ":=", leftNode, (yyvsp[-1].Node));
              
              delete (yyvsp[-3].Str);
          }
#line 1667 "limbaj.tab.c"
    break;

  case 48: /* statement: ID_BC ACCES ID_BC ASSIGN_GIFT e_bool ';'  */
#line 222 "limbaj.y"
                                                     { 
            SymTableHelp::CheckId(*(yyvsp[-5].Str)); 
            if(SymTableHelp::CheckClassMember(*(yyvsp[-5].Str),*(yyvsp[-3].Str))){
              string tipMembru=SymTableHelp::GetClassMemberType(*(yyvsp[-5].Str),*(yyvsp[-3].Str));
              string tipE = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare";

              if(tipMembru!=tipE && tipE!="eroare"){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se poate atribui "<<tipE<<" campului "<<*(yyvsp[-3].Str)<<" ("<<tipMembru<<")"<<endl;
              }
            }
           (yyval.Node) = new ASTNode("void", "OTHER"); 
           delete (yyvsp[-5].Str); delete (yyvsp[-3].Str);
            }
#line 1685 "limbaj.tab.c"
    break;

  case 49: /* statement: OWN_BC ACCES ID_BC ASSIGN_GIFT e ';'  */
#line 235 "limbaj.y"
                                                {
            if(SymTableHelp::CheckOwnMember(*(yyvsp[-3].Str))){
              string tipSt = SymTableHelp::GetClassMemberTypeFromCurrentScope(*(yyvsp[-3].Str));
              string tipDr = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare";

              if(tipSt != tipDr && tipDr != "eroare"){
             cout << "Eroare semantica la linia " << yylineno << ": Nu se poate atribui " << tipDr << " membrului " << *(yyvsp[-3].Str) << " (" << tipSt << ")" << endl;
              }

              ASTNode* leftNode = new ASTNode(tipSt, *(yyvsp[-3].Str));
              (yyval.Node) = new ASTNode(tipSt, ":=", leftNode, (yyvsp[-1].Node));
          }else{
            (yyval.Node)=new ASTNode("eroare","OTHER");
          }
          delete (yyvsp[-3].Str);
          }
#line 1706 "limbaj.tab.c"
    break;

  case 50: /* statement: OWN_BC ACCES ID_BC ASSIGN_GIFT e_bool ';'  */
#line 251 "limbaj.y"
                                                    {
            if(SymTableHelp::CheckOwnMember(*(yyvsp[-3].Str))){
              string tipSt = SymTableHelp::GetClassMemberTypeFromCurrentScope(*(yyvsp[-3].Str));
              string tipDr = ((yyvsp[-1].Node) != NULL) ? (yyvsp[-1].Node)->type : "eroare";

              if(tipSt != tipDr && tipDr != "eroare"){
             cout << "Eroare semantica la linia " << yylineno << ": Nu se poate atribui " << tipDr << " membrului " << *(yyvsp[-3].Str) << " (" << tipSt << ")" << endl;
              }

              ASTNode* leftNode = new ASTNode(tipSt, *(yyvsp[-3].Str));
              (yyval.Node) = new ASTNode(tipSt, ":=", leftNode, (yyvsp[-1].Node));
          }else{
            (yyval.Node)=new ASTNode("eroare","OTHER");
          }
          delete (yyvsp[-3].Str);
          }
#line 1727 "limbaj.tab.c"
    break;

  case 51: /* statement: IF_BC '(' e_bool ')' '{' statement_list '}'  */
#line 268 "limbaj.y"
                                                       {(yyval.Node)=NULL;}
#line 1733 "limbaj.tab.c"
    break;

  case 52: /* statement: IF_BC '(' e_bool ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'  */
#line 269 "limbaj.y"
                                                                                      {(yyval.Node)=NULL;}
#line 1739 "limbaj.tab.c"
    break;

  case 53: /* statement: IF_BC '(' e ')' '{' statement_list '}'  */
#line 270 "limbaj.y"
                                                  {
            if((yyvsp[-4].Node)!=NULL){
              if((yyvsp[-4].Node)->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'if' trebuie sa fie de tip bool, nu "<<(yyvsp[-4].Node)->type<<endl;
            }
            (yyval.Node)=NULL;
            }
#line 1751 "limbaj.tab.c"
    break;

  case 54: /* statement: IF_BC '(' e ')' '{' statement_list '}' ELSE_BC '{' statement_list '}'  */
#line 277 "limbaj.y"
                                                                                 {
             if((yyvsp[-8].Node)!=NULL){
              if((yyvsp[-8].Node)->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'if' trebuie sa fie de tip bool, nu "<<(yyvsp[-8].Node)->type<<endl;
            }
            (yyval.Node)=NULL;
            }
#line 1763 "limbaj.tab.c"
    break;

  case 55: /* statement: WHILE_BC '(' e_bool ')' '{' statement_list '}'  */
#line 284 "limbaj.y"
                                                          {(yyval.Node)=NULL;}
#line 1769 "limbaj.tab.c"
    break;

  case 56: /* statement: WHILE_BC '(' e ')' '{' statement_list '}'  */
#line 285 "limbaj.y"
                                                     {
            if((yyvsp[-4].Node)!=NULL){
              if((yyvsp[-4].Node)->type != "bool")
              std::cout<<"Eroare semantica la linia "<<yylineno<<": Conditia din 'while' trebuie sa fie de tip bool, nu "<<(yyvsp[-4].Node)->type<<endl;
            }            
            (yyval.Node)=NULL;}
#line 1780 "limbaj.tab.c"
    break;

  case 57: /* statement: PRINT_BC '(' e ')' ';'  */
#line 292 "limbaj.y"
                                  {
              (yyval.Node) = new ASTNode("void", "PRINT", (yyvsp[-2].Node), NULL);
          }
#line 1788 "limbaj.tab.c"
    break;

  case 58: /* statement: PRINT_BC '(' e_bool ')' ';'  */
#line 295 "limbaj.y"
                                       {
              (yyval.Node) = new ASTNode("void", "PRINT", (yyvsp[-2].Node), NULL);
          }
#line 1796 "limbaj.tab.c"
    break;

  case 59: /* statement: call_fn ';'  */
#line 299 "limbaj.y"
                       {
             string tip = (yyvsp[-1].Node)->type;
             bool eLenes = (tip == "lenes" );
             bool eTipBaza = (tip == "int_gift" || tip == "float_snow" || tip == "bool" || tip == "str_letter");
        
             if (!eLenes && eTipBaza) {
             cout << "Eroare semantica la linia " << yylineno << ": O functie apelata ca instructiune trebuie sa fie de tip 'lenes' (void). Functia returneaza " << tip << endl;
            
        }

        (yyval.Node) = (yyvsp[-1].Node); 
    }
#line 1813 "limbaj.tab.c"
    break;

  case 60: /* statement: RETURN_BC e ';'  */
#line 311 "limbaj.y"
                            { // la returnuri am pus verificarea daca tipul functiei este si acela returnat si sunt tratate si cazurile cu 'lenes'
            std::string tipReturn=((yyvsp[-1].Node)!=NULL)?(yyvsp[-1].Node)->type:"eroare";
            std::string tipFct=SymTableHelp::GetType(SymTableHelp::currentFuncName);

            if(tipFct!="eroare" && tipReturn!="eroare"){
              if(tipFct=="constructor"){
                if(tipReturn != "int_gift"){
                  std::cout << "Eroare semantica la linia "<<yylineno<<": Constructorul trebuie sa returneze 0 (int_gift)." << endl;
                }
              }
              else if(tipFct!=tipReturn){
                std::cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<SymTableHelp::currentFuncName<<" este de tip "<<tipFct<<" dar returneaza o valoare de tip "<<tipReturn<<endl;            
                }
            }

            if(tipFct=="lenes"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": O functie de tip lenes nu poate returna o valoare"<<endl;  
            }

            (yyval.Node)=NULL;
            }
#line 1839 "limbaj.tab.c"
    break;

  case 61: /* statement: RETURN_BC e_bool ';'  */
#line 332 "limbaj.y"
                                 {
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

            (yyval.Node)=NULL;
            }
#line 1859 "limbaj.tab.c"
    break;

  case 62: /* statement: RETURN_BC ';'  */
#line 348 "limbaj.y"
                          {
            std::string tipFct=SymTableHelp::GetType(SymTableHelp::currentFuncName);

            if(tipFct!="lenes" && tipFct !="eroare"){
            std::cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<SymTableHelp::currentFuncName<<" este de tip "<<tipFct<<" si trebuie sa returneze o valoare"<<endl;
            }
            
            (yyval.Node)=NULL;}
#line 1872 "limbaj.tab.c"
    break;

  case 63: /* e_bool: e EQ_GIFTS e  */
#line 358 "limbaj.y"
                     {
        string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
        string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

        if(t1 != t3 && t1 != "eroare" && t3 != "eroare") {
            cout << "Eroare semantica la linia " << yylineno << ": Nu se pot compara tipuri diferite (" << t1 << " == " << t3 << ")" << endl;
             // Facem un nod dummy cu tipul eroare pentru a nu crapa mai sus
             (yyval.Node) = new ASTNode("eroare", "OTHER");
             if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
        }
        else{
            (yyval.Node) = new ASTNode("bool", "==", (yyvsp[-2].Node), (yyvsp[0].Node));
       }
      }
#line 1891 "limbaj.tab.c"
    break;

  case 64: /* e_bool: e NEQ_GIFTS e  */
#line 372 "limbaj.y"
                 {
        string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
        string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

        if(t1 != t3 && t1 != "eroare" && t3 != "eroare") {
            cout << "Eroare semantica la linia " << yylineno << ": Nu se pot compara tipuri diferite (" << t1 << " != " << t3 << ")" << endl;
            (yyval.Node) = new ASTNode("eroare", "OTHER");
            if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
        }
        else{
            (yyval.Node) = new ASTNode("bool", "!=", (yyvsp[-2].Node), (yyvsp[0].Node)); 
        }        
  }
#line 1909 "limbaj.tab.c"
    break;

  case 65: /* e_bool: e LE_GIFTS e  */
#line 385 "limbaj.y"
                 {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " <= " << t3 << ")" << endl;
      }
      (yyval.Node) = new ASTNode("eroare", "OTHER");
      if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia "<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       (yyval.Node) = new ASTNode("eroare", "OTHER");
       if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    }
      else
      { 
         (yyval.Node) = new ASTNode("bool", "<=", (yyvsp[-2].Node), (yyvsp[0].Node));
      }
    }
#line 1934 "limbaj.tab.c"
    break;

  case 66: /* e_bool: e GE_GIFTS e  */
#line 405 "limbaj.y"
                 {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";
    
    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
        cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " >= " << t3 << ")" << endl;
      }
      (yyval.Node) = new ASTNode("eroare", "OTHER");
      if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia "<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       (yyval.Node) = new ASTNode("eroare", "OTHER");
       if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    }
      else
      { 
          (yyval.Node) = new ASTNode("bool", ">=", (yyvsp[-2].Node), (yyvsp[0].Node)); 
      }
    }
#line 1959 "limbaj.tab.c"
    break;

  case 67: /* e_bool: e LT_GIFTS e  */
#line 425 "limbaj.y"
                 {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " < " << t3 << ")" << endl;
      }
      (yyval.Node) = new ASTNode("eroare", "OTHER");
      if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia"<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       (yyval.Node) = new ASTNode("eroare", "OTHER");
       if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    }
      else
      { 
          (yyval.Node) = new ASTNode("bool", "<", (yyvsp[-2].Node), (yyvsp[0].Node)); 
      }
    }
#line 1984 "limbaj.tab.c"
    break;

  case 68: /* e_bool: e GT_GIFTS e  */
#line 445 "limbaj.y"
                 {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if(t1 != t3){
      if (t1 != "eroare" && t3 != "eroare") {
         cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " > " << t3 << ")" << endl;
      }
      (yyval.Node) = new ASTNode("eroare", "OTHER");
      if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    } else if(t1 != "int_gift" && t1 != "float_snow" && t1 != "eroare"){
        cout<<"Eroare semantica la linia"<<yylineno<<": Operatorii de inegalitate se aplica doar numerelor, nu si tipului "<< t1 <<endl;
       (yyval.Node) = new ASTNode("eroare", "OTHER");
       if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
    }
      else
      { 
          (yyval.Node) = new ASTNode("bool", ">", (yyvsp[-2].Node), (yyvsp[0].Node));
      }
    }
#line 2009 "limbaj.tab.c"
    break;

  case 69: /* e_bool: '(' e_bool ')'  */
#line 465 "limbaj.y"
                   { (yyval.Node) = (yyvsp[-1].Node); }
#line 2015 "limbaj.tab.c"
    break;

  case 70: /* e_bool: e_bool EQ_GIFTS e_bool  */
#line 467 "limbaj.y"
                          {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";
    
    if (t1 == "eroare" || t3 == "eroare") {
          (yyval.Node) = new ASTNode("eroare", "OTHER");
          if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      } else {
        (yyval.Node) = new ASTNode("bool", "==", (yyvsp[-2].Node), (yyvsp[0].Node));
      }
  }
#line 2031 "limbaj.tab.c"
    break;

  case 71: /* e_bool: e_bool NEQ_GIFTS e_bool  */
#line 478 "limbaj.y"
                           {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if (t1 == "eroare" || t3 == "eroare") {
          (yyval.Node) = new ASTNode("eroare", "OTHER");
          if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      } else {
       (yyval.Node) = new ASTNode("bool", "!=", (yyvsp[-2].Node), (yyvsp[0].Node));
      }
  }
#line 2047 "limbaj.tab.c"
    break;

  case 72: /* e_bool: e_bool EQ_GIFTS e  */
#line 489 "limbaj.y"
                      { 
    std::string t3=((yyvsp[0].Node) !=NULL)? (yyvsp[0].Node)->type : "eroare";

    if(t3=="bool"){
       (yyval.Node) = new ASTNode("bool", "==", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite (bool =="<< t3 << " )" << endl;
          (yyval.Node) = new ASTNode("eroare", "OTHER");
    }}
#line 2061 "limbaj.tab.c"
    break;

  case 73: /* e_bool: e_bool NEQ_GIFTS e  */
#line 498 "limbaj.y"
                       {
    std::string t3=((yyvsp[0].Node) !=NULL)? (yyvsp[0].Node)->type : "eroare";

    if(t3=="bool"){
       (yyval.Node) = new ASTNode("bool", "!=", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite (bool !="<< t3 << " )" << endl;
          (yyval.Node) = new ASTNode("eroare", "OTHER");
    }
   }
#line 2076 "limbaj.tab.c"
    break;

  case 74: /* e_bool: e EQ_GIFTS e_bool  */
#line 508 "limbaj.y"
                      { 
    std::string t1=((yyvsp[-2].Node) !=NULL)? (yyvsp[-2].Node)->type : "eroare";

    if(t1=="bool"){
       (yyval.Node) = new ASTNode("bool", "==", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " == bool)" << endl;
          (yyval.Node) = new ASTNode("eroare", "OTHER");
    }
  }
#line 2091 "limbaj.tab.c"
    break;

  case 75: /* e_bool: e NEQ_GIFTS e_bool  */
#line 518 "limbaj.y"
                         { 
      std::string t1=((yyvsp[-2].Node) !=NULL)? (yyvsp[-2].Node)->type : "eroare";

    if(t1=="bool"){
       (yyval.Node) = new ASTNode("bool", "!=", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<<": Nu se pot compara tipuri diferite ("<< t1 << " != bool)" << endl;
          (yyval.Node) = new ASTNode("eroare", "OTHER");
    }
   }
#line 2106 "limbaj.tab.c"
    break;

  case 76: /* e_bool: e_bool ATELIER_AND_COR e_bool  */
#line 528 "limbaj.y"
                                 { 
     (yyval.Node) = new ASTNode("bool", "&&", (yyvsp[-2].Node), (yyvsp[0].Node));
  }
#line 2114 "limbaj.tab.c"
    break;

  case 77: /* e_bool: e ATELIER_AND_COR e  */
#line 531 "limbaj.y"
                       {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if(t1=="bool" && t3=="bool")
     {(yyval.Node) = new ASTNode("bool", "&&", (yyvsp[-2].Node), (yyvsp[0].Node));} //am pus astea si acum merge if(v1 && v2)
    else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit "<<t1<<" si "<<t3<<endl;
        //facem nod dummy ca sa nu crape apoi
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2131 "limbaj.tab.c"
    break;

  case 78: /* e_bool: e_bool ATELIER_AND_COR e  */
#line 543 "limbaj.y"
                            { 
    std::string t3=((yyvsp[0].Node) != NULL)?(yyvsp[0].Node)->type:"eroare";
    if(t3=="bool"){
      (yyval.Node)=new ASTNode("bool","&&",(yyvsp[-2].Node),(yyvsp[0].Node));
    }else{
          std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit bool si "<<t3<<endl;
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2145 "limbaj.tab.c"
    break;

  case 79: /* e_bool: e ATELIER_AND_COR e_bool  */
#line 552 "limbaj.y"
                            {
    std::string t1=((yyvsp[-2].Node) != NULL)?(yyvsp[-2].Node)->type:"eroare";
    if(t1=="bool"){
      (yyval.Node) = new ASTNode("bool", "&&", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'and' cere tipul bool, dar a primit "<<t1<<" si bool"<<endl;
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2159 "limbaj.tab.c"
    break;

  case 80: /* e_bool: e_bool DECORATIUNI_OR_COLINDE e_bool  */
#line 561 "limbaj.y"
                                         { // toate combinatiile pt or ca sa fie posibil id (de bool )or nice 
     (yyval.Node) = new ASTNode("bool", "||", (yyvsp[-2].Node), (yyvsp[0].Node));
  }
#line 2167 "limbaj.tab.c"
    break;

  case 81: /* e_bool: e DECORATIUNI_OR_COLINDE e  */
#line 564 "limbaj.y"
                               {
    string t1 = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
    string t3 = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

    if(t1=="bool" && t3=="bool")
     {(yyval.Node) = new ASTNode("bool", "||", (yyvsp[-2].Node), (yyvsp[0].Node));} 
    else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit "<<t1<<" si "<<t3<<endl;
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }}
#line 2182 "limbaj.tab.c"
    break;

  case 82: /* e_bool: e_bool DECORATIUNI_OR_COLINDE e  */
#line 574 "limbaj.y"
                                    {
      std::string t3=((yyvsp[0].Node) != NULL)?(yyvsp[0].Node)->type:"eroare";
    if(t3=="bool"){
      (yyval.Node)=new ASTNode("bool","||",(yyvsp[-2].Node),(yyvsp[0].Node));
    }else{
          std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit bool si "<<t3<<endl;
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2196 "limbaj.tab.c"
    break;

  case 83: /* e_bool: e DECORATIUNI_OR_COLINDE e_bool  */
#line 583 "limbaj.y"
                                    {
     std::string t1=((yyvsp[-2].Node) != NULL)?(yyvsp[-2].Node)->type:"eroare";
    if(t1=="bool"){
      (yyval.Node) = new ASTNode("bool", "||", (yyvsp[-2].Node), (yyvsp[0].Node));
    }else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'or' cere tipul bool, dar a primit "<<t1<<" si bool"<<endl;
        (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2210 "limbaj.tab.c"
    break;

  case 84: /* e_bool: BOOL_VAL_BC  */
#line 592 "limbaj.y"
                {
      Val v;
      if(*(yyvsp[0].Str) == "nice") v.bval = true; else v.bval = false; 
      v.tip = MY_BOOL; 
   
  (yyval.Node) = new ASTNode(v, "bool");
      delete (yyvsp[0].Str);
  }
#line 2223 "limbaj.tab.c"
    break;

  case 85: /* e_bool: NOT_BC e_bool  */
#line 600 "limbaj.y"
                  { 
     
      (yyval.Node) = new ASTNode("bool", "!", (yyvsp[0].Node), NULL);
  }
#line 2232 "limbaj.tab.c"
    break;

  case 86: /* e_bool: NOT_BC e  */
#line 604 "limbaj.y"
            { 
    std::string t=((yyvsp[0].Node)!=NULL)? (yyvsp[0].Node)->type:"eroare";
    if(t=="bool"){
      (yyval.Node)=new ASTNode("bool","!",(yyvsp[0].Node),NULL);
    } else{
        std::cout<<"Eroare semantica la linia "<< yylineno <<": Operatorul 'not' cere tipul bool, dar a primit "<<t<<endl;
      (yyval.Node)=new ASTNode("eroare","OTHER");
    }
  }
#line 2246 "limbaj.tab.c"
    break;

  case 87: /* e: e '+' e  */
#line 615 "limbaj.y"
            {
      std::string tipSt = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
      std::string tipDr = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow" || tipSt == "str_letter"){
         
          (yyval.Node) = new ASTNode(tipSt, "+", (yyvsp[-2].Node), (yyvsp[0].Node));
        }
        else{
            std::cout<<"Eroare semantica la linia "<< yylineno <<": Adunarea nu este permisa pentru tipul "<<tipSt<<endl;
            (yyval.Node) = new ASTNode("eroare", "OTHER");
             if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);   
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa adunarea de tipuri diferite ("<<tipSt<<" + "<<tipDr<<")"<<endl;
        (yyval.Node) = new ASTNode("eroare", "OTHER");
        if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      }
      
}
#line 2273 "limbaj.tab.c"
    break;

  case 88: /* e: e '-' e  */
#line 637 "limbaj.y"
            {
      std::string tipSt = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
      std::string tipDr = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
         (yyval.Node) = new ASTNode(tipSt, "-", (yyvsp[-2].Node), (yyvsp[0].Node)); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Scaderea nu este permisa pentru tipul "<<tipSt<<endl;
            (yyval.Node) = new ASTNode("eroare", "OTHER");   
            if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);   
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa scaderea de tipuri diferite"<<endl;
        (yyval.Node) = new ASTNode("eroare", "OTHER");
        if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      }
  }
#line 2298 "limbaj.tab.c"
    break;

  case 89: /* e: e '*' e  */
#line 657 "limbaj.y"
            {
      std::string tipSt = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
      std::string tipDr = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
         (yyval.Node) = new ASTNode(tipSt, "*", (yyvsp[-2].Node), (yyvsp[0].Node)); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Inmultirea nu este permisa pentru tipul "<<tipSt<<endl;
            (yyval.Node) = new ASTNode("eroare", "OTHER"); 
            if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);     
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa inmultirea de tipuri diferite"<<endl;
        (yyval.Node) = new ASTNode("eroare", "OTHER");
        if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      }
  }
#line 2323 "limbaj.tab.c"
    break;

  case 90: /* e: e '/' e  */
#line 677 "limbaj.y"
            {
      std::string tipSt = ((yyvsp[-2].Node) != NULL) ? (yyvsp[-2].Node)->type : "eroare";
      std::string tipDr = ((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare";

      if(tipSt == tipDr)
      {
        if(tipSt == "int_gift" || tipSt == "float_snow"){
          (yyval.Node) = new ASTNode(tipSt, "/", (yyvsp[-2].Node), (yyvsp[0].Node)); 
        }
        else{
            std::cout<<"Eroare semantica la linia "<<yylineno<< ": Impartirea nu este permisa pentru tipul "<<tipSt<<endl;
            (yyval.Node) = new ASTNode("eroare", "OTHER");  
            if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);    
        }
      }else{
        std::cout<<"Eroare semantica la linia "<<yylineno<< ": Nu este permisa impartirea de tipuri diferite"<<endl;
        (yyval.Node) = new ASTNode("eroare", "OTHER");
        if((yyvsp[-2].Node)) delete (yyvsp[-2].Node); if((yyvsp[0].Node)) delete (yyvsp[0].Node);
      }
  }
#line 2348 "limbaj.tab.c"
    break;

  case 91: /* e: '(' e ')'  */
#line 697 "limbaj.y"
              { (yyval.Node) = (yyvsp[-1].Node); }
#line 2354 "limbaj.tab.c"
    break;

  case 92: /* e: NR  */
#line 699 "limbaj.y"
        {
      int val = stoi(*(yyvsp[0].Str));
      Val v(val);
      
(yyval.Node) = new ASTNode(v, "int_gift");
      delete (yyvsp[0].Str); 
  }
#line 2366 "limbaj.tab.c"
    break;

  case 93: /* e: FLOAT_NR  */
#line 706 "limbaj.y"
             {
      float val = stof(*(yyvsp[0].Str));
      Val v(val);
    
     (yyval.Node) = new ASTNode(v, "float_snow");
      delete (yyvsp[0].Str);
  }
#line 2378 "limbaj.tab.c"
    break;

  case 94: /* e: STRING_VAL  */
#line 713 "limbaj.y"
               {
      Val v(*(yyvsp[0].Str));
      (yyval.Node) = new ASTNode( v,"str_letter");
      delete (yyvsp[0].Str);
  }
#line 2388 "limbaj.tab.c"
    break;

  case 95: /* e: ID_BC  */
#line 718 "limbaj.y"
          { 
        if(SymTableHelp::CheckId(*(yyvsp[0].Str)))
        {
          string tip = SymTableHelp::GetType(*(yyvsp[0].Str));
         
          (yyval.Node) = new ASTNode(tip, *(yyvsp[0].Str));
        }
        else{
          (yyval.Node) = new ASTNode("eroare", "OTHER");
        }
        delete (yyvsp[0].Str);
   }
#line 2405 "limbaj.tab.c"
    break;

  case 96: /* e: ID_BC ACCES ID_BC  */
#line 730 "limbaj.y"
                      {
    SymTableHelp::CheckId(*(yyvsp[-2].Str));
    string tip = "eroare";
    if(SymTableHelp::CheckClassMember(*(yyvsp[-2].Str),*(yyvsp[0].Str))){
       tip = SymTableHelp::GetClassMemberType(*(yyvsp[-2].Str),*(yyvsp[0].Str));
    }
   
    (yyval.Node) = new ASTNode(tip, "OTHER");
    delete (yyvsp[-2].Str); delete (yyvsp[0].Str);
  }
#line 2420 "limbaj.tab.c"
    break;

  case 97: /* e: OWN_BC ACCES ID_BC  */
#line 740 "limbaj.y"
                       {
            if(SymTableHelp::CheckOwnMember(*(yyvsp[0].Str))){
                string tip = SymTableHelp::GetClassMemberTypeFromCurrentScope(*(yyvsp[0].Str));
                if(tip=="bool"){
                  cout << "Eroare semantica la linia " << yylineno << ": Membrul " << *(yyvsp[0].Str) << " este bool si nu poate fi folosit in expresii aritmetice." << endl;
                 (yyval.Node) = new ASTNode("eroare", "OTHER");
                }
                else
                (yyval.Node) = new ASTNode(tip, *(yyvsp[0].Str));
            } else {
                (yyval.Node) = new ASTNode("eroare", "OTHER");
            }
            delete (yyvsp[0].Str);
          }
#line 2439 "limbaj.tab.c"
    break;

  case 98: /* e: call_fn  */
#line 755 "limbaj.y"
            { (yyval.Node) = (yyvsp[0].Node); }
#line 2445 "limbaj.tab.c"
    break;

  case 99: /* $@8: %empty  */
#line 756 "limbaj.y"
                    { SymTableHelp::ClearCallArg(); }
#line 2451 "limbaj.tab.c"
    break;

  case 100: /* e: NEW_BC ID_BC '(' $@8 ')'  */
#line 756 "limbaj.y"
                                                          {
      // Cazul constructor fara parametri: create_gift A()
      if(SymTableHelp::CheckClassExists(*(yyvsp[-3].Str))) {
         // Verificam daca exista constructor fara parametri
         // Putem refolosi logica de la functii daca constructorul e salvat ca functie
         // Sau pur si simplu returnam tipul clasei daca nu avem verificari stricte pe constructori
         
         // Aici presupunem ca verificarea parametrilor se face in CheckFunctionCall sau similar
         // Daca constructorul e tratat ca o functie cu numele clasei:
        // SymTableHelp::currentFuncName = *$2; // Setam context pt verificare (hacky dar depinde de implementarea ta)
         // Sau pur si simplu returnam nodul:
         (yyval.Node) = new ASTNode(*(yyvsp[-3].Str), "CONSTRUCTOR_CALL"); // Returneaza un obiect de tipul NumeClasa
      } else {
         (yyval.Node) = new ASTNode("eroare", "OTHER");
      }
      delete (yyvsp[-3].Str);
  }
#line 2473 "limbaj.tab.c"
    break;

  case 101: /* $@9: %empty  */
#line 773 "limbaj.y"
                     { SymTableHelp::ClearCallArg(); }
#line 2479 "limbaj.tab.c"
    break;

  case 102: /* e: NEW_BC ID_BC '(' $@9 wishlist ')'  */
#line 773 "limbaj.y"
                                                                    {
      // Cazul constructor cu parametri: create_gift A(10, 20)
      if(SymTableHelp::CheckClassExists(*(yyvsp[-4].Str))) {
          // Aici ar trebui sa verifici daca parametrii din wishlist se potrivesc cu constructorul clasei *$2
          // De exemplu: SymTableHelp::CheckConstructorCall(*$2); 
          
          (yyval.Node) = new ASTNode(*(yyvsp[-4].Str), "CONSTRUCTOR_CALL"); // Returneaza tipul clasei
      } else {
          (yyval.Node) = new ASTNode("eroare", "OTHER");
      }
      delete (yyvsp[-4].Str);
  }
#line 2496 "limbaj.tab.c"
    break;

  case 103: /* $@10: %empty  */
#line 789 "limbaj.y"
                   {SymTableHelp::ClearCallArg(); }
#line 2502 "limbaj.tab.c"
    break;

  case 104: /* call_fn: ID_BC '(' $@10 wishlist ')'  */
#line 789 "limbaj.y"
                                                                 { 
      //bool exists = SymTableHelp::CheckId(*$1);  
      //Facem aici modificari ca sa se afiseze mesajul corect pt cand nu e declarata o functie
      bool exists = SymTableHelp::CheckFunctionExists(*(yyvsp[-4].Str));
      bool checkParams = false;
      if(exists){
        checkParams= SymTableHelp::CheckFunctionCall(*(yyvsp[-4].Str));
      }

      if(exists && checkParams){
        string tip = SymTableHelp::GetType(*(yyvsp[-4].Str));
      
        (yyval.Node) = new ASTNode(tip, "OTHER");
      }
      else{
        (yyval.Node) = new ASTNode("eroare", "OTHER");
      }
      delete (yyvsp[-4].Str);
      }
#line 2526 "limbaj.tab.c"
    break;

  case 105: /* call_fn: ID_BC '(' ')'  */
#line 808 "limbaj.y"
                       { 
            SymTableHelp::ClearCallArg();
            bool exists = SymTableHelp::CheckFunctionExists(*(yyvsp[-2].Str)); 
            bool checkParams = false;
                  
            if(exists){
              checkParams= SymTableHelp::CheckFunctionCall(*(yyvsp[-2].Str));
            }

            if(exists && checkParams){
              string tip = SymTableHelp::GetType(*(yyvsp[-2].Str));
              (yyval.Node) = new ASTNode(tip, "OTHER");
            }
            else{
              (yyval.Node) = new ASTNode("eroare", "OTHER");
            }
            delete (yyvsp[-2].Str);
       }
#line 2549 "limbaj.tab.c"
    break;

  case 106: /* $@11: %empty  */
#line 826 "limbaj.y"
                              {SymTableHelp::ClearCallArg();}
#line 2555 "limbaj.tab.c"
    break;

  case 107: /* call_fn: ID_BC ACCES ID_BC '(' $@11 wishlist ')'  */
#line 826 "limbaj.y"
                                                                          {
            if(SymTableHelp::CheckId(*(yyvsp[-6].Str))){
              if(SymTableHelp::CheckClassMethodCall(*(yyvsp[-6].Str),*(yyvsp[-4].Str))){
                 string tip = SymTableHelp::GetClassMemberType(*(yyvsp[-6].Str),*(yyvsp[-4].Str));
                 (yyval.Node) = new ASTNode(tip, "OTHER");
              }else{
               //? std::cout<<"Eroare semantica la linia "<<yylineno<< ": Metoda nu exista sau argumente gresite";
                (yyval.Node) = new ASTNode("eroare", "OTHER");
              }
          }
          else{
            (yyval.Node) = new ASTNode("eroare", "OTHER");
          }
          delete (yyvsp[-6].Str); delete (yyvsp[-4].Str);
          }
#line 2575 "limbaj.tab.c"
    break;

  case 108: /* call_fn: ID_BC ACCES ID_BC '(' ')'  */
#line 841 "limbaj.y"
                                  {
        if(SymTableHelp::CheckId(*(yyvsp[-4].Str))){
          SymTableHelp::ClearCallArg();
          if(SymTableHelp::CheckClassMethodCall(*(yyvsp[-4].Str),*(yyvsp[-2].Str))){
            string tip = SymTableHelp::GetClassMemberType(*(yyvsp[-4].Str),*(yyvsp[-2].Str));
            (yyval.Node) = new ASTNode(tip, "OTHER");
          }
          else{
            (yyval.Node) = new ASTNode("eroare", "OTHER");
          }
        }
        else{
          (yyval.Node) = new ASTNode("eroare", "OTHER");
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str);
       }
#line 2596 "limbaj.tab.c"
    break;

  case 109: /* wishlist: e  */
#line 860 "limbaj.y"
             {SymTableHelp::AddCallArg(((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare");}
#line 2602 "limbaj.tab.c"
    break;

  case 110: /* wishlist: wishlist ',' e  */
#line 861 "limbaj.y"
                           {SymTableHelp::AddCallArg(((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare");}
#line 2608 "limbaj.tab.c"
    break;

  case 111: /* wishlist: e_bool  */
#line 862 "limbaj.y"
                  {SymTableHelp::AddCallArg(((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare");}
#line 2614 "limbaj.tab.c"
    break;

  case 112: /* wishlist: wishlist ',' e_bool  */
#line 863 "limbaj.y"
                                {SymTableHelp::AddCallArg(((yyvsp[0].Node) != NULL) ? (yyvsp[0].Node)->type : "eroare");}
#line 2620 "limbaj.tab.c"
    break;


#line 2624 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 867 "limbaj.y"


void yyerror(const char * s){
    std::cout << "Eroare la linia " << yylineno << ": " << s << std::endl;
}

int main(int argc, char** argv){
    if(argc > 1) yyin = fopen(argv[1], "r");
    yyparse();  
    return 0;
}

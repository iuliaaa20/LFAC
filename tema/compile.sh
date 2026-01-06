
echo "Compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1.tab.h
rm -f $1
bison -d $1.y
flex $1.l
g++ lex.yy.c limbaj.tab.c SymTableHelp.cpp SymTable.cpp -o limbaj

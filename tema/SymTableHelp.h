#pragma once
#include "SymTable.h"

//scopul acestei clase este sa lucram direct cu ea in fisierul bison fiindca profa vrea sa avem cat mai putin cod scris in c++ in fisierul limbaj.y
// aici cumva manevram un obiect de tipul SymTable si setam totul. functiile si variabilele sunt statice pentru a putea lucra cu ele direct in limbaj.y, 
//fara sa mai trebuiasca sa declaram un obiect de tipul SymTableHelp

class SymTableHelp{
    private:
 
         static SymTable* currentScope; //scopul in care ma aflu
         static ofstream fisier; //fisierul o sa fie tables.txt, cum cere in tema, pentru a printa pe el tabelele de simboluri
         static string currentType; //tipul id-ului abia citit
         static vector<string> paramBuffer; //aici voi tine minte parametrii de functii
         static string currentFuncName; //din nou, pentru functii
    public:
        //astea o sa le explic in .cpp, desi au nume sugestive
        static void Init();          
        static  void Clean();       
        static void EnterScope(string name);
        static void ExitScope();
        static void SetType(string type); 
        static void AddVar(string name, string kind); 
        static void SetVal(string name, Val v);
        static void AddParam(string name); 
        static void SaveParams();
        static bool CheckId(string name); 
    };

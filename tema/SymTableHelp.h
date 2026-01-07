#pragma once
#include "SymTable.h"


//scopul acestei clase este sa lucram direct cu ea in fisierul bison fiindca profa vrea sa avem cat mai putin cod scris in c++ in fisierul limbaj.y
// aici cumva manevram un obiect de tipul SymTable si setam totul. functiile si variabilele sunt statice pentru a putea lucra cu ele direct in limbaj.y, 
//fara sa mai trebuiasca sa declaram un obiect de tipul SymTableHelp

class SymTableHelp{
    private:
         static ofstream fisier; //fisierul o sa fie tables.txt, cum cere in tema, pentru a printa pe el tabelele de simboluri
         static string currentType; //tipul id-ului abia citit
         static vector<string> paramBuffer; //aici voi tine minte parametrii de functii
         static vector<string> callArgsBuffer; //aici tinem argumentele la apelul functiei
         static map<string,SymTable*> classMap; // sa tinem minte tabelele claselor
    public:
        //astea o sa le explic in .cpp, desi au nume sugestive
        static string currentFuncName; //din nou, pentru functii 
        static SymTable* currentScope; //scopul in care ma aflu
        static void Init();          
        static  void Clean();       
        static void EnterScope(string name);
        static void ExitScope();
        static void SetType(string type);
        static string GetType(string name); 
        static void AddVar(string name, string kind); 
        static void SetVal(string name, Val v);
        static void AddParam(string name); 
        static void SaveParams();
        static bool CheckId(string name); 
        static void AddCallArg(string type); //adaugarea arg in buffer
        static bool CheckFunctionCall(string funcName); //verifica daca argumentele au tipul din definitie
        static void ClearCallArg(); //curata argsBuffer
        static void AddClassScope(string className, SymTable* table);
        static bool CheckClassMember(string objectName,string memberName);
        static string GetClassMemberType(string objectName, string memberName);
        static bool CheckClassMethodCall(string objectName, string methodName);
        static bool CheckFunctionExists(string name);
        static bool CheckClassExists(string name);
        static void CheckConstructorName(string name);
        static bool CheckOwnMember(string memberName);
        static string GetClassMemberTypeFromCurrentScope(string memberName);
        
    };
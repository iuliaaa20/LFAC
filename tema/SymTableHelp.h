#include "SymTable.h"
class SymTableHelp{
    private:
 
         static SymTable* currentScope; 
         static ofstream fisier;
         static string currentType; 
    
    public:
    static vector<string> paramBuffer; 
    static string currentFuncName;
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
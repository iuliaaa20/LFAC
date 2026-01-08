#pragma once
#include "SymTable.h"




class SymTableHelp{
    private:
         static ofstream fisier; 
         static string currentType; 
         static vector<string> paramBuffer; 
         static vector<string> callArgsBuffer; 
         static map<string,SymTable*> classMap; 
    public:
        
        static string currentFuncName; 
        static SymTable* currentScope; 
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
        static void AddCallArg(string type); 
        static bool CheckFunctionCall(string funcName); 
        static void ClearCallArg(); 
        static void AddClassScope(string className, SymTable* table);
        static bool CheckClassMember(string objectName,string memberName);
        static string GetClassMemberType(string objectName, string memberName);
        static bool CheckClassMethodCall(string objectName, string methodName);
        static bool CheckFunctionExists(string name);
        static bool CheckClassExists(string name);
        static void CheckConstructorName(string name);
        static bool CheckConstructorCall(string className);
        static bool CheckOwnMember(string memberName);
        static string GetClassMemberTypeFromCurrentScope(string memberName);
        
    };
#include "SymTableHelp.h"

SymTable* SymTableHelp::currentScope = NULL;     
ofstream SymTableHelp::fisier;               
string SymTableHelp::currentType = "";      
vector<string> SymTableHelp::paramBuffer;
string SymTableHelp::currentFuncName = ""; 
vector<string> SymTableHelp::callArgsBuffer; 
map<string, SymTable*> SymTableHelp::classMap;

extern int yylineno;

void SymTableHelp:: Init() {
    fisier.open("tables.txt");
    EnterScope("global");
}

void SymTableHelp::EnterScope(string name) {
    currentScope = new SymTable(name, currentScope);
}

void SymTableHelp::ExitScope() {
    if (currentScope) { 
        currentScope->print(fisier); 
        SymTable* c = currentScope;
        currentScope = currentScope->getPred(); 
        
    }
}

void SymTableHelp::Clean() {
    ExitScope();
    fisier.close();
}

void SymTableHelp::SetType(string type) {
    currentType = type;
}

string SymTableHelp::GetType(string name){
    if(currentScope){
        return currentScope->getType(name);
    }
    return "eroare";
}

void SymTableHelp::AddVar(string name, string kind) {
    if (currentScope) {
       
        currentScope->addVar(currentType, name, kind);
    }
}

void SymTableHelp::SetVal(string name, Val v) {
    if (currentScope != NULL) {
        currentScope->setVal(name, v);
    } 
}
void SymTableHelp::AddParam(string name) {
    if (currentScope) {
        currentScope->addVar(currentType, name, "parametru");
        paramBuffer.push_back(currentType); 
    }
}

void SymTableHelp::SaveParams() {
    if (currentScope && currentScope->getPred()) { 
        SymTable* parentScope = currentScope->getPred(); 
        
        parentScope->setParams(currentFuncName, paramBuffer); 
    
        paramBuffer.clear();
    }
}

bool SymTableHelp::CheckId(string name) {
    if (currentScope && currentScope->findId(name)) {
        return true; 
    }

    cout << "Eroare la linia "<<yylineno<<": variabila '" << name << "' nu e declarata intr-un scop vizibil" << endl;
    return false;
}

void SymTableHelp::AddCallArg(string type){
    callArgsBuffer.push_back(type);

}

bool SymTableHelp::CheckFunctionCall(string funcName){
    if(!currentScope)
    return false;

    vector<string> expectedParams=currentScope->getParams(funcName);
    
    if(expectedParams.size()!=callArgsBuffer.size())
     {
        cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<funcName<<" asteapta "<<expectedParams.size()<<" argumente in loc de "<<callArgsBuffer.size()<<" argumente primite"<<endl;
        return false;        
    }
    for(int i=0;i<expectedParams.size();i++)
    {
        if(expectedParams[i] != callArgsBuffer[i]){
            cout<<"Eroare semantica la linia "<<yylineno<<" la apelul functiei "<<funcName<<". Argumentul "<<(i+1)<<" are tipul incorect ("<<callArgsBuffer[i]<<") in loc de "<<expectedParams[i]<<endl;
        return false;
        }
        
    }
    return true;
}

void SymTableHelp::ClearCallArg(){
    callArgsBuffer.clear();
}

void SymTableHelp::AddClassScope(string className, SymTable* table){
    classMap[className]=table;
}

bool SymTableHelp::CheckClassMember(string objectName, string memberName){
    if(!currentScope->existsId(objectName)){
        cout<<"Eroare la linia "<<yylineno<<": Obiectul "<<objectName<<" nu este definit"<<endl;
        return false;
    }
    string className=GetType(objectName);

    if(classMap.find(className)==classMap.end()){
        cout<<"Eroare la linia "<<yylineno<<": "<<objectName<<" are tipul "<<className<<" care nu este o clasa"<<endl;
        return false;
    }

    SymTable* classTable=classMap[className];

    if(classTable->existsId(memberName)){
        return true;
    }else{
        cout<<"Eroare la linia "<<yylineno<<": Clasa "<<className<<" nu are membrul "<<memberName<<endl;
        return false;
    }
}

string SymTableHelp::GetClassMemberType(string objectName, string memberName){
    string className=GetType(objectName);
    if(classMap.find(className)!=classMap.end()){
        SymTable* classTable=classMap[className];

        IdInfo* id=classTable->findId(memberName);
        if(id) return id->type;
    }
    return "eroare";
}

bool SymTableHelp::CheckClassMethodCall(string objectName, string methodName){
    string className=currentScope->getType(objectName);

    if(className=="eroare"){
        cout<<"Eroare semantica la linia "<<yylineno<<": Obiectul"<<objectName<<" nu este declarat"<<endl;
        return false;
    }
    
    if (classMap.find(className)==classMap.end()){
        cout<<"Eroare semantica la linia "<<yylineno<<": Variabila "<<objectName<<" are tipul "<<className<<" care nu este o clasa definita "<<endl;
        return false;
    }

    SymTable* classTable=classMap[className];
    IdInfo* methodInfo=classTable->findId(methodName);

    if(methodInfo==NULL){
        cout<<"Eroare semantica la linia "<<yylineno<<": Clasa "<<className<<" nu are metoda "<<methodName<<endl;
        return false;
    }

    if(methodInfo->kind!="functie"){
        cout<<"Eroare semantica la linia "<<yylineno<<": "<<methodName<<" este definita in clasa "<<className<<", dar nu este o functie, ci  "<<methodInfo->kind<<endl;
        return false;
    }

    if(methodInfo->paramTypes.size()!=callArgsBuffer.size()){
        cout<<"Eroare semantica la linia "<<yylineno<<": Numar gresit de parametri pentru metoda "<<methodName<<". A primit "<<callArgsBuffer.size()<<" parametri, se asteapta "<<methodInfo->paramTypes.size()<<endl;
        return false;
    }

    for(int i=0;i<methodInfo->paramTypes.size();i++){
        if(methodInfo->paramTypes[i]!=callArgsBuffer[i]){
            cout<<"Eroare semantica la linia "<<yylineno<<": Tipul argumentului de pe pozitia "<<i+1<<" este gresit. Metoda "<<methodName<<" astepta "<<methodInfo->paramTypes[i]<<" si a primit "<<callArgsBuffer[i]<<endl;
        return false;
        }
    }
    return true;
}

bool SymTableHelp::CheckFunctionExists(string name){
    if(currentScope==NULL) return false;

    IdInfo* id=currentScope->findId(name);

    if(id==NULL){
        cout<<"Eroare semantica la linia "<<yylineno<<": Functia "<<name<<" nu este declarata"<<"intr-un scope parinte/bunic"<<endl;
        return false;
    }

    if(id->kind!="functie"){
    cout<<"Eroare semantica la linia "<<yylineno<<": "<<name<<" este definita ca "<<id->kind<<" si nu poate fi apelata ca functie"<<endl;
        return false;    }

    return true;
}

bool SymTableHelp::CheckClassExists(string name){
    if(classMap.find(name)==classMap.end()){
        cout<<"Eroare semantica la linia "<<yylineno<<": Clasa "<<name<<" nu este definita (sau este definita mai jos)"<<endl;
        return false;
    }
    return true;

}

bool SymTableHelp::CheckOwnMember(string memberName){
    if(!currentScope) return false;
    SymTable* parent=currentScope->getPred();
    if(!parent){
        cout<<"Eroare semantica la linia "<<yylineno<<": own poate fi utilizat doar in interiorul metodelor unei clase"<<endl;
        return false;
    }

    if(parent->existsId(memberName)){
        return true;
    }else{
        cout<<"Eroare semantica la linia "<<yylineno<<": Membrul "<<memberName<<" nu exista in clasa curenta"<<endl;
        return false;
    }
}

string SymTableHelp::GetClassMemberTypeFromCurrentScope(string memberName) {
    if (currentScope && currentScope->getPred()) {
        return currentScope->getPred()->getType(memberName);
    }
    return "eroare";
}

void SymTableHelp::CheckConstructorName(string name){
    if(!currentScope) return;
    string scopeName=currentScope->getScopeName();

    if (scopeName.find("Class_") == 0) {
        string className=scopeName.substr(6);
        if(className!=name){
            cout<<"Eroare semantica la linia"<<yylineno<<": Constructorul "<<name<<" trebuie sa aiba acelasi nume cu clasa, mai exact "<<className<<endl;
        }
    }else{
        cout<<"Eroare semantica la linia"<<yylineno<<": Constructorii pot fi definiti doar in interiorul claselor "<<endl;

    }

}
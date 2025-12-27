#include "SymTableHelp.h"

SymTable* SymTableHelp::currentScope = NULL;     
ofstream SymTableHelp::fisier;               
string SymTableHelp::currentType = "";      
vector<string> SymTableHelp::paramBuffer;
string SymTableHelp::currentFuncName = ""; 

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
        delete c;
    }
}

void SymTableHelp::Clean() {
    ExitScope();
    fisier.close();
}

void SymTableHelp::SetType(string type) {
    currentType = type;
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
        SymTable* globalScope = currentScope->getPred();
        
        globalScope->setParams(currentFuncName, paramBuffer);
    
        paramBuffer.clear();
    }
}

bool SymTableHelp::CheckId(string name) {
    if (currentScope && currentScope->findId(name)) {
        return true; 
    }

    cout << "Eroare: variabila '" << name << "' nu e declarata" << endl;
    return false;
}
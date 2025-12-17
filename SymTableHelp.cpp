#include "SymTableHelp.h"

SymTable* SymTableHelp::currentScope = NULL;     
ofstream SymTableHelp::fisier;               
string SymTableHelp::currentType = "";       

void SymTableHelp:: Init() {
    fisier.open("tables.txt");
    EnterScope("GLOBAL");
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

bool SymTableHelp::CheckId(string name) {
    if (currentScope && currentScope->findId(name)) {
        return true; 
    }

    cout << "Eroare: variabila '" << name << "' nu e declarata" << endl;
    return false;
}
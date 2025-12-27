#include "SymTableHelp.h"
//disclaimer: unele functii posibil sa le intelegi mai bine dupa de ce le avem dupa ce te uiti si peste limbaj.y
//aici fac declarari:
SymTable* SymTableHelp::currentScope = NULL;     
ofstream SymTableHelp::fisier;               
string SymTableHelp::currentType = "";      
vector<string> SymTableHelp::paramBuffer;
string SymTableHelp::currentFuncName = ""; 

//imi deschid fisierul unde voi printa tabelele si intru in scopul global:
void SymTableHelp:: Init() {
    fisier.open("tables.txt");
    EnterScope("global");//are default parinte NULL
}
//cand voi intra intr-un scop nou(functie,clasa), apelez functia asta:
void SymTableHelp::EnterScope(string name) {
    currentScope = new SymTable(name, currentScope);
}

//iesim din functie/clasa/scop:
void SymTableHelp::ExitScope() {
    if (currentScope) { //asta e verificare de siguranta
        currentScope->print(fisier); //printez tabela pentru acel scop
        SymTable* c = currentScope;
        currentScope = currentScope->getPred(); //ma mut in scopul parinte
        delete c; //sterg tabela scopului de dinainte. mi a zis gemini ca atunci cand vom verifica semantic si vom avea functii s-ar putea sa nu mai vrem sa stergem, de tinut minte
    }
}

void SymTableHelp::Clean() {
    ExitScope();
    fisier.close();
}

void SymTableHelp::SetType(string type) {
    currentType = type;
}
//aici doar apelez functia din symtable simplu, la fel si la SetVal de dupa:
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
        currentScope->addVar(currentType, name, "parametru");//ca la variabile
        paramBuffer.push_back(currentType); //pun si in buffer tipurile parametrilor, ne va ajuta mai tarziu
    }
}

//again,e pentru functii
void SymTableHelp::SaveParams() {
    if (currentScope && currentScope->getPred()) { //e verificare pt siguranta
        SymTable* parentScope = currentScope->getPred(); //fie va fi scopul global, fie o clasa
        
        parentScope->setParams(currentFuncName, paramBuffer); //doar apelam functia din SymTable
    
        paramBuffer.clear();
    }
}
//sa ne asiguram ca variabila e declarata inainte sa o folosim:
bool SymTableHelp::CheckId(string name) {
    if (currentScope && currentScope->findId(name)) {
        return true; 
    }

    cout << "Eroare: variabila '" << name << "' nu e declarata" << endl;
    return false;
}

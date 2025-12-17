#include "SymTable.h"

SymTable::SymTable(string name, SymTable* pred) {
    this->scopeName = name;
    this->pred= pred;
}

void SymTable::addVar(string type, string name, string kind) {
    if (ids.count(name)) {
        cout << "Eroare: Id " << name << " este deja definit in scope " << scopeName << endl;
        return;
    }
    IdInfo info(type, name, kind);
    ids[name] = info;
}

bool SymTable::existsId(string name) {
    return ids.count(name) > 0;
}


IdInfo* SymTable::findId(string name) {
    if (ids.count(name)) {
        return &ids[name];
    }
    if (pred != NULL) {
        return pred->findId(name);
    }
    return NULL;
}

SymTable* SymTable::getPred() {
    return pred;
}

void SymTable::print(ofstream& file) {
    file << "Scope: " << scopeName << endl;
    if (pred) {
        file << "(Predecesor: " << pred->scopeName << ")" << endl;
    }
    
    if (ids.empty()) {
        file << "  [Empty scope]" << endl;
    } else {
        for ( auto& pair : ids) {
            file << "  Name: " << pair.first 
                 << " Type: " << pair.second.type 
                 << " Kind: " << pair.second.kind << endl;
        }
    }

}

SymTable::~SymTable() {
    ids.clear();
}
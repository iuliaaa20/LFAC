#include "SymTable.h"

SymTable::SymTable(string name, SymTable* pred) {
    this->scopeName = name; 
    this->pred= pred;
}

void SymTable::addVar(string type, string name, string kind) {
    if (ids.count(name)) {
        cout << "Eroare la linia "<<yylineno<<": Id " << name << " este deja definit in scope " << scopeName << endl; 
        return;
    }

    IdInfo info(type, name, kind);
 
    if (type == "int_gift")      info.value.tip = MY_INT;
    else if (type == "float_snow") info.value.tip = MY_FLOAT;
    else if (type == "str_letter") info.value.tip = MY_STRING;
    else if (type == "bool")       info.value.tip = MY_BOOL;
    else info.value.tip = MY_NEDEF; 
    
    ids[name] = info; 
}

void SymTable::setVal(string name, Val v) {
    IdInfo* id = findId(name); 
    if (id != NULL) 
        id->value = v; 
}

void SymTable::setParams(string name, vector<string> params) {
    IdInfo* id = findId(name); 
    if (id != NULL) {
        id->paramTypes = params; 
    }
}

bool SymTable::existsId(string name) {
    if (ids.count(name)) 
       return true;

    if (pred != NULL) 
        return pred->existsId(name);
    return false;
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
        file << "  Parent: " << pred->scopeName << endl;
    }
    
    if (ids.empty()) {
        file << "  [Empty scope]" << endl;
    } else {
        for ( auto& pair : ids) {
            IdInfo& info = pair.second;
            file << "   Name: " << info.name 
                 << "  | Kind: " << info.kind 
                 << "  | Type: " << info.type 
                 << "  | Val: ";
            switch (info.value.tip) {
                case MY_INT:    file << info.value.ival; break;
                case MY_FLOAT:  file << info.value.fval; break;
                case MY_STRING: file  << info.value.sval; break;
                case MY_BOOL:   file << (info.value.bval ? "true" : "false"); break;
                default:        file << " (Object/Undef)"; break;
            }
            file << endl;
        }
    }
}

string SymTable::getType(string name){
    IdInfo* id = findId(name);
    if(id!=NULL)
    return id->type;
    return "eroare";
}

vector<string> SymTable::getParams(string name){
    IdInfo* id=findId(name);
    if(id!=NULL && id->kind == "functie")
    {return id->paramTypes;}
    return vector<string>(); 
}

string SymTable::getScopeName()
{
    return scopeName;
}

SymTable::~SymTable() {
    ids.clear();
}
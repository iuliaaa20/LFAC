#include "SymTable.h"
//asta e construnctorul pentru o tabela noua de simboluri, e destul de basic (fiecare tabela e pentru un scope. de asta ii setam numele scope-ului si parintele)
SymTable::SymTable(string name, SymTable* pred) {
    this->scopeName = name; 
    this->pred= pred;
}

//vrem sa adaugam o variabile(simbol) in tabela
void SymTable::addVar(string type, string name, string kind) {
    if (ids.count(name)) {
        cout << "Eroare: Id " << name << " este deja definit in scope " << scopeName << endl; //nu putem defini de doua ori in acelasi scope o variabila
        return;
    }

    IdInfo info(type, name, kind);//setez informatiile despre id

    //aici ii dau si tipul pe care il stie clasa Val ca mai tarziu sa ii pot da valoarea corespunzatoare si sa verific daca e de tip bun:
    if (type == "int_gift")      info.value.tip = MY_INT;
    else if (type == "float_snow") info.value.tip = MY_FLOAT;
    else if (type == "str_letter") info.value.tip = MY_STRING;
    else if (type == "bool")       info.value.tip = MY_BOOL;
    else info.value.tip = MY_NEDEF; 
    
    ids[name] = info; //in caz ca ai uitat, ids e mapul meu de tipul: <nume Id,informatii id>
}
void SymTable::setVal(string name, Val v) {
    
    IdInfo* id = findId(name); //imi gaseste id-ul in tabela in functie de nume
    if (id != NULL) //daca l-a gasit, ii atribuie valoare
        id->value = v; 
}

//metoda folosita atunci cand simbolul e functie:
void SymTable::setParams(string name, vector<string> params) {
    IdInfo* id = findId(name); //am gasit numele functiei
    if (id != NULL) {
        id->paramTypes = params; //tinem minte ce parametri are functia in definitia ei
    }
}

bool SymTable::existsId(string name) {
    if (ids.count(name)) 
       return true;

    if (pred != NULL) 
        return pred->existsId(name);//aici il cauta recursiv in parinte ca poate a fost definit in alt scope
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

//functie de printare a informatiilor despre id-uri:
void SymTable::print(ofstream& file) {
    file << "Scope: " << scopeName << endl;
    if (pred) {
        file << "Parent: " << pred->scopeName << endl;
    }
    
    if (ids.empty()) {
        file << "  [Empty scope]" << endl;
    } else {
        for ( auto& pair : ids) {
            IdInfo& info = pair.second;
            file << "  Name: " << info.name 
                 << " | Kind: " << info.kind 
                 << " | Type: " << info.type 
                 << " | Val: ";
             //aici afisam valoarea lor(trebuie sa fac cu case pentru tip fiindca orice id contine toate tipurile de val(int,float,string,bool) 
           // dar are informatie adevarata doar in variabila(ival,fval,etc) potrivita:
            switch (info.value.tip) {
                case MY_INT:    file << info.value.ival; break;
                case MY_FLOAT:  file << info.value.fval; break;
                case MY_STRING: file << "\"" << info.value.sval << "\""; break;
                case MY_BOOL:   file << (info.value.bval ? "true" : "false"); break;
                default:        file << " (Object/Undef)"; break;
            }
            file << endl;
        }
    }

}

SymTable::~SymTable() {
    ids.clear();
}

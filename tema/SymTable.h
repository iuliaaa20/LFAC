#pragma once
//Aceasta clasa este pentru a retine si lucra cu simboluri(id-uri, nume de clase, de functii)

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

extern int yylineno;
//aici avem niste nume definite de noi pentru tipurile de date
enum DataTypes{
MY_INT,
MY_FLOAT,
MY_STRING,
MY_BOOL,
MY_NEDEF //asta este pentru obiecte din clase cred si pt nume de functii, simboluri fara un tip definit
};
//urmeaza o clasa ajutatoare pentru a retine valoarea fiecarei variabile
class Val{
  public:
    DataTypes tip; //poate fi orice tip de mai sus din enum
    int ival = 0; //aici initializez orice variabila cu ceva standard (0) ca sa nu mi le initializeze cu ceva valoare random gen 989897
    float fval = 0.0;
    string sval = "";
    bool bval = true;
  //constructorii astia ar trebui sa ne faca viata mai usoara cand vom implementa AST:
    Val() : tip(MY_NEDEF) {} 
    Val(int v) : tip(MY_INT), ival(v) {}
    Val(float v) : tip(MY_FLOAT), fval(v) {}
    explicit Val(string v) : tip(MY_STRING), sval(v) {}
    Val(bool v) : tip(MY_BOOL), bval(v) {}


};
//alta clasa ajutatoare. pentru fiecare id voi avea un obiect de tipul IdInfo unde retin tipul, numele, kind(clasa,functie,variabila) si valoarea id-ului;
class IdInfo {
public:
    string type;
    string name;
    string kind;
    Val value;
    vector<string> paramTypes; // acest camp din clasa va fi folosit numai daca kind=functie si ii retinem si parametrii
    IdInfo() {}
    IdInfo(string type, string name, string kind) 
        : type(type), name(name), kind(kind) {}
};
//clasa principala:
class SymTable {
    SymTable* pred; //am un pointer la parintele scopului meu. adica daca sunt intr-o functie dintr-o clasa, pred va fi clasa, iar pentru clasa respectiva, pred va fi scopul global.         
    map<string, IdInfo> ids;    //pt numele fiecarui id, tin toate informatiile despre acesta
    string scopeName;    //scopul in care sunt      

public:
    SymTable(string name, SymTable* pred = NULL); //pred e default NULL findca scopul global are parintele null
    
    void addVar(string type, string name, string kind= "variabila"); //adaug id-uri in tabela de simboluri
    void setVal(string name, Val v); //setez valoarea pt variabile
    void setParams(string name, vector<string> params); //asta e doar pt functii ca sa le setez parametrii
    bool existsId(string name); //verific ca exista un id atunci cand acesta este folosit
    IdInfo* findId(string name); //il gaseste
    SymTable* getPred();//functie care ma ajuta sa merg si in scope-urile parinte ca sa caut variabile
    void print(ofstream& file); //e pentru a printa tabele de simboluri(Se cere in enuntul temei)
    string getType(string name); //ne da tipul variabilei ca sa putem sa facem verificari semantice
    vector<string> getParams(string name); // returnează lista de tipuri pentru parametri
    string getScopeName();
    ~SymTable();
};

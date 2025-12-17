#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class IdInfo {
public:
    string type;
    string name;
    string kind;

    IdInfo() {}
    IdInfo(string type, string name, string kind) 
        : type(type), name(name), kind(kind) {}
};

class SymTable {
    SymTable* pred;          
    map<string, IdInfo> ids;    
    string scopeName;          

public:
    SymTable(string name, SymTable* pred = NULL);
    
    void addVar(string type, string name, string kind= "variabila");
    bool existsId(string name);
    IdInfo* findId(string name);
    SymTable* getPred();
    void print(ofstream& file);

    ~SymTable();
};


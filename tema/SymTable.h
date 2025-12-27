#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum DataTypes{
MY_INT,
MY_FLOAT,
MY_STRING,
MY_BOOL,
MY_NEDEF
};

class Val{
  public:
    DataTypes tip;
    int ival = 0;
    float fval = 0.0;
    string sval = "";
    bool bval = true;

    Val() : tip(MY_NEDEF) {} 
    Val(int v) : tip(MY_INT), ival(v) {}
    Val(float v) : tip(MY_FLOAT), fval(v) {}
    Val(string v) : tip(MY_STRING), sval(v) {}
    Val(bool v) : tip(MY_BOOL), bval(v) {}


};

class IdInfo {
public:
    string type;
    string name;
    string kind;
    Val value;
    vector<string> paramTypes;
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
    void setVal(string name, Val v);
    void setParams(string name, vector<string> params);
    bool existsId(string name);
    IdInfo* findId(string name);
    SymTable* getPred();
    void print(ofstream& file);

    ~SymTable();
};


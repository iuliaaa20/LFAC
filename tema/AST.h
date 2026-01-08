#pragma once
#include <string>
#include <vector>
#include "SymTable.h"

using namespace std;

class ASTNode {
public:
    ASTNode* left;
    ASTNode* right;
    string root; 
    string type; 
    Val val;     

    ASTNode(string type, string root, ASTNode* left, ASTNode* right);
    ASTNode(string type, string root);
    ASTNode(Val v, string type);
    ASTNode(const char* t, const char* r);
    
    ~ASTNode();

    string my_to_string();
    Val eval(SymTable* table);
};
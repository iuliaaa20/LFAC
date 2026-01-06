#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SymTable.h"
#include "SymTableHelp.h"

using namespace std;

class ASTNode {
public:
    ASTNode* left;
    ASTNode* right;
    string root; // Aici tinem "Operatorul" (+, -, :=) sau "Numele variabilei" sau "OTHER"
    string type; // "int_gift", "float_snow", etc.
    Val val;     // Valoarea (doar daca e constanta: 5, 3.14, "text")

    // 1. Constructorul GENERAL (4 parametri) - pentru Operatori Binari (+, -, *, :=)
    // NU are valori default la left/right pentru a nu crea confuzie cu constructorul 2.
    ASTNode(string type, string root, ASTNode* left, ASTNode* right) 
        : type(type), root(root), left(left), right(right) {}

    // 2. Constructor SIMPLU (2 string-uri) - pentru Variabile (ID) si OTHER
    ASTNode(string type, string root) 
        : type(type), root(root), left(NULL), right(NULL) {}

    // 3. Constructor CONSTANTE (string + Val) - pentru NR, FLOAT, BOOL
    ASTNode(Val v, string type) : type(type), val(v), left(NULL), right(NULL)
    {
        if (type == "int_gift") root = to_string(v.ival);
        else if (type == "float_snow") root = to_string(v.fval);
        else if (type == "bool") root = (v.bval ? "true" : "false");
        else if (type == "str_letter") root = v.sval; 
    }
    ASTNode(const char* t, const char* r) 
        : type(t), root(r), left(NULL), right(NULL) {}
    
    ~ASTNode() { 
        if(left) delete left; 
        if(right) delete right; 
    }

    Val eval(SymTable* table) {
        
        // 1. Noduri Dummy (OTHER) - Returnam valori default ca sa nu crape programul
        if (root == "OTHER") {
            if (type == "int_gift") return Val(0);
            if (type == "float_snow") return Val(0.0f);
            if (type == "str_letter") return Val(string(""));
            if (type == "bool") return Val(true);
            return Val();
        }

        // 2. Operatori Aritmetici
        if (root == "+") {
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            
            if (type == "int_gift") return Val(v1.ival + v2.ival);
            if (type == "float_snow") return Val(v1.fval + v2.fval);
            if (type == "str_letter") return Val(v1.sval + v2.sval);
        }

        if (root == "-") {
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            if (type == "int_gift") return Val(v1.ival - v2.ival);
            if (type == "float_snow") return Val(v1.fval - v2.fval);
        }
        
        if (root == "*") {
             Val v1 = left->eval(table);
             Val v2 = right->eval(table);
             if (type == "int_gift") return Val(v1.ival * v2.ival);
             if (type == "float_snow") return Val(v1.fval * v2.fval);
        }

        if (root == "/") {
             Val v1 = left->eval(table);
             Val v2 = right->eval(table);
             if (type == "int_gift"){
                if(v2.ival==0){
                    cout<<"Eroare: nu se poate efectua impartirea la 0\n";
                    return Val();
                }
                else
                return Val(v1.ival / v2.ival);
             } 
             if (type == "float_snow"){
                if(v2.ival==0.0f){
                    cout<<"Eroare: nu se poate efectua impartirea la 0\n";
                    return Val();
                }
                else                
                return Val(v1.fval / v2.fval);
            }
        }

        // 3. Operatori Logici / Relationali (Zona Colegei)
        // Aici trebuie adaugati: <, >, <=, >=, !=, &&, ||, !
        
        if (root == "==") { 
             Val v1 = left->eval(table);// deci aici se iau valorile si pt id uri din symtable si sunt verificate mai jos deci trebuie doar tipurile de date defaul verificate
             Val v2 = right->eval(table);
             // Exemplu simplu pentru int (Colega trebuie sa extinda pt float/bool)
             if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival == v2.ival);
             if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval == v2.fval);
             if (v1.tip == MY_BOOL && v2.tip == MY_BOOL) return Val(v1.bval == v2.bval);
             if (v1.tip == MY_STRING && v2.tip == MY_STRING) return Val(v1.sval == v2.sval);
             return Val(false); 
        }

        if (root == "!=") {
             Val v1 = left->eval(table);
             Val v2 = right->eval(table);
             if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival != v2.ival);
             if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval != v2.fval);
             if (v1.tip == MY_BOOL && v2.tip == MY_BOOL) return Val(v1.bval != v2.bval);
             if (v1.tip == MY_STRING && v2.tip == MY_STRING) return Val(v1.sval != v2.sval);
             return Val(false); 
        }

        if(root=="<"){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival < v2.ival);
            if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval < v2.fval);
            return Val(false); 
        }

        if(root==">"){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival > v2.ival);
            if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval > v2.fval);
            return Val(false);             
        }

        if(root=="<="){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival <= v2.ival);
            if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval <= v2.fval);
            return Val(false);             
        }

        if(root==">="){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            if (v1.tip == MY_INT && v2.tip == MY_INT) return Val(v1.ival >= v2.ival);
            if (v1.tip == MY_FLOAT && v2.tip == MY_FLOAT) return Val(v1.fval >= v2.fval);
            return Val(false);             
        }

        if(root=="&&"){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            return Val(v1.bval && v2.bval);      
            
        }

        if(root=="||"){
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            return Val(v1.bval || v2.bval);      
            
        }

        if(root=="!"){
            Val v1 = left->eval(table);
            return Val(!v1.bval);      
            
        }
        // 4. Assignment (Atribuire)
        // am schimbat din ASSIGN in := cum era cerinta 
        if (root == ":=") {
             // Structura: left este Variabila (ID), right este Expresia
             Val res = right->eval(table);
             
             // Numele variabilei se afla in root-ul copilului stang
             // Copilul stang e un nod de tip ID creat cu new ASTNode(type, "nume_var")
             string numeVar = left->root; 
             
             if(table) {
                 table->setVal(numeVar, res);
             }
             return res;
        }

        // 5. Print
        if (root == "PRINT") {
             Val res = left->eval(table);
             if(res.tip==MY_NEDEF){return res;} // in caz ca vrem sa facem Print(int==nice) sa nu ne lase sa printam si sa piarda cumva mesajul de eroare semantica

             if (res.tip == MY_INT) cout << res.ival << endl;
             else if (res.tip == MY_FLOAT) cout << res.fval << endl;
             else if (res.tip == MY_STRING) cout << res.sval << endl;
             else if (res.tip == MY_BOOL) cout << (res.bval ? "nice" : "naughty") << endl;
             return res;
        }

        // 6. Cautare Variabila (ID)
        // Daca nu e operator si nu e OTHER si nu e CONSTANTA (left/right sunt NULL)
        // verificam daca numele din 'root' exista in tabela
        if (table && left == NULL && right == NULL) {
            IdInfo* info = table->findId(root);
            
            if (info != NULL) {
                // Returnam valoarea curenta din tabela
                return info->value;
            }
        }

        // 7. Constanta (Frunza)
        // Daca am ajuns aici, inseamna ca e un numar sau un string (5, "text")
        return val;
    }
};
#include "AST.h"
#include <iostream>
#include "SymTableHelp.h" 

using namespace std;

ASTNode::ASTNode(string type, string root, ASTNode* left, ASTNode* right) 
    : type(type), root(root), left(left), right(right) {}

ASTNode::ASTNode(string type, string root) 
    : type(type), root(root), left(NULL), right(NULL) {}

ASTNode::ASTNode(Val v, string type) : type(type), val(v), left(NULL), right(NULL)
{
    if (type == "int_gift") root = to_string(v.ival);
    else if (type == "float_snow") root = to_string(v.fval);
    else if (type == "bool") root = (v.bval ? "nice" : "naughty");
    else if (type == "str_letter") root = v.sval; 
}

ASTNode::ASTNode(const char* t, const char* r) 
    : type(t), root(r), left(NULL), right(NULL) {}

ASTNode::~ASTNode() { 
    if(left) delete left; 
    if(right) delete right; 
}

string ASTNode::my_to_string() {
    if (left == NULL && right == NULL) {
        if (type == "str_letter") return "\"" + root + "\""; 
        return root; 
    }

    if (root == "!") {
        return "!" + left->my_to_string();
    }

    if (left != NULL && right != NULL) {
        return "(" + left->my_to_string() + " " + root + " " + right->my_to_string() + ")";
    }

    return ""; 
}

Val ASTNode::eval(SymTable* table) {
    if (root == "OTHER") {
        if (type == "int_gift") return Val(0);
        if (type == "float_snow") return Val(0.0f);
        if (type == "str_letter") return Val(string("default_str"));
        if (type == "bool") return Val(false);
        
        return Val();
    }

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

    if (root == "==") { 
            Val v1 = left->eval(table);
            Val v2 = right->eval(table);
            
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

    if (root == ":=") {
            Val res = right->eval(table);
            
            string numeVar = left->root; 
            
            if(table) {
                table->setVal(numeVar, res);
            }
            return res;
    }

    if (root == "PRINT") {
        string eText = left->my_to_string();
        cout << "Print(" << eText << ") -> ";

        Val res = left->eval(table);
        
        if(res.tip == MY_NEDEF){ return res; } 

        if (res.tip == MY_INT) cout << res.ival << endl;
        else if (res.tip == MY_FLOAT) cout << res.fval << endl;
        else if (res.tip == MY_STRING) cout << res.sval << endl;
        else if (res.tip == MY_BOOL) cout << (res.bval ? "nice" : "naughty") << endl;
        
        
        return res;
    }

    if (table && left == NULL && right == NULL&& val.tip==MY_NEDEF) {
        IdInfo* info = table->findId(root);
        
        if (info != NULL) {
            return info->value;
        }
    }

    return val;
}
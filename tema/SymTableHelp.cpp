#include "SymTableHelp.h"
//disclaimer: unele functii posibil sa le intelegi mai bine dupa de ce le avem dupa ce te uiti si peste limbaj.y
//aici fac declarari:
SymTable* SymTableHelp::currentScope = NULL;     
ofstream SymTableHelp::fisier;               
string SymTableHelp::currentType = "";      
vector<string> SymTableHelp::paramBuffer;
string SymTableHelp::currentFuncName = ""; 
vector<string> SymTableHelp::callArgsBuffer; //initializare buffer pt argumente la apelul functiei
map<string, SymTable*> SymTableHelp::classMap;

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
        //delete c; //sterg tabela scopului de dinainte. mi a zis gemini ca atunci cand vom verifica semantic si vom avea functii s-ar putea sa nu mai vrem sa stergem, de tinut minte
        //am comentat delete ca sa nu aiba table cu clase valori dubioase dupa
    }
}

void SymTableHelp::Clean() {
    ExitScope();
    fisier.close();
}

void SymTableHelp::SetType(string type) {
    currentType = type;
}

string SymTableHelp::GetType(string name){
    if(currentScope){
        return currentScope->getType(name);
    }
    return "eroare";
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

void SymTableHelp::AddCallArg(string type){
    callArgsBuffer.push_back(type);

}

bool SymTableHelp::CheckFunctionCall(string funcName){
    if(!currentScope)
    return false;

    //luam parametri asteptati din definitia functiei
    //functia poate fi definita in scopul parinte deci o cautam urcand recursiv prin getParams din Symtable

    vector<string> expectedParams=currentScope->getParams(funcName);
    
    if(expectedParams.size()!=callArgsBuffer.size())
     {//verificam nr de pramatri daca corespunde
        cout<<"Eroare semantica: Functia "<<funcName<<" asteapta "<<expectedParams.size()<<" argumente in loc de "<<callArgsBuffer.size()<<" argumente primite"<<endl;
        return false;        
    }
    for(int i=0;i<expectedParams.size();i++)
    {
        if(expectedParams[i] != callArgsBuffer[i]){
            cout<<"Eroare semantica la apelul functiei "<<funcName<<". Argumentul "<<(i+1)<<" are tipul incorect ("<<callArgsBuffer[i]<<") in loc de "<<expectedParams[i]<<endl;
        return false;
        }
        
    }
    return true;
}

void SymTableHelp::ClearCallArg(){
    callArgsBuffer.clear();
}

void SymTableHelp::AddClassScope(string className, SymTable* table){
    classMap[className]=table;
}
// aici verificam membrul, obiect->camp
bool SymTableHelp::CheckClassMember(string objectName, string memberName){
    //gasim obiectul
    if(!currentScope->existsId(objectName)){
        cout<<"Eroare: Obiectul "<<objectName<<" nu este definit"<<endl;
        return false;
    }
    //gasim tipul obiectului
    string className=GetType(objectName);

    //cautam table clasei <nume_clasa> in map
    if(classMap.find(className)==classMap.end()){
        cout<<"Eroare: "<<objectName<<" are tipul "<<className<<" care nu este o clasa"<<endl;
        return false;
    }

    SymTable* classTable=classMap[className];

    //cautam membrul camp in table clasei
    if(classTable->existsId(memberName)){
        return true;
    }else{
        cout<<"Eroare: Clasa "<<className<<" nu are membrul "<<memberName<<endl;
        return false;
    }
}

string SymTableHelp::GetClassMemberType(string objectName, string memberName){
    string className=GetType(objectName);
    if(classMap.find(className)!=classMap.end()){
        SymTable* classTable=classMap[className];

        //returnam tipul membrului din tabela clasei, nu din scopul curent
        IdInfo* id=classTable->findId(memberName);
        if(id) return id->type;
    }
    return "eroare";
}

bool SymTableHelp::CheckClassMethodCall(string objectName, string methodName){
    //aflam tipul obiectului pe care se face apelul
    string className=currentScope->getType(objectName);

    if(className=="eroare"){
        cout<<"Eroare semantica: Obiectul"<<objectName<<" nu este declarat"<<endl;
        return false;
    }
    //verificam daca tipul obiectului este o clasa definita de noi
    if (classMap.find(className)==classMap.end()){
        cout<<"Eroare semantica: Variabila "<<objectName<<" are tipul "<<className<<" care nu este o clasa definita "<<endl;
        return false;
    }

    //tablea de simboluri daca avem clasa buna
    SymTable* classTable=classMap[className];
    //cautam metoda in tabela
    IdInfo* methodInfo=classTable->findId(methodName);

    if(methodInfo==NULL){
        cout<<"Eroare semantica: Clasa "<<className<<" nu are metoda "<<methodName<<endl;
        return false;
    }

    //verificam daca simbolul gasit chiar e functie
    if(methodInfo->kind!="functie"){
        cout<<"Eroare semantica: "<<methodName<<" este definita in clasa "<<className<<", dar nu este o functie, ci  "<<methodInfo->kind<<endl;
        return false;
    }

    //verificam nr de parametri
    if(methodInfo->paramTypes.size()!=callArgsBuffer.size()){
        cout<<"Eroare semantica: Numar gresit de parametri pentru metoda "<<methodName<<". A primit "<<callArgsBuffer.size()<<" parametri, se asteapta "<<methodInfo->paramTypes.size()<<endl;
        return false;
    }

    //verificam tipul fiecarui parametru
    for(int i=0;i<methodInfo->paramTypes.size();i++){
        if(methodInfo->paramTypes[i]!=callArgsBuffer[i]){
            cout<<"Eroare semantica: Tipul argumentului de pe pozitia "<<i+1<<" este gresit. Metoda "<<methodName<<" astepta "<<methodInfo->paramTypes[i]<<" si a primit "<<callArgsBuffer[i]<<endl;
        return false;
        }
    }
    return true;
}

bool SymTableHelp::CheckFunctionExists(string name){
    if(currentScope==NULL) return false;

    IdInfo* id=currentScope->findId(name);

    if(id==NULL){
        cout<<"Eroare semantica: Functia "<<name<<" nu este declarata"<<endl;
        return false;
    }

    if(id->kind!="functie"){
    cout<<"Eroare semantica: "<<name<<" este definita ca "<<id->kind<<" si nu poate fi apelata ca functie"<<endl;
        return false;    }

    return true;
}
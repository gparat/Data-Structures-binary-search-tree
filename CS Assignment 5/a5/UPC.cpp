// Name        : UPC.cpp
// Author      : Giovanni Parati
// Date        : 11/20/2020
// implementation for a UPC, contains a key, a value, constructors, setters and getters.
//holds the data that will be put into the BST Nodes

#include <string>
#include "UPC.h"
using namespace std;

UPC::UPC(){
    key=-1;
    value="";
}

UPC::UPC(long long k){
    key=k;
    value="";
}

UPC::UPC(long long k, string v){
    key=k;
    value=v;
}

long long UPC::getKey(){
    return key;
}

string UPC::getVal(){
    return value;
}

void UPC::setKey(int k){
    key=k;
}

void UPC::setVal(string v){
    value=v;
}
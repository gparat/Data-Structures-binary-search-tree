// Name        : app.cpp
// Author      : Giovanni Parati
// Date        : 11/20/2020
// contains main method, buildTree, performSearchBST
// read a file containing UPC codes and descriptions into a BST
// allows user to search for items by code

#include <cstddef>
#include <iostream>
#include <time.h>
//Started code for Assignment5
//You are allowed to add, but not remove statements 

//..
#include <string>
using namespace std;
#include <fstream>
#include "UPC.h"
#include "BST.cpp"

//searches a BST for a specific UPC key
void performSearchBST(BST<UPC>* tree, UPC key){
    printf("%012I64d\n\r",key.getKey());//preserves leading zeroes
    clock_t t, t2;
    t=clock();
    Node<UPC>* n=tree->find(key);
    t2=clock();
    if(n==NULL){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<n->data.getVal()<<endl;
        cout<<"Lookup time: "<<(t2-t)<<" milliseconds"<<endl;
        cout<<endl;
    }
}

//builds a BST by reading a given file line by line
BST<UPC>* buildTree(string fname){
    BST<UPC>* tree=new BST<UPC>();
    ifstream ifile;
    ifile.open(fname);
    string line;
    long long key;
    string value;
    getline(ifile, line);
    while(!ifile.eof()){
        getline(ifile, line);
        key=stoll(line.substr(0,(line.find(','))));
        value=line.substr(line.find(',')+1);
        UPC t(key,value);
        tree->insert(t);
    }
    return tree;
}

int main() {
    const string filename="grocery_upc_database.csv";
    //...
    //cout << "size of long=" << sizeof(long) << endl;
	BST<UPC>* tree = buildTree(filename);  //build binary search tree of UPC objects

	string code;
	cout << "Please enter a UPC code(! to quit): ";
	cin >> code;
    bool isnum;
	while (code != "!") {
        isnum=true;
        for(int i=0; i<code.size(); i++){//checks that input is a valid number
            if(!isdigit(code.at(i))){
                isnum=false;
            }
        }
        if(isnum){
            long long entry = stoll(code); //convert user inputted string to type long int
            UPC key(entry);
            performSearchBST(tree, key);
        }
        else{
            cout<<"invalid input"<<endl;
        }
		cout << "\nPlease enter a UPC code(! to quit): ";
		cin >> code;
	}

	return 0;
} 
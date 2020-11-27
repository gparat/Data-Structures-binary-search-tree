// Name        : BST.h
// Author      : Giovanni Parati
// Date        : 11/20/2020
// h file for BST, written by me

#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class BST{
    Node<T> *root;

public:
    BST();
    
    Node<T>* find(Node<T> *root, T item);
    Node<T>* find(T item);
    void insert(T item);
    void insert(Node<T> *&root, T item);
};
// Name        : BST.cpp
// Author      : Giovanni Parati
// Date        : 11/20/2020
// class for the BST, implements constructor, find, insert.
//derived in part from teacher sample code, modified to use overloading and to return a Node<T>*

#include "BST.h"
using namespace std;

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
Node<T>* BST<T>::find(T item){
    return find(root, item);
}
//recursively finds a specific item by comparison with the left and right, returns the target Node if it is found
//or NULL if it is not found
template <class T>
Node<T>* BST<T>::find(Node<T> *root, T item){
    if (root == NULL)
        return NULL;

    if (root->data.getKey() == item.getKey())
        return root;

    else if (root->data.getKey() < item.getKey())
        return find(root->right, item.getKey());
    else
        return find(root->left, item.getKey());
}

template <class T>
void BST<T>::insert(T item){
    insert(root, item);
}
//inserts a Node into the BST by comparing left and right of exsisting Nodes. uses recursion
template <class T>
void BST<T>::insert(Node<T> *&root, T item){
    if (root == NULL)
    {
        root = new Node<T>(item);
    }
    else if (item.getKey() < root->data.getKey())
        insert(root->left, item);
    else
        insert(root->right, item);
}
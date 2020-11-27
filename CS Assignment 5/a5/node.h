// Name        : node.h
// Author      : Giovanni Parati
// Date        : 11/20/2020
// h file for a simple BST node

#include <cstddef>

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data) : data(data), left(NULL), right(NULL) {}
    bool isLeaf() { return left == NULL && right == NULL; }
    bool isFull() { return left != NULL && right != NULL; }
};
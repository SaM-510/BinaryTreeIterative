//
// Author: Varick Erickson
// Date: 2/18/2021
//

#ifndef TREET_H
#define TREET_H

#include <queue>
using namespace std;

// Used to identify the order you wish to traverse the tree
enum Order {PRE_ORDER, POST_ORDER, IN_ORDER};

template<class T>
class TreeT {
public:
    TreeT();
    ~TreeT();

    void Add(T elem);       // Add element to the tree
    void Remove(T elem);    // Remove element from the tree
    bool Contains(T elem);  // Determines if elem is in the tree


    int Size();     // Number of elements in the tree

    // These are used by the iterator
    void ResetIterator(Order traverseOrder);    // Initializes the Iterator
    T GetNextItem();
private:
    struct Node {
        Node* left;
        Node* right;
        T value;
    };
    Node* root;
    int length;
    queue<T> iterArr;     // queue used for the iterator

    void DestroyTree(Node* node);

    void DeleteNode(Node*& subtree);
    void RemoveHelper(Node*& subtree, T elem);

    void PlacePreOrder(Node* node);
    void PlacePostOrder(Node* node);
    void PlaceInOrder(Node* node);

};


#include "TreeT.cpp"

#endif //TREET_H

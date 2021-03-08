
#include "TreeT.h"


template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {
    DestroyTree(root);
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {
    if (node == nullptr)
        return;

    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}


template<class T>
void TreeT<T>::Add(T elem) {

    Node* newNode = new Node;
    newNode->value = elem;

    if (root == nullptr) {
        root = newNode;
        numNodes++;
        return;
    }

    Node* curr = root;
    while(true) {
        if (elem < curr->value) {
            if (curr->left == nullptr){
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        }
        else if (elem > curr->value) {
            if (curr->right == nullptr){
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
        else {
            delete newNode;
            return;
        }
    }
    numNodes++;
}

template<class T>
void TreeT<T>::Remove(T item) {
    RemoveHelper(root, item);
}

template<class T>
void TreeT<T>::RemoveHelper(Node*& subtree, T item) {

    if (item == subtree->value) {
        DeleteNode(subtree);  // Found the node. Now delete it.
    }
    else if (item < subtree->value) {
        subtree = subtree->left; // go left
    }
    else {
        subtree = subtree->right; // go right
    }
}

template<class T>
void TreeT<T>::DeleteNode(Node *&subtree) {

    T item;
    Node* tempPtr;

    tempPtr = subtree;
    if (subtree->right == NULL && subtree->left == NULL)
    {
        delete tempPtr;
        subtree = NULL;
    }
    else if (subtree->left == NULL)
    {
        subtree = subtree->right;
        delete tempPtr;
    }
    else if (subtree->right == NULL)
    {
        subtree = subtree->left;
        delete tempPtr;
    }
    else {
        GetPredecessor(subtree->left, item);
        subtree->info = item;
        RemoveHelper(subtree->left, item);
    }
}

template<class T>
bool TreeT<T>::Contains(T elem) {
    Node* curr = root;

    while(curr != nullptr) {
        if (elem == curr->value) {
            return true;
        }
        else if (elem < curr->value) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    return false;
}

//template<class T>
//bool TreeT<T>::Contains(T elem) {
//    return ContainsHelper(root, elem);
//}
//
//// Used for recursive version.
//template<class T>
//bool TreeT<T>::ContainsHelper(Node* curr, T elem) {
//
//}

template<class T>
int TreeT<T>::Size() {
    return numNodes;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {
    if (traverseOrder == IN_ORDER)
        PlaceInOrder(root);
    else if (traverseOrder == POST_ORDER)
        PlacePostOrder(root);
    else
        PlacePreOrder(root);
}

template<class T>
T TreeT<T>::GetNextItem() {
    return T();
}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {

}




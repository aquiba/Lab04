/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --bintree.h--
*/

#ifndef BINTREE_H
#define BINTREE
#include "movie.h"

struct Node;
struct Node {
        Inventory* movie;
        Node* left;
        Node* right;
}; // end struct Node

class BinTree {
        friend ostream& operator<<(ostream&, const BinTree&);
        struct Node;

public:
        BinTree(); // default constructor
        BinTree(const BinTree&); // copy constructor
        ~BinTree(); // destructor

        bool insert(Inventory*, const int); // insert into BST
        bool isEmpty() const; // check whether or not tree is empty
        void makeEmpty(); // makes BST empty
        bool retrieve(const Inventory&, Inventory*&) const;
        void retrieveHelper(Node*, const Inventory&, 
                                Inventory*&) const;
        void inOrderDisplay(Node*) const;
        Node* getRoot() const; 

private:
        struct Node {
                Inventory* movie;
                Node* left;
                Node* right;
        }; // end struct Node
        Node *root;

        void inOrderDisplayHelper(Node*) const;
        void destroyTree(Node*&);
}; // end class BinTree
#endif

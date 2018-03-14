#include "bintree.h"

ostream & operator<<(ostream &, const BinTree &){
    // TODO: insert return statement here
}

BinTree::BinTree() : root(NULL) {
}


//Copy Constructor unimplemented.
BinTree::BinTree(const BinTree &){
}

BinTree::~BinTree(){
    makeEmpty();
}

bool BinTree::insert(Inventory *insertMovie, const int copies){
    Node* tempNode = new Node; // Creates copy
    tempNode->movie = insertMovie;
    insertMovie = NULL; // Deletes node to avoid memleaks
    tempNode->left = NULL;
    tempNode->right = NULL;
    if (isEmpty()) root = tempNode; // Sets root to temp node if tree is empty
    else { // Iterative insertion
        Node* current = root; // Sets the start point for the search
        bool inserted = false; // Exit case

        while (!inserted) {
            if (*tempNode->movie == *current->movie) { // Found the same node
                delete tempNode; // Deletes, already inserted
                tempNode = NULL;
                for (int i = 0; i < copies; i++) { //Increase how many copies
                    current->movie->increaseCopies();
                }
                return true;
            }
            else if (*tempNode->movie < *current->movie) { // Searches left for spot
                if (current->left == NULL) { // Found an empty place
                    inserted = true; // Allows the while loop to end
                    current->left = tempNode; // inserts node.
                }
                else { // Continues down left
                    current = current->left;
                }
            }
            else { // Not in any left children.
                if (current->right == NULL) { // Found a place in the right
                                              // Will default to this because
                                              // the logic above dictates
                                              // That if it's not more, 
                                              // and if it hasnt been found
                                              // it will always go right.
                    inserted = true;
                    current->right = tempNode;
                }
                else { // Continues down right
                    current = current->right;
                }
            }
        }
    }
    return true; // Insertion completed.
}

bool BinTree::isEmpty() const{
    return (root == NULL);
} //end isEmpty

void BinTree::makeEmpty(){
    destroyTree(root);
}

bool BinTree::retrieve(const Inventory &find, Inventory *&found) const{
    retrieveHelper(root, find, found);
    if (found != NULL) { //Check is targetFound was changed
        return true;
    } else {
        return false; //If targetFound was not found then return false
    }
}

void BinTree::retrieveHelper(Node *ptr, const Inventory &find, Inventory *&found) const{
    if (ptr == NULL) found = NULL; //Not Found
    else if (find == *ptr->movie) { //Item Found
        found = ptr->movie; //returns reference to the item
    }
    else if (find < *ptr->movie) { //Check left
        retrieveHelper(ptr->left, find, found); // searches left
    }
    else { //Checks right
        retrieveHelper(ptr->right, find, found); // searches right
    }
}

void BinTree::inOrderDisplay(Node *ptr) const {
    inOrderDisplayHelper(ptr);
}

void BinTree::inOrderDisplayHelper(Node *ptr) const {
    if (ptr != NULL) { // Traverse inorder and print data
        inOrderDisplayHelper(ptr->left); // recurses through leftmost child
        ptr->movie->displayHeader();
        inOrderDisplayHelper(ptr->right); // recurses throughout rightmost child
    }
}

BinTree::Node * BinTree::getRoot() const {
    return root;
}


void BinTree::destroyTree(Node *& current){
    if (current != NULL) { // Checks to see if we should delete
        destroyTree(current->left); // Checks left
        destroyTree(current->right); // Checks right

        delete current->movie; // deletes the node we're on
        current->movie = NULL; // deletes movie.
    } //end if
    delete current; // Deletes the root
    current = NULL; // Sets root to null
} //end destroyTree

/**
*
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --borrow.cpp--
*/

#include "borrow.h"

// ---------- Borrow() ----------
// This is the default Borrow() constructor, and it sets
// the Transaction type string to "Borrow".
Borrow::Borrow() : Transaction() {
        this->transaction = "Borrow";
} // end default constructor Borrow()

// ---------- Borrow() ----------
// This is the copy constructor Borrow() and it takes
// another Borrow object as input to create a deep copy of
// a borrow transaction.
Borrow::Borrow(const Borrow& rhs) {
        this->transaction = rhs.transaction;
        this->media = rhs.media;
        this->item = rhs.item;
} // end copy constructor Borrow()

// ---------- ~Borrow() ----------
// This is the destructor ~Borrow() and it destroys the
// dynamically allocated memory.
Borrow::~Borrow() {

} // end destructor ~Borrow()

// ---------- setData() ----------
// This is the setData() function and it sets the data
// of an object that is being Borrowed. After an item
// is borrowed, the number of copies of this item is 
// decreased by one.
bool Borrow::setData(string setMedia, Inventory* setItem,
                        Customer* setCustomer) {
        if( setItem != NULL ) { // if item we are setting is not null
                this->media = setMedia; // set media type
                this->item = setItem; // set item

                if( media != "" ) { // if media type is not empty
                        // decrease the number of copies of this item
                        this->item->decreaseCopies();
                } // end if
        } // end if
        return true;
} // end function setData()

// ---------- display() ----------
// This is the display() function, and it displays the
// media and transaction type of a Borrow object.
void Borrow::display() const {
        cout << this->media << " " << this->transaction << " ";
} // end function display()

// ---------- create() ----------
// This is the create() function, and it creates a new
// Borrow object for the Factory class to use.
Transaction* Transaction::create() {
        return new Borrow();
} // end function create()

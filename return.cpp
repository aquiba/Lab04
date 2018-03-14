/**
*
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --return.cpp--
*/

#include "return.h"

// ---------- Return() ----------
// This is the default Return() constructor, and it sets
// the Transaction type string to "Return".
Return::Return() : Transaction() {
        this->transaction = "Return";
} // end default constructor Return()

// ---------- Return() ----------
// This is the copy constructor Return() and it takes
// another Return object as input to create a deep copy of
// a return transaction.
Return::Return(const Return& rhs) {
        this->transaction = rhs.transaction;
        this->media = rhs.media;
        this->item = rhs.item;
} // end copy constructor Return()

// ---------- ~Return() ----------
// This is the destructor ~Return() and it destroys the
// dynamically allocated memory.
Return::~Return() {

} // end destructor ~Return()

// ---------- setData() ----------
// This is the setData() function and it sets the data
// of an object that is being Returned. After an item
// is returned, the number of copies of this item is 
// increased  by one.
bool Return::setData(string setMedia, Inventory* setItem,
                        Customer* setCustomer) {
        if( setItem != NULL ) { // if item we are setting is not null
                this->media = setMedia; // set media type
                this->item = setItem; // set item

                if( media != "" ) { // if media type is not empty
                        // increase the number of copies of this item
                        this->item->increaseCopies();
                } // end if
        } // end if
        return true;
} // end function setData()

// ---------- display() ----------
// This is the display() function, and it displays the
// media and transaction type of a Return object.
void Return::display() const {
        cout << this->media << " " << this->transaction << " ";
} // end function display()

// ---------- create() ----------
// This is the create() function, and it creates a new
// Return object for the Factory class to use.
Transaction* Transaction::create() {
        return new Return();
} // end function create()

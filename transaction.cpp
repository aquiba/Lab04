/**
* 
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --transaction.cpp--
*/

#include "transaction.h"

// ---------- Transaction() ----------
// This is the default constructor Transaction() and it initializes
// the data members of the transaction to their default values.
Transaction::Transaction() {
        this->item = NULL;
        this->media = "";
        this->transaction = "Transaction";
} // end default constructor Transaction()

// ---------- Transaction() ----------
// This is the copy constructor Transaction() and it takes 
// another Transaction object as input to create a deep copy of 
// a transaction.
Transaction::Transaction(const Transaction& rhs) {
        this->item = rhs.item;
        this->media = rhs.media;
        this->transaction = rhs.transaction;
} // end copy constructor Transaction()

// ---------- ~Transaction() ----------
// This is the destructor ~Transaction() and it destroys the
// dynamically allocated memory.
Transaction::~Transaction() {

} // end destructor ~Transaction()

// ---------- setData() ----------
// This is the setData() function, and it sets the data of a 
// transaction up for a Customer partaking in the transaction.
bool Transaction::setData(string setMedia, Inventory* setItem, 
                        Customer* setCustomer) {
        this->media = setMedia;
        this->item = setItem;
        return true;
} // end function setData()

// ---------- display() ----------
// This is the display() function, and it displays the
// media and transaction type of a Transaction object.
void Transaction::display() const {
        cout << media << " " << transaction << ": ";
} // end function display()

// ---------- create() ----------
// This is the create() function, and it creates a new 
// Transaction object for the Factory class to use.
Transaction* Transaction::create() {
        return new Transaction();
} // end function create()

// ---------- getMediaType() ----------
// This is the getMediaType() function, and it just
// returns the media type of the Transaction.
string Transaction::getMediaType() {
        return this->media;
} // end function getMediaType()

// ---------- getTransactionType() ----------
// This is the getTransactionType() function, and it
// just returns the transaction type of the Transaction.
string Transaction::getTransactionType() {
        return this->transaction;
} // end function getTransactionType()

// ---------- getItem() ----------
// This is the getItem() function, and it just
// returns the item of the Transaction.
Inventory* Transaction::getItem() const {
        return this->item;
} // end function getItem()

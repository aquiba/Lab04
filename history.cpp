
/**
*
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project -history.cpp--
*/

#include "history.h"
#include "customer.h"

// ---------- History() ----------
// This is the default History() constructor, and it sets
// the Transaction type string to "History".
History::History() : Transaction() {
        this->transaction = "History";
} // end default constructor History()

// ---------- History() ----------
// This is the copy constructor History() and it takes
// another History object as input to create a deep copy of
// a history transaction.
History::History(const History& rhs) {
        this->transaction = rhs.transaction;
        this->media = rhs.media;
        this->item = rhs.item;
} // end copy constructor History()

// ---------- ~History() ----------
// This is the destructor ~History() and it destroys the
// dynamically allocated memory.
History::~History() {

} // end destructor ~History()

// ---------- setData() ----------
// This is the setData() function, and it simply displays
// the customer history.
bool History::setData(string setMedia, Inventory* setItem,
                        Customer* setCustomer) {
        // display customer history
        setCustomer->displayCustomerHistory();
        return false;
} // end function setData()

// ---------- create() ----------
// This is the create() function, and it creates a new
// Return object for the Factory class to use.
Transaction* History::create() {
        return new History();
} // end function create()

/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --borrow.h--
*/

#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"

class Customer;

class Borrow : public Transaction {
public:
        Borrow(); // constructor
        Borrow(const Borrow&); // copy constructor
        ~Borrow(); // destructor

        virtual bool setData(string, Inventory*, Customer*);
        virtual void display() const;
        virtual Transaction* create();
}; // end class Borrow

#endif

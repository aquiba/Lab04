/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --return.h--
*/

#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Customer;

class Return : public Transaction {
public:
        Return(); // constructor
        Return(const Return&); // copy constructor
        ~Return(); // destructor

        virtual bool setData(string, Inventory*, Customer*);
        virtual void display() const;
        virtual Transaction* create();
}; // end class Return

#endif

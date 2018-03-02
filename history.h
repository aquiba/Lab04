
/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project -history.h--
*/

#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class Customer;

class History : public Transaction {
public:
        History(); // constructor
        History(const History&); // copy constructor
        ~History(); // destructor

        virtual bool setData(string, Inventory*, Customer*);
        virtual Transaction* create();
}; // end class History

#endif

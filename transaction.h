/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --transaction.h--
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "movie.h"

class Customer;

class Transaction {
public:
        Transaction(); // constructor
        Transaction(const Transaction&); // copy constructor
        virtual ~Transaction(); // destructor

        virtual bool setData(string, Inventory*, Customer*);
        virtual void display();

        virtual Transaction* create();

        string getMediaType(); // get media type
        string getTransactionType(); // get transaction type
        Inventory* getItem() const; // get item in inventory

protected:
        string transaction; // string for transaction type
        string media; // string for media type
        Inventory* item; // inventory pointer
}; // end class Transaction

#endif

/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --customer.h--
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include "transaction.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
public:
        Customer(); // end constructor
        Customer(istream&); // end constructor from file
        Customer(const Customer&); // end copy constructor
        virtual ~Customer(); // end destructor

        void setData(istream&);
        void displayCustomerHistory() const;
        void addTransaction(Transaction);
        virtual void display() const;
        int getCustomerID() const;
        string getFirstName() const;
        string getLastName() const;

        // operators!
        virtual bool operator==(const Customer&) const;
        virtual bool operator!=(const Customer&) const;

private:
        int id;
        string firstName;
        string lastName;
        vector<Transaction> transactionHistory;
}; // end class Customer

#endif

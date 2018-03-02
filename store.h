/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --store.h--
*/

#ifndef STORE_H
#define STORE_H
#include "customer.h"
#include "factory.h"
#include "bintree.h"

#include <fstream>
#include <vector>

#define MAXCUSTOMERS 10000
#define MAXINVENTORY 53

using namespace std;

class Store {
public:
        Store(); // end constructor
        Store(string); // end string constructor
        Store(const Store&); // end copy constructor
        ~Store(); // end destructor

        // read in through files!
        void createCustomers(istream&);
        void createInventory(istream&);
        void processTransactions(istream&);

        // display functions!
        void display();
        void displayInventory();
        void displayCustomers();
        
        // accessors!
        bool lookUpCustomer(int) const;
        string getBusinessName() const;
        Customer getCustomer(const int) const;

private:
        Customer customers[MAXCUSTOMERS];
        BinTree inventory[MAXINVENTORY];
        vector<Transaction> transactionHistory;
        Factory factory;
        string name;
}; // end class Store

#endif

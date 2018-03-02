/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --inventory.h--
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Inventory {
public:
        Inventory(); // constructor
        Inventory(const Inventory&); // copy constructor
        virtual ~Inventory(); // destructor

        // sets data of inventory items
        virtual void setData(istream&) = 0;
        virtual void setData2(istream&) = 0;

        // displays data and information of all data
        virtual void display() const = 0;
        virtual void displayHeader() const = 0;

        // return item in inventory
        virtual string getItem() const = 0;

        void setMaxCopies(const int);
        void increaseCopies();
        void decreaseCopies();
        
        // shows how much is in stock of a particular inventory item
        int getStockIn(); // gets how many copies are in stock
        int getStockOut(); // gets how many copies have been borrowed

        virtual Inventory* create() = 0;

        // operators!
        virtual bool operator==(const Inventory&) const = 0;
        virtual bool operator<(const Inventory&) const = 0;

private:
        int stockNumber; // how much in stock
        int maxStock; // max inventory stock
}; // end class Inventory

#endif

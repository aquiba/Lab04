/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --factory.h--
*/

#ifndef FACTORY_H
#define FACTORY_H
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

#define MAXSIZE 26
#define CLASSIC 2
#define DRAMA 3
#define COMEDY 5
#define BORROW 1
#define HISTORY 7
#define RETURN 17

using namespace std;

class Movie;
class Transaction;

class Factory {
public:
        Factory(); // constructor
        ~Factory(); // destructor

        Inventory* createMovie(char, istream&);
        Transaction* createTransaction(char, istream&);
        int convertToSubscript(char);
        string getMediaType(char);

private:
        Inventory* storeInventory[MAXSIZE];
        Transaction* transactionInventory[MAXSIZE];
        string mediaType[MAXSIZE];

        int hash(char) const; // hash table!
        void initInventory();
}; // end class Factory

#endif

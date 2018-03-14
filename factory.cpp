/**
*
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --factory.cpp--
*/

#include "factory.h"

// ---------- Factory() ----------
// This is the default constructor Factory() and it
// sets up arrays for Store Inventory and Transaction Inventory
// to their default array values.
Factory::Factory() {
        initInventory(); // initialize inventory!

        // Create Inventory for all Movie Genres
        this->storeInventory[CLASSIC] = new Classic();
        this->storeInventory[DRAMA] = new Drama();
        this->storeInventory[COMEDY] = new Comedy();

        // Create Inventory for all Transaction Types
        this->transactionInventory[BORROW] = new Borrow();
        this->transactionInventory[HISTORY] = new History();
        this->transactionInventory[RETURN] = new Return();

        this->mediaType[DRAMA] = "DVD";
} // end default constructor Factory()

// ---------- initInventory() ----------
// This is the function initInventory() and it is used
// in the default constructor Factory(). It initializes all
// arrays to their default states.
void Factory::initInventory() {
        // Create a max-size factory
        for( int i = 0; i < MAXSIZE; i++ ) {
                // Create empty store inventory
                this->storeInventory[i] = NULL;

                // Create empty transaction list
                this->transactionInventory[i] = NULL;

                // Create empty media type list
                this->mediaType[i] = "";
        } // end for
} // end function initInventory()

// ---------- ~Factory() ----------
// This is the destructor ~Factory() and it destroys the dynamically
// allocated storeInventory[] and transactionInventory[] arrays.
Factory::~Factory() {
        for( int i = 0; i < MAXSIZE; i++ ) {
                if( storeInventory[i] != NULL ) {
                        delete storeInventory[i];
                        storeInventory[i] = NULL;
                } // end if

                if( transactionInventory[i] != NULL ) {
                        delete transactionInventory[i];
                        transactionInventory[i] = NULL;
                } // end if
        } // end for
} // end destructor ~Factory()

// ---------- hash() ----------
// This is the function Hash() and it computes
// the integer value of a specific character.
int Factory::hash(char parse) const {
        if( parse < 'a' ) {
                return parse - 'A';
        } else {
                return 0;
        } // end if
} // end function hash()

// ---------- convertToSubscript() ----------
// This is the function convertToSubscipt() and it returns the
// hash of a character that is passed in.
int Factory::convertToSubscript(char convert) {
        // use hash() function to convert to subscript!
        return hash(convert);
} // end function convertToSubscript()

// ---------- createMovie() ----------
// This is the function createMovie() and it creates a movie
// object in a location of the array depending on the 
// hash/subscript result.
Inventory* Factory::createMovie(char parse, istream& infile) {
        string temp = ""; // empty string

        // hash for insertion index
        int subscript = hash(parse);

        if( storeInventory[subscript] == NULL ) {
                getLine(infile, temp, '\n');
                return NULL;
        } else {
                return this->storeInventory[subscript]->create();
        } // end if
} // end function createMovie()

// ---------- createTransaction() ----------
// This is the function createTransaction() and it creates a
// transaction object in a location of the array depending on the
// hash/subscript result.
Transaction* Factory::createTransaction(char parse, istream& infile) {
        string temp = ""; // empty string

        // hash for insertion index
        int subscript = hash(parse);

        if( transactionInventory[subscript] == NULL ) {
                getLine(infile, temp, '\n');
                return NULL;
        } else {
                return this->transactionInventory[subscript]->create();
        } // end if
} // end function createTransaction()

// ---------- getMediaType() ----------
// This is the function getMediaType() and it returns the
// type of media based on the hashed character that is
// passed in.
string Factory::getMediaType(char parse) {
        return mediaType[ hash(parse) ];
} // end function getMediaType()

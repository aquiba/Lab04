/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --comedy.h--
*/

#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"

class Comedy : public Movie {
public:
        Comedy(); // constructor
        Comedy(const Comedy&); // copy constructor
        ~Comedy(); // destructor

        // set data for comedy movies
        virtual void setData(istream&);
        virtual void setData2(istream&);

        // displays comedy movies and all their information
        virtual void display() const;
        virtual void displayHeader() const;

        virtual Inventory* create();

        // operators!
        virtual bool operator==(const Inventory&) const;
        virtual bool operator<(const Inventory&) const;

private:
        const string genre; // genre of movie is comedy
}; // end class Comedy

#endif

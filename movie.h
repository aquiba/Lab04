/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --movie.h--
*/

#ifndef MOVIE_H
#define MOVIE_H
#include "inventory.h"

using namespace std;

class Movie : public Inventory {
public:
        Movie(); // constructor
        Movie(const Movie&); // copy constructor
        ~Movie(); // destructor

        // displays movies plus all information!
        virtual void display() const;
        virtual void displayHeader() const = 0;

        virtual void setData(istream&);
        virtual void setData2(istream&) = 0;

        virtual string getItem() const; // return item in inventory
        string getDirector(); // get movie director
        string getTitle(); // get movie title
        int getYear(); // get year movie was published

        virtual Inventory* create() = 0; // create inventory

        // operators!
        virtual bool operator==(const Inventory&) const = 0;
        virtual bool operator<(const Inventory&) const = 0;

protected:
        string title; // movie title
        string director; // name of director
        int year; // year movie was published
}; // end class Movie

#endif

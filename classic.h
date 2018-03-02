/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --classic.h--
*/

#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"

#include <string>

class Classic : public Movie {
public:
        Classic(); // constructor
        Classic(const Classic&); // copy constructor
        ~Classic(); // destructor

        // sets data for classic movies
        void setData(istream&);
        virtual void setData2(istream&);

        // displays classic movies and all their information
        void display() const;
        virtual void displayHeader() const;

        virtual Inventory* create();

        // operators!
        virtual bool operator==(const Inventory&) const;
        virtual bool operator<(const Inventory&) const;

private:
        string actorFirstName; // actor's first name
        string actorLastName; // actor's last name
        int month; 
        const string genre; // genre of movie is classic
}; // end class Classic

#endif

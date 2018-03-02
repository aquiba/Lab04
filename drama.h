/**
*
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --drama.h--
*/

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
        Drama(); // constructor
        Drama(const Drama&); // copy constructor
        ~Drama(); // destructor

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
        const string genre; // genre of movie is drama
}; // end class Comedy

#endif

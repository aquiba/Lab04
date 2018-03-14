#include "movie.h"

Movie::Movie() : Inventory(), title(""), director(""), year(0){}

Movie::Movie(const Movie &copy) {
    title = copy.title;
    director = copy.director;
    year = copy.year;
}

Movie::~Movie() {
}

void Movie::display() const {
    cout << title << " " << director << " " << year << endl;
}

void Movie::displayHeader() const {
    cout << "  ****** MOVIE ITEM ***** " << endl;
}

void Movie::setData(istream &infile){
    infile.get();
    getline(infile, director, ',');

    infile.get();
    getline(infile, title, ',');

    infile.get();
    infile >> year;

}

string Movie::getItem() const{
    return title;
}

string Movie::getDirector(){
    return director;
}

string Movie::getTitle(){
    return title;
}

int Movie::getYear(){
    return year;
}

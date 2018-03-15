#include "comedy.h"

Comedy::Comedy() : Movie(), genre("F") {
}

Comedy::Comedy(const Comedy &copy) : genre("F") {
    title = copy.title;
    year = copy.year;
    director = copy.director;
}

Comedy::~Comedy() {}

void Comedy::setData(istream &infile) {
    infile.get();
    getline(infile, director, ',');
    if (director.size() > 18) {
        title.resize(18);
    }
    infile.get();
    getline(infile, title, ',');
    if (title.size() > 22) {
        title.resize(22);
    }
    infile.get();
    infile >> year;
}

void Comedy::setData2(istream &infile) {
    infile.get();
    getline(infile, title, ',');
    infile >> year;
}

void Comedy::display() const {
    cout << genre << " " << left << " " << setw(22);
    cout << " " << director << " " << year;
}

void Comedy::displayHeader() const {
    cout << "GENRE | STOCK | DIRECTOR" << setw(16) << "| MM YYYY | " << endl;
    cout << "---------------------------------------------------------------------";
    cout << endl;
}

bool Comedy::operator==(const Inventory &compare) const {
    const Comedy& temp = (Comedy&)compare;
    return (temp.year == year && director == temp.director);
}

bool Comedy::operator<(const Inventory &compare) const {
    const Comedy& temp = (Comedy&)compare;

    if (title < temp.title) return true;
    else if (title == temp.title)
        return (year < temp.year);
}

Inventory * Comedy::create() {
    return new Comedy();
}
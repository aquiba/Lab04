#include "Drama.h"

Drama::Drama() : Movie(), genre("D") {
}

Drama::Drama(const Drama &copy) : genre("D") {
    title = copy.title;
    year = copy.year;
    director = copy.director;
}

Drama::~Drama() {}

void Drama::setData(istream &infile) {
    infile.get();
    getline(infile, director, ',');
    if (director.size() > 18) {
        title.resize(18);
    }
    infile.get();
    if (title.size() > 22) {
        title.resize(22);
    }
    infile.get();
    infile >> year;
}

void Drama::setData2(istream &infile) {
    infile.get();
    getline(infile, title, ',');
    infile >> year;
}

void Drama::display() const {
    cout << genre << " " << left << " " << setw(22);
    cout << " " << director << " " << year;
}

void Drama::displayHeader() const {
    cout << "GENRE | STOCK | DIRECTOR" << setw(16) << "| MM YYYY | " << endl;
    cout << "---------------------------------------------------------------------";
    cout << endl;
}

bool Drama::operator==(const Inventory &compare) const {
    const Drama& temp = (Drama&)compare;
    return (temp.year == year && director == temp.director);
}

bool Drama::operator<(const Inventory &compare) const {
    const Drama& temp = (Drama&)compare;

    if (title < temp.title) return true;
    else if (title == temp.title)
        return (year < temp.year);
}

Inventory * Drama::create() {
    return new Drama();
}
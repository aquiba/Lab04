#include "classic.h"

Classic::Classic() : genre("C") {
    actorFirstName = "";
    actorLastName = "";
    month = 0;
    year = 0;
}

Classic::Classic(const Classic &copy) : genre("C") {
    actorFirstName = copy.actorFirstName;
    actorLastName = copy.actorLastName;
    month = copy.month;
    year = copy.year;
}

Classic::~Classic() {}

void Classic::setData(istream &infile) {
    infile.get();
    getline(infile, director, ',');
    if (director.size() > 18) {
        title.resize(18);
    }
    infile.get();
    getline(infile, director, ',');
    if (title.size() > 22) {
        title.resize(22);
    }
    infile.get();
    infile >> actorFirstName >> actorLastName;
    infile >> month >> year;

}

void Classic::setData2(istream &infile) {
    infile >> month;
    infile >> year;
    infile >> actorFirstName;
    infile >> actorLastName;
}

void Classic::display() const {
    cout << genre << " " << left << " ";
    cout << " " << director << " " << title << " " << month << " ";
    cout << year << " " << actorFirstName << " " << actorLastName << endl;
    cout << endl;
}

void Classic::displayHeader() const {
    cout << "GENRE | STOCK | DIRECTOR" << setw(16) << "| ACTOR | MM YYYY | " << endl;
    cout << "---------------------------------------------------------------------";
    cout << endl;
}

bool Classic::operator==(const Inventory &compare) const {
    const Classic& temp = (Classic&)compare;
    return (temp.year == year && temp.month == month &&
        temp.actorFirstName == actorFirstName &&
        actorLastName == temp.actorLastName);
}

bool Classic::operator<(const Inventory &compare) const {
    const Classic& temp = (Classic&)compare;

    if (year < temp.year) return true;
    else if (year == temp.year) {
        if (actorFirstName < temp.actorFirstName) return true;
        else if (actorFirstName == temp.actorFirstName)
            return (actorLastName < temp.actorLastName);
        else return false;
    }
    else return false;
}

Inventory * Classic::create() {
    return new Classic();
}

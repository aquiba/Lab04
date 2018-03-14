/**
*
* Professor Min Chen
* Date Created: 14 March 2018
* Last Modified: 14 March 2018
* CSS343B
*
* Lab 4: Final Project --customer.cpp--
*/

// ---------- Customer() ----------
// This is the default constructor Customer(), and
// sets a Customer object to their default empty values.
Customer::Customer() {
        this->id = -1;
        this->firstName = "";
        this->lastName = "";
        this->transactionHistory.reserve(10);
} // end default constructor Customer()

// ---------- Customer() ----------
// This is the input file constructor Customer(), and
// it sets a Customer objects values based on the data
// in the data passed in through a file.
Customer::Customer(istream& infile) {
        setData(infile);
} // end constructor from file Customer()

// ---------- Customer() ----------
// This is the copy constructor Customer() and it takes
// another Customer object as input to create a deep copy.
Customer::Customer(const Customer& rhs) {
        this->id = rhs.id;
        this->firstName = rhs.firstName;
        this->lastName = rhs.lastName;
} // end copy constructor Customer()

// ---------- ~Customer() ----------
// This is the destructor ~Customer() and it destros the
// dynamically allocated array.
Customer::~Customer() {
        for( int i = 0; i < (int)transactionHistory.size(); i++ ) {
                delete transactionHistory[i];
        } // end for
} // end destructor ~Customer()

// ---------- setData() -----------
// This is the function setData(), and it sets a 
// Customer objects values based on data passed
// in through istream/file.
// Format in file goes by ID, Last Name, Firstname.
void Customer::setData(istream& infile) {
        infile >> id; // read in id first
        
        // if we have reached the end of the file
        if( infile.eof() ) {
                return; // stop reading
        } // end if

        infile.get(); // get next string
        infile >> lastName; // read in last name
        
        infile.get(); // get next string
        infile >> firstName; // read in first name
} // end function setData()

// ---------- displayCustomerHistory() ----------
// This is the function displayCustomerHistory() and it
// prints out the Transaction history of a Customer.
void Customer::displayCustomerHistory() const {
        cout << " Customer: " << this->id << " " << this->lastName <<
                ", " << this->firstName << endl;

        // int representing size of transaction history vector
        int histSize = this->transactionHistory.size();

        if( histSize > 0 ) { // if history size greater than 0
                // loop through and display all of transaction history vector
                for( int i = 0; i < histSize < i++ ) {
                        this->transactionHistory[i].display();
                        this->transactionHistory[i].getItem()->display();
                } // end for
                cout << endl;
        } else { // if history size is 0
                cout << "This customer has no transactions." << endl;
        } // end if
        cout << endl;
} // end function displayCustomerHistory()

// ---------- addTransaction() ----------
// This is the function addTransaction() and it adds a 
// Transaction to the Transaction history of a Customer.
void Customer::addTransaction(Transaction transaction) {
        this->transactionHistory.push_back(transaction;
} // end function addTransaction()

// ---------- display() ----------
// This is the function display() and it displays
// the Customer object as well as the Transaction history.
void Customer::display() const {
        displayCustomerHistory();
} // end function display()

// ---------- getCustomerID() ----------
// This is the function getCustomerID() and it simply
// returns a Customer's ID number.
int Customer::getCustomerID() const {
        return this->id;
} // end function getCustomerID()

// ---------- getFirstName() ----------
// This is the function getFirstName() and it simply
// returns a Customer's first name.
string Customer::getFirstName() const {
        return this->firstName;
} // end function getFirstName()

// ---------- getLastName() ----------
// This is the function getLastName() and it simply
// returns a Customer's last name.
string Customer::getLastName() const {
        return this->lastName;
} // end function getLastName()

// ---------- operator== ----------
// This is the function for overloaded operator== and it checks
// to see if one Customer is equal to another Customer.
// If yes, returns true. If no, returns false.
// Two customers are the same if they have the same ID.
bool Customer::operator==(const Customer& rhs) const {
        return ( this->id == rhs.id );
} // end function operator==

// ---------- operator!= ----------
// This is the function for overloaded operator!= and it checks
// to see if one Customer is not equal to another Customer.
// If yes, returns false. If no, returns true.
// Two customers are the same if they have the same ID.
bool Customer::operator!=(const Customer& rhs) const {
        return !( this->id == rhs.id );
} // end function operator!=

#include "store.h"

Store::Store() : name("") {}

Store::Store(string name) : name(name){}

Store::Store(const Store& copy) {

}

Store::~Store() {

}

void Store::createCustomers(istream& infile) {
    for (;;) {
        Customer* tempCustomer = new Customer();
        tempCustomer->setData(infile);
        if (infile.eof()) {
            delete tempCustomer;
            tempCustomer = NULL;
            break;
        }
        customers[tempCustomer->getCustomerID()] = *tempCustomer;
        delete tempCustomer;
        tempCustomer = NULL;
    }
}

void Store::createInventory(istream& infile) {
    //creates inventory from inventory textfile
    
    char ch = ' ';
    for (;;) {
        
        infile >> ch;

        if (infile.eof()) break;

        Inventory * addedMovie = factory.createMovie(ch, infile);

        if (addedMovie != NULL) {
            addedMovie->setData(infile);

            bool inserted = inventory[factory.convertToSubscript(ch)]
                .insert(addedMovie, 10);

            if (!inserted) {
                delete addedMovie;
                //addedMovie = NULL;
                cout << "Not Inserted" << endl;
            }//end if not inserted
        }//end if
        addedMovie = NULL;
        delete addedMovie;
    }//end for
}//end createInventory
void Store::processTransactions(istream& infile){
    char actCh = ' ';
    char movCh = ' ';
    char medCh = ' ';
    int custID = 0;
    bool found = false;
    string mediaType = "";
    char EOL = '\n';
    Inventory * itemLoc = NULL;
    Customer * tempCust = NULL;
    Inventory *  tempItem = NULL;

    for (;;) {
        infile >> actCh;
        if (infile.eof()) break; //check for end of file

        if (actCh == 'S') {
            displayInventory();
            actCh = ' ';
        }
        else if (infile.get() == EOL)
            actCh = ' ';
        else {
            Transaction * procTran = factory
                .createTransaction(actCh, infile);

            if (procTran != NULL) { //no action code
                infile >> custID;

                if (infile.eof()) break;

                if (lookUpCustomer(custID)) { //customer exists
                    tempCust = &customers[custID];

                    bool isHistory = procTran->
                        setData(mediaType, itemLoc, tempCust);

                    if (infile.get() != EOL && isHistory) {
                        //not EOL or is history

                        infile >> medCh;

                        mediaType = factory.getMediaType(medCh);


                        if (mediaType != "") {  //movie genre

                            infile >> movCh;

                            tempItem = factory.createMovie(movCh, infile);

                            if (tempItem != NULL) {
                                tempItem->setData2(infile);

                                found = inventory[factory.
                                    convertToSubscript(movCh)].
                                    retrieve(*tempItem, itemLoc);

                                if (found == false)	//if movie not found
                                {
                                    cout << "ERROR: Invalid Movie Request!"
                                        << tempItem->getItem() << endl;
                                }//end if
                                delete tempItem;
                                tempItem = NULL;

                                bool found2 = procTran->
                                    setData(mediaType, itemLoc, tempCust);

                                if ((found && found2) && mediaType != "") {
                                    customers[custID]
                                        .addTransaction(*procTran);

                                }
                                delete procTran;
                                procTran = NULL;
                            }
                            else {
                                cout << "ERROR: " << movCh
                                    << " not Found!" << endl;

                                if (procTran != NULL)
                                    delete procTran;
                                procTran = NULL;
                            }//end if

                            string temp;
                            getline(infile, temp, EOL);
                            delete tempItem;
                            tempItem = NULL;

                        }
                        else {
                            string temp;
                            getline(infile, temp, EOL);

                            cout << "ERROR: Invalid Code " << medCh << endl;

                            if (procTran != NULL)
                                delete procTran;
                            procTran = NULL;
                        }//end if not media type
                    }
                    else {
                        if (procTran != NULL)
                            delete procTran;
                        procTran = NULL;
                    }//end if not EOL and isHistory
                }
                else {
                    cout << "Error: Invalid Customer ID " << custID << endl;

                    if (procTran != NULL)
                        delete procTran;
                    procTran = NULL;

                    string temp;
                    getline(infile, temp, EOL);
                }//end if customer exists
            }
            else {
                cout << "ERROR: Invalid Action type " << actCh << endl;

                if (procTran != NULL)
                    delete procTran;
                procTran = NULL;
            }//end if no action code
        }//end process infile if

        found = false;
        custID = 0;
        itemLoc = NULL;
        tempCust = NULL;
        tempItem = NULL;
    }//end for
}
void Store::display() {
    displayCustomers();
    displayInventory();
}

void Store::displayCustomers() {
    for (int i = 0; i < MAXCUSTOMERS; i++) {
        if (lookUpCustomer(i)) {
            getCustomer(i).display();
        }//end if
    }//end for
}
void Store::displayInventory() {
    if (name != "") {
        cout
            << "--------------------------------------------------------------"
            << endl;
        cout << "Inventory for " << name << endl;
        cout
            << "--------------------------------------------------------------"
            << endl;
    }//end if

    for (int i = 0; i < MAXINVENTORY; i++) {
        if (!inventory[i].isEmpty()) {

            inventory[i].inOrderDisplay(inventory[i].getRoot());
            cout << endl;
        }//end if
    }//end for
}
bool Store::lookUpCustomer(int id) const {
    if (customers[id].getCustomerID() == -1) {
        return false;
    }
    else
        return true;
}
string Store::getBusinessName() const {
    return name;
}
Customer Store::getCustomer(const int id) const {
    return customers[id];
}

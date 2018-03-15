/**
* 
* Professor Min Chen
* Date Created: 28 February 2018
* Last Modified: 28 February 2018
* CSS343B
*
* Lab 4: Final Project --main.cpp--
*/

#include "store.h"
using namespace std;

// ---------- main() ----------
// This is the main function and it runs our program
int main() {
        Store manager("FLIXBOX: Movie Rentals!");
        ifstream customers("data4customers.txt");
        ifstream movieDatabase("data4movies.txt");
        ifstream transactions("data4commands.txt");

        // if any of the text files are not found
        if( (!manager) || (!customers) || (!transactions) ) {
                cout << "File not found." << endl;
                getchar();
                return 1;
        } // end if

        manager.createCustomers(customers);
        manager.createInventory(movieDatabase);
        manager.processTransactions(transactions);

        return 0;
} // end function main()

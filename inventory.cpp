#include "inventory.h"

Inventory::Inventory() : stockNumber(-1), maxStock(0){} //end constructor

Inventory::Inventory(const Inventory& copy) {} //end copy constructor

Inventory::~Inventory() {} //end destructor

void Inventory::setMaxCopies(const int max) {
	maxStock = max;

	if (stockNumber < 0) stockNumber = max;
}//end setMaxCopies


void Inventory::increaseCopies() {
	if (stockNumber != maxStock) stockNumber++;
}//end increaseCopies

void Inventory::decreaseCopies() {
	if (stockNumber != 0) stockNumber--;
}//end decreaseCopies


int Inventory::getStockIn() { 
	return stockNumber; 
}//end getAmountIn


int Inventory::getStockOut() { 
	return maxStock - stockNumber; 
}//end getAmountOut
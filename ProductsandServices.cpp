/************************************************************************
Programming Project #3 -- Team Project for  C++ Client Database System Exp
ArbitraryForClientsAndRepsansion



**************************************************************************************/

#include "ArbitraryForClientsAndReps.h"
#include <iostream>

using namespace std;

void ArbitraryForClientsAndReps::SetAddress(string address){
	this->address = address;
}
string ArbitraryForClientsAndReps::GetAddress() {
	return address;
}

void ArbitraryForClientsAndReps::SetFullName(string fullName) {
	this->name = fullName;
}
void ArbitraryForClientsAndReps::SetName(string name) {
	this->name = name;
}
string ArbitraryForClientsAndReps::GetName() {
	return name;
}

void ArbitraryForClientsAndReps::SetTotalSales(int totalSales) {
	this->totalSales = totalSales;
}


void ArbitraryForClientsAndReps::PrintInfo() {
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Total Sales: " << totalSales << endl << endl;
}

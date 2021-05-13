#include "SalesRep.h"
#include <iostream>

using namespace std;

SalesRep::SalesRep() {

}
SalesRep::SalesRep(string fullName, string address) {
	this->name = fullName;
}
SalesRep::SalesRep(string fullName, string address, int totalSales) {
	this->name = fullName;
	this->address = address;
	this->totalSales = totalSales;
}
SalesRep::SalesRep(string fullName, string address, int totalSales, int monthlySales) {
	this->name = fullName;
	this->address = address;
	this->totalSales = totalSales;
	this->monthlySales = monthlySales;
}

void SalesRep::SetMonthlySales(int monthlySales) {
	this->monthlySales = monthlySales;
}

int SalesRep::GetMonthlySales() {
	return monthlySales;
}

void SalesRep::SetSalesBonus(int salesBonus) {
	this->salesBonus = salesBonus;
}
int SalesRep::GetSalesBonus() {
	return salesBonus;
}

void SalesRep::PrintInfo() {
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Total Sales: " << totalSales << endl << endl;

}
void SalesRep::PrintAllInfo() {
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Total Sales: " << totalSales << endl;
	cout << "Monthly Sales: " << monthlySales << endl;
	cout << "Sales Bonus (not calculated or none = 0): " << salesBonus << endl << endl;
}
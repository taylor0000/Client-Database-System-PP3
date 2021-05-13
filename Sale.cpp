#include "Sale.h"
#include <vector>

using namespace std;

Sale::Sale() {
	this->price = 0;
	this->quantity = 0;
	this->service = "";
	this->clientName = "";
	this->yearlySales = 0;
}
Sale::Sale(string clientName, string service, int quantity, int price) {
	this->clientName = clientName;
	this->service = service;
	this->quantity = quantity;
	this->price = price;
	this->yearlySales = this->price * this->quantity;
}

Sale::Sale(string clientName, string service, int quantity, int price, int yearlySales) {
	this->clientName = clientName;
	this->service = service;
	this->quantity = quantity;
	this->price = price;
	this->yearlySales = this->price * this->quantity;
}

void Sale::SaleInfo() {
	cout << "Service: " << service << endl;
	cout << "Quantity Sold: " << quantity << endl;
	cout << "Price Per: " << price << endl;
	cout << "Total Sales: " << yearlySales << endl << endl;
}
void Sale::PrintInfo() {
	cout << "Client Name: " << clientName << endl;
	cout << "Quantity Sold: " << quantity << endl;
	cout << "Price Per: " << price << endl;
	cout << "Total Sales: " << yearlySales << endl << endl;
}
void Sale::PrintAllInfo() {
	cout << "Client Name: " << clientName << endl;
	cout << "Sale Description: " << service << endl << endl;
	cout << "Quantity Sold: " << quantity << endl;
	cout << "Price Per: " << price << endl;
	cout << "Yearly Sales: " << yearlySales << endl << endl;
}
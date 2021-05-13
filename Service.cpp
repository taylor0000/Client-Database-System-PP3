#include "Service.h"
#include "Sale.h"
Service::Service() {
	this->price = 0;
	this->quantitySold = 0;
	this->description = "";
}
Service::Service(string name, string description, int price) {
	this->name = name;
	this->description = description;
	this->price = price;
}
Service::Service(string name, string description, int price, int quantitySold) {
	this->name = name;
	this->description = description;
	this->quantitySold = quantitySold;
	this->price = price;
	this->totalSales = this->price * this->quantitySold;
}

void Service::PrintInfo() {
	cout << "Service Name: " << this->name << endl;
	cout << "Total Sales: " << totalSales << endl;
	cout << "Quantity Sold: " << quantitySold << endl;
	cout << "Price Per: " << price << endl << endl;
}
void Service::PrintAllInfo() {
	cout << "Service Name: " << this->name << endl;
	cout << "Service Description: " << description << endl << endl;
	cout << "Total Sales: " << totalSales << endl;
	cout << "Quantity Sold: " << quantitySold << endl;
	cout << "Price Per: " << price << endl << endl;
}
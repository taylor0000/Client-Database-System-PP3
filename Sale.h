#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "ArbitraryForClientsAndReps.h";

using namespace std;

class Sale
{
public:
	Sale();
	Sale(string clientName, string service, int price);
	Sale(string clientName, string service, int quantity, int price, int yearlySales);
	Sale(string clientName, string service, int quantity, int price);

	void AddSale(string service, string clientName, int price, int clientID, int quantity);
	void PrintInfo();
	void PrintAllInfo();

	void SetQuant(int quantity) { this->quantity = quantity; };
	int GetQuantity() { return quantity; };

	void SetPrice(int price) { this->price = price; };
	int GetPrice() { return price; };

	void SetName(string clientName) { this->clientName = clientName; };
	string GetName() { return this->clientName; };

	void SetServ(string service) { this->service = service; };
	string GetService() { return service; };
	void SaleInfo();
	
	int GetYearlySales() { return this->yearlySales; };
private:
	string clientName = "noname";
	string service = "no service";
	int quantity = 0;
	int price = 0;
	int yearlySales = 0;
};


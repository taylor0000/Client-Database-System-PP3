#pragma once
#include <string>
#include <iostream>

using namespace std;

class Service
{
public:
	Service();
	Service(string name, string description, int Price);
	Service(string name, string description, int price, int quantitySold);
	void PrintInfo();
	void PrintAllInfo();
	void SetQuant(int quant) { quantitySold = quant; };
	int GetQuant() { return quantitySold; };
	void SetPrice(int price) { this->price = price; };
	int GetPrice() { return price; };

	void SetName(string name) { this->name = name; };
	string GetName() { return name; };

	void SetDesc(string desc) { description = desc; };
	string GetDesc() { return description; };

	void SetTotalSales(int totalSales) { this->totalSales = totalSales; };
	int GetTotalSales() { return totalSales; };
private:
	string name = "noname";
	string description = "no desc";
	int quantitySold = 0;
	int price = 0;
	int totalSales = 0;
};


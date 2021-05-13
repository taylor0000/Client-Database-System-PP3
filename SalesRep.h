#pragma once
#include "ArbitraryForClientsAndReps.h";
class SalesRep : public ArbitraryForClientsAndReps		//derived from <-- class to have address, totalSales and name
{
public:
	SalesRep();
	SalesRep(string fullName, string address);
	SalesRep(string fullName, string address, int totalSales);	//TODO add monthly sales
	SalesRep(string fullName, string address, int totalSales, int monthlySales);
	void SetMonthlySales(int monthlySales);
	int GetMonthlySales();
	void SetSalesBonus(int salesBonus);
	int GetSalesBonus();
	void PrintInfo();
	void PrintAllInfo();
private:
	int monthlySales;
	int salesBonus = 0;
};


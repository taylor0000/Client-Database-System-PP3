/************************************************************************
Programming Project #3 -- Team Project for  C++ Client Database System Exp
ArbitraryForClientsAndRepsansion

**************************************************************************/
#pragma once
#include "Sale.h"

#include <vector>
#include <iostream>

using namespace std;

class ArbitraryForClientsAndReps		//This class will be used solely as a super class that gives 
{
public:
	void SetName(string name);
	void SetFullName(string fullName);
	void SetAddress(string address);
	void SetTotalSales(int totalSales);
	void PrintInfo();
	string GetName();
	string GetAddress();
	int GetTotalSales() { return totalSales; };

protected:
	string name = "no-Name";
	string address = "No-address";
	int totalSales = 0;
	//vector<Sale> sales;		//TODO figure out how Sale will be implimented
};


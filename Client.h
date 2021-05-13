#pragma  once
#include "ArbitraryForClientsAndReps.h";

class Client : public ArbitraryForClientsAndReps		//derived from <-- class to have address, totalSales and name
{
public:
	Client();
	Client(string fullName, string address);
	Client(string fullName, string address, int totalSales);

	void PrintInfo();
};
 

// Client Database Project.cpp : This file contains the 'main' function. Program execution begins and ends there.


//TODO: Saving to text file functions will be implimented last

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Client.h"
#include "SalesRep.h"
#include "Service.h"
using namespace std;

//***********************************************************************************************************************************************************************************************
//												Functions related to Client menu

void ListAllClients(vector<Client>& clients) {		//lists entire client list
	int counter = 1;

	cout << endl;
	cout << "List of all clients" << endl;

	for (Client client : clients) {
		cout << "Client ID: " << counter << endl;
		client.PrintInfo();


		counter++;
	}
}

void AddClient(vector<Client>& clients) {		//add a client object to clients vector
	string firstName, lastName, fullName, address;
	int totalSales;

	cout << "Add a client:" << endl;
	cout << "Enter Client's name" << endl;
	cin.ignore();
	getline(cin, fullName);

	cout << "Enter client's short address" << endl;
	getline(cin, address);

	cout << "Enter total sales" << endl;
	cin >> totalSales;
	Client clientObj(fullName, address, totalSales);
	clients.push_back(clientObj);

	cout << endl << "successfully added" << endl;
	clientObj.PrintInfo();
}

void UpdateClient(vector<Client>& clients) {
	int userInput;
	int totalSales;
	string fullName, address;

	cout << endl;
	cout << "Enter the client's ID number starting at 1" << endl;		//Later userInput is - 1 to account for starting ID at 1// DO not get confused; as vectors start at 0
	cin >> userInput;

	if (userInput >= clients.size()) {
		cout << endl;
		cout << "Invalid ID" << endl;
		return;
	}

	userInput -= 1;		//Assumes the user input starts at 1, thus this accounts for that + 1

	cout << "You have selected Client: " << userInput + 1 << endl;
	clients.at(userInput).PrintInfo();

	cout << "Enter a new name" << endl;
	cin.ignore();
	getline(cin, fullName);
	cout << "Enter a new address" << endl;
	getline(cin, address);
	cout << "Enter total sales" << endl;
	cin >> totalSales;

	clients.at(userInput).SetFullName(fullName);
	clients.at(userInput).SetAddress(address);
	clients.at(userInput).SetTotalSales(totalSales);

	cout << "Client successfully updated" << endl;
}

void ReadClientInfo(vector<Client>& clients) {			
	int userInput;

	cout << "Enter a which client by ID you would like more information on, ID starts at 1" << endl;
	cin >> userInput;
	cout << endl;

	if (userInput < clients.size()) {
		cout << "Client ID: " << userInput << endl;
		clients.at(userInput - 1).PrintInfo();					//userinput - 1 to account for ID starting at 1
	}
	else {
		cout << "Invalid ID" << endl;
	}
}


void SaveClientListToFile(const vector<Client> &clients) {						
	ofstream clientFS;
	clientFS.open("NewClients.txt");

	for (Client client : clients) {
		clientFS << client.GetName() << endl;
		clientFS << client.GetAddress() << endl;
		clientFS << client.GetTotalSales() << endl;
	}
	cout << "Saving updated list to file NewClients.txt" << endl;
	clientFS.close();
	cout << "Done." << endl;
}
string OutputClientMenu(vector<Client>& clients) {		//client menu		//current functionality in progress
	string userInput;


	cout << endl;

	while (userInput != "q") {
		cout << "\tCLIENT MENU" << endl << endl;
		cout << "Choose an operation or 'q' to exit to previous menu";
		cout << endl;
		cout << "1. List all clients" << endl;
		cout << "2. Add a client" << endl;
		cout << "3. Update a client's information" << endl;
		cout << "4. Read specified client info" << endl;
		cout << "5. Save updated client list to file" << endl << endl;			//TODO finish

		cin >> userInput;

		if (userInput == "1") {
			ListAllClients(clients);
		}
		else if (userInput == "2") {
			AddClient(clients);
		}
		else if (userInput == "3") {
			UpdateClient(clients);
		}
		else if (userInput == "4") {
			ReadClientInfo(clients);
		}
		else if (userInput == "5") {
			SaveClientListToFile(clients);
			return userInput;
		}
	}

	return userInput;
}

//***********************************************************************************************************************************************************************************************
//												Functions related to Salesrep menu


void ListAllReps(vector<SalesRep>& reps) {		//lists entire client list
	int counter = 1;

	cout << endl;
	cout << "List of all Sales Representatives" << endl;

	for (SalesRep SalesRep : reps) {
		cout << "Sales Representative ID: " << counter << endl;
		SalesRep.PrintInfo();


		counter++;
	}
}

void AddRep(vector<SalesRep>& reps) {		//add a client object to clients vector
	string firstName, lastName, fullName, address;
	int totalSales;
	int monthlySales;

	cout << "Add a representative:" << endl;
	cout << "Enter representative's name" << endl;
	cin.ignore();
	getline(cin, fullName);
	
	cout << "Enter representative's short address" << endl;
	getline(cin, address);

	cout << "Enter total sales of representative" << endl;
	cin >> totalSales;
	cout << "Enter monthly sales of representative" << endl;
	cin >> monthlySales;

	SalesRep repObj(fullName, address, totalSales, monthlySales);		//creates new SalesRep obj (repObj) with constructor using user input
	reps.push_back(repObj);
	cout << endl << "successfully added" << endl;
	repObj.PrintInfo();
}

void UpdateRep(vector<SalesRep>& reps) {		//will probably need revision after more info is added
	int userInput;
	int totalSales;
	int monthlySales;
	string fullName, address;

	cout << endl;
	cout << "Enter the sale rep's ID number starting at 1" << endl;		//Later userInput is - 1 to account for starting ID at 1// DO not get confused; as vectors start at 0
	cin >> userInput;

	if (userInput >= reps.size()) {
		cout << endl;
		cout << "Invalid ID" << endl;
		return;
	}

	userInput -= 1;		//Assumes the user input starts at 1, thus this accounts for that + 1

	cout << "You have selected Representative: " << userInput + 1 << endl;
	reps.at(userInput).PrintInfo();

	cout << "Enter a new name" << endl;
	cin.ignore();
	getline(cin, fullName);
	cout << "Enter a new address" << endl;
	getline(cin, address);
	cout << "Enter total sales" << endl;
	cin >> totalSales;
	cout << "Enter monthly sales";
	cin >> monthlySales;

	reps.at(userInput).SetFullName(fullName);
	reps.at(userInput).SetAddress(address);
	reps.at(userInput).SetTotalSales(totalSales);
	reps.at(userInput).SetMonthlySales(monthlySales);

	cout << "Representative successfully updated" << endl;
}

void ReadRepInfo(vector<SalesRep>& reps) {			
	int userInput;

	cout << "Enter which representative by ID you would like more information on, ID starts at 1" << endl;
	cin >> userInput;
	cout << endl;

	if (userInput < reps.size()) {
		cout << "Representative ID: " << userInput << endl;
		reps.at(userInput - 1).PrintAllInfo();					//userinput - 1 to account for ID starting at 1
	}
	else {
		cout << "Invalid ID" << endl;
	}
}

void FindSalesBonus(vector<SalesRep> reps) {	
	int min;
	int counter = 1;

	cout << endl;
	cout << "Calculating Sales Bonus based on 10%" << endl;
	cout << "What is the minimum monthly sales to receive a bonus?" << endl;
	cin >> min;

	cout << endl;
	cout << "Qualified Representatives" << endl << endl;

	for (SalesRep rep : reps) {
		if (rep.GetMonthlySales() > min) {
			cout << "Representative ID: " << counter << endl;
			rep.SetSalesBonus(rep.GetMonthlySales() * 1.10);
			
			rep.PrintInfo();
			cout << "Sales Bonus: " << rep.GetSalesBonus();
			counter++;
		}
	}

}

void SaveRepListToFile(const vector<SalesRep> &reps) {						//ERROR DUE TO DIFFICULTY OVERLOADING << OPERATOR //TODO finish
	ofstream repFS;
	repFS.open("NewSalesReps.txt");

	for (SalesRep rep : reps) {
		repFS << rep.GetName() << endl;
		repFS << rep.GetAddress() << endl;
		repFS << rep.GetTotalSales() << endl;
		repFS << rep.GetMonthlySales() << endl;
	}
	cout << "Saving updated list to file NewSalesReps.txt" << endl;
	repFS.close();
	cout << "Done." << endl;
}

string OutputSalesrepMenu(vector<SalesRep> reps) {		//sales menu //Not finished
	string userInput;

	while (userInput != "q") {
		cout << "\tSALES REPRESENTATIVES MENU" << endl << endl;
		cout << "Choose an operation or 'q' to exit to previous menu";
		cout << endl;
		cout << "SalesRep Menu" << endl;
		cout << "1. List all sales representatives and related information" << endl;
		cout << "2. Add a sales representative" << endl;
		cout << "3. Update a sales representative information" << endl;
		cout << "4. Read a specific sales representative's info with monthly sales" << endl;
		cout << "5. Calculate sales bonus based on the monthly sales" << endl;
		cout << "6. Save updated sales representative's database to file and return to previous menu" << endl;
		cout << endl;

		cin >> userInput;

		if (userInput == "1") {
			ListAllReps(reps);
		}
		else if (userInput == "2") {
			AddRep(reps);
		}
		else if (userInput == "3") {
			UpdateRep(reps);
		}
		else if (userInput == "4") {
			ReadRepInfo(reps);
		}
		else if (userInput == "5") {
			FindSalesBonus(reps);
		}
		else if (userInput == "6") {
			SaveRepListToFile(reps);
		}
	}

	return userInput;
}

//***********************************************************************************************************************************************************************************************
//												Functions related to Service menu

void ListAllServices(vector<Service>& services) {		//lists entire client list
	int counter = 1;

	cout << endl;
	cout << "List of all services" << endl;

	for (Service service : services) {
		cout << "Service ID: " << counter << endl;
		service.PrintInfo();

		counter++;
	}
}

void ListServiceDescription(vector<Service> services) {
	int userInput;

	cout << "Choose a service ID (starting at 1) to show its description" << endl << endl;
	cin >> userInput;

	if (userInput - 1 < services.size()) {
		cout << "Service ID: " << userInput << endl;
		services.at(userInput - 1).PrintAllInfo();
	}
	else {
		cout << "Invalid ID" << endl;
	}

}

void AddService(vector<Service>& services) {
	string name, description;
	int price, quantity;

	cin.ignore();

	cout << "Add A NEW SERVICE" << endl;
	cout << "Enter name of the new service" << endl;
	getline(cin, name);

	cout << "Enter a description of the service" << endl;
	getline(cin, description);

	cout << "Enter price of the service per use" << endl;
	cin >> price;

	cout << "Enter if this service has been sold to a client, 0 if not" << endl;
	cin >> quantity;

	Service serviceObj(name, description, price, quantity);
	services.push_back(serviceObj);
}

void SaveServicesToFile(const vector<Service> &services) {					
	ofstream serviceFS;
	serviceFS.open("NewServices.txt");

	for (Service service : services) {
		serviceFS << service.GetName() << endl;
		serviceFS << service.GetDesc() << endl;
		serviceFS << service.GetPrice() << endl;
		serviceFS << service.GetQuant() << endl;
		serviceFS << service.GetTotalSales() << endl;
	}
	cout << "Saving updated list to file" << endl;
	serviceFS.close();
	cout << "Done." << endl;
}

void UpdateService(vector<Service>& services) {
	string name, desc;
	int price, userInput, quantity, totalSales;

	cout << "UPDATE SERVICE" << endl;

	cout << "Enter Service by ID (Starts at 1)" << endl;
	cin >> userInput;

							
	cout << "Enter new name for service" << endl;
	
	cin.ignore();

	getline(cin, name);
	cout << "Enter new description for service" << endl;
	getline(cin, desc);
	cout << "Enter new price per service use" << endl;
	cin >> price;
	cout << "Enter bought quantity, 0 if none" << endl;
	cin >> quantity;
	cout << "Enter total Sales" << endl;
	cin >> totalSales;

	services.at(userInput - 1).SetName(name);
	services.at(userInput - 1).SetDesc(desc);
	services.at(userInput - 1).SetPrice(price);
	services.at(userInput - 1).SetQuant(quantity);
	services.at(userInput - 1).SetTotalSales(totalSales);
}														

void ProduceReport(vector<Service>& services) {		//incomplete
	cout << setw(50) << "MONTHLY SALES REPORT" << endl << endl;
	
}
string OutputServiceMenu(vector<Service>& services) {		//service menu
	string userInput;

	while (userInput != "q") {
		cout << "\tSERVICE MENU" << endl << endl;
		cout << "Choose an operation or 'q' to exit to previous menu";
		cout << endl;
		cout << "1. List all services" << endl;
		cout << "2. Display description of a specified service" << endl;
		cout << "3. Add a new product or service" << endl;
		cout << "4. Update a product or service" << endl;
		cout << "5. Produce a monthly sales report" << endl;
		cout << "6. Save updated products or services to file and return to previous menu" << endl;
		cout << endl;

		cin >> userInput;

		if (userInput == "1") {
			ListAllServices(services);
		}
		else if (userInput == "2") {
			ListServiceDescription(services);
		}
		else if (userInput == "3") {
			AddService(services);
		}
		else if (userInput == "4") {
			UpdateService(services);
		}
		else if (userInput == "5") {
			ProduceReport(services);
		}
		else if (userInput == "6") {
			SaveServicesToFile(services);
		}

	}
	return userInput;
}


//***********************************************************************************************************************************************************************************************
//												Functions related to Sales Menu

void PurchaseProduct(vector<Sale>& sales) { // DONE
	string clientName, service;
	int price, quantity;

	cin.ignore();

	cout << "Add A SALE" << endl;
	cout << "Enter new client's name" << endl;
	getline(cin, clientName);

	cout << "Enter a new service" << endl;
	getline(cin, service);

	cout << "Enter quantity of service sold, 0 if none" << endl;
	cin >> quantity;

	cout << "Enter a price per service" << endl;
	cin >> price;

	Sale saleObj(clientName, service, quantity, price);
	sales.push_back(saleObj);
}

void ListYearlySales(vector<Sale>& sales) {		//Done
	int counter = 1;

	cout << endl;
	cout << "List of yearly sales" << endl;

	for (Sale sales : sales) {// CHECK FOR ERRORS AND FIX
		cout << "Sale ID: " << counter << endl;
		sales.PrintInfo();

		counter++;
	}
}

void ListClientYearlySales(vector<Sale>& sales, vector<Client> clients) { // Done
	int userInput;
	
	string clientName;

	cout << "Enter Client's ID to display their yearly sales" << endl << endl;
	cin >> userInput;

	if (userInput < clients.size()) {
		clientName = sales.at(userInput - 1).GetName();
		int total = 0;

		cout << "Client ID: " << userInput << endl;
		cout << clientName << " Yearly Sales:" << endl << endl;
		for (Sale sale : sales) {
			if (sale.GetName() == clientName) {
				sale.SaleInfo();
				total = total + sale.GetYearlySales();
			}
		}
		cout << "Accumulative Total: " << total << endl;
	}
	else {
		cout << "Invalid ID" << endl;
	}
	

	

}

void SaveSalesToFile(const vector<Sale>& sales) {		//Done				
	ofstream saleFS;
	saleFS.open("NewSales.txt");

	for (Sale sale : sales) {
		saleFS << sale.GetName() << endl;
		saleFS << sale.GetService() << endl;
		saleFS << sale.GetQuantity() << endl;
		saleFS << sale.GetPrice() << endl;
	}
	cout << "Saving updated list to file" << endl;
	saleFS.close();
	cout << "Done." << endl;
}

void UpdateSales(vector<Sale>& sales) { // Done
	string clientName, service;
	int price, userInput, quantity;

	cout << "UPDATE SALES" << endl << endl;
	
	cout << "Enter the sale ID to be updated (starts at 1)" << endl;
	cin >> userInput;

	if (userInput < sales.size()) {
		cin.ignore();
		cout << "Enter updated sale's client name" << endl;
		getline(cin, clientName);

		cout << "Enter updated sale's service name" << endl;
		getline(cin, service);

		cout << "Enter bought quantity, 0 if none" << endl;
		cin >> quantity;

		cout << "Enter updated sale's price per service use" << endl;
		cin >> price;


		sales.at(userInput - 1).SetName(clientName);
		sales.at(userInput - 1).SetServ(service);
		sales.at(userInput - 1).SetPrice(price);
		sales.at(userInput - 1).SetQuant(quantity);
	}
	else {
		cout << "Invalid sale ID" << endl;
	}
	
	

}

string OutputSalesMenu(vector<Sale>& sales, vector<Client> clients) {		//sales menu
	string userInput;

	while (userInput != "q") {
		cout << "\tSALES MENU" << endl << endl;
		cout << "Choose an operation or 'q' to exit to previous menu";
		cout << endl;
		cout << "Sales Menu" << endl;
		cout << "1. Allow client to purchase a product or service" << endl;
		cout << "2. list all sales for the year" << endl;
		cout << "3. List all sales for the year of a client" << endl;
		cout << "4. Update a specific sale" << endl;
		cout << "5. Save sales database to file and return to previous menu" << endl;
		cout << endl;

		cin >> userInput;

		if (userInput == "1") {
			PurchaseProduct(sales);
		}
		else if (userInput == "2") {
			ListYearlySales(sales);
		}
		else if (userInput == "3") {
			ListClientYearlySales(sales, clients);
		}
		else if (userInput == "4") {
			UpdateSales(sales);
		}
		else if (userInput == "5") {
			SaveSalesToFile(sales);
			cout << "Creating new file: NewSales.txt" << endl;
			return userInput;
		}

	}
	return userInput;
}

//***********************************************************************************************************************************************************************************************
//												Functions related to Primary Menu
string OutputPrimaryMenu(vector<Client>& clients, vector<SalesRep> rep, vector<Service>& services, vector<Sale>& sales) {		//calls sub-menus based on entered category by user
	string userInput;
	
	cout << endl;
	cout << "Choose a database category or 'q' to quit" << endl;
	cout << "1. Clients" << endl;
	cout << "2. Sales Representatives" << endl;
	cout << "3. Products and services" << endl;
	cout << "4. Sales" << endl;
	cout << "" << endl;

	cin >> userInput;

	if (userInput == "1") {
		OutputClientMenu(clients);
	}
	else if (userInput == "2") {
		OutputSalesrepMenu(rep);
	}
	else if (userInput == "3") {
		OutputServiceMenu(services);
	}
	else if (userInput == "4") {
		OutputSalesMenu(sales, clients);
	}
	
	return userInput;
}

//***********************************************************************************************************************************************************************************************
//												Functions related to Main()

bool PopulateClientVector(vector<Client>& clients) {		//Function to populate clients vector	//Status: Working with current info in Clients.txt, however format changes to Clients.txt will break this function
	string name = "Noname";
	string address = "no address";
	string temp;
	int totalSales = 0;

	
	
	ifstream inFS;		//create in file stream variable

	inFS.open("Clients.txt");	//opens clients text file

	
	inFS.ignore();

	while (getline(inFS, name)) {	//while file stream has not reached end of file (text) do:
		
		getline(inFS, address);
		inFS >> totalSales;

		Client clientObj(name, address, totalSales); //create new client object
		clients.push_back(clientObj);
		
		inFS.ignore();
	}

	
	return true;
}

bool PopulateSalesRepsVector(vector <SalesRep>& salesReps) {		//Populate reps vector in main from salesRep text file
	string name;
	string address = "no address";
	string temp;
	int monthlySales = 0;
	int totalSales;

	SalesRep salesRepObj;	//create a SalesRep object, which has name, address, ect properties
	int counter = 0;	//keep track of which obj in SalesRep vector to add information
	ifstream inFS;		//create in file stream variable

	inFS.open("SalesReps.txt");	//opens salesRep text file


	inFS.ignore();

	while (getline(inFS, name)) {	//while file stream has not reached end of file (text) do:

		getline(inFS, address);

		inFS >> totalSales;

		inFS >> monthlySales;
		
		SalesRep repObj(name, address, totalSales, monthlySales);

		salesReps.push_back(repObj);

		inFS.ignore();
	}

	
	return true;
}

bool PopulateServiceVector(vector<Service>& services) {		
	string name = "noName";
	string description = "no desc";
	int quantitySold = 0;
	int price = 0;
	ifstream inFS;
	
	int counter = 0;

	inFS.open("Services.txt");
		
	

	while (getline(inFS, name)) {

		getline(inFS, description);
		
		inFS >> price;
		
		inFS >> quantitySold;
		
		
		inFS.ignore();

		Service serviceObj(name, description, price, quantitySold);
		services.push_back(serviceObj);
	}



	return true;
}

bool PopulateSalesVector(vector<Sale>& sales) { // DONE
	string clientName = "noName";
	string service = "no serv";
	int quantity = 0;
	int price = 0;
	ifstream inFS;

	int counter = 0;

	inFS.open("Sales.txt");



	while (getline(inFS, clientName)) {

		getline(inFS, service);

		inFS >> quantity;

		inFS >> price;


		inFS.ignore();

		Sale saleObj(clientName, service, quantity, price);
		sales.push_back(saleObj);
	}



	return true;
}
//***********************************************************************************************************************************************************************************************
//												Main Program


int main()
{
	string quit = "q";
	string userInput;


	vector<Client> clients;		//create a vector of client object to form our client list
	vector<SalesRep> reps;		//create a vector of sales representative objects/s
	vector<Service> services;	//create a vector of type Service objects
	vector<Sale> sales;			//create a vector of type Sale objects

	PopulateClientVector(clients);		//populate our client list
	PopulateSalesRepsVector(reps);		//populate salesReps list with text file
	PopulateServiceVector(services);	//populate Service list with text file
	PopulateSalesVector(sales);			//populate Sales list with text file


	cout << "Welcome to The MasterSkillz.inc Client Database";

	while (userInput != quit) {

		userInput = OutputPrimaryMenu(clients, reps, services, sales);			//call funtion to print primary menu that calls funtions to more sub-menus until quit ("q") is entered
	}

	return 0;
}


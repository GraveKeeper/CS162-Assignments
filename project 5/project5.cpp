#include <iostream>
#include <cstring>
#include <fstream>
#include "CarList.h"
#define SEMI ';'
using namespace std;

int menu()
{
	int option = 0;
	cout << "Please Choose an option : " << endl << endl;
	cout << "  1. New Car " << endl;
	cout << "  2. Display All Cars " << endl;
	cout << "  3. Remove Car " << endl;
	cout << "  4. Search by Origin " << endl;
	cout << "  5. Search by Name " << endl;
	cout << "  6. Search by Model " << endl;
	cout << "  7. Quit " << endl << endl;
	cout << " Option: ";
	cin >> option;
	return option; 
}

int main()
{	
	CarList * TheList = new CarList();	
	int option;
	option = menu();
	while(option!=7)
	{
		if(option < 1 || option > 7)
		cout << "Invalid option please enter a vaild option " << endl;
		else
		{
			switch(option)
			{
				case 1:
					TheList->newCar();
					break;
				case 2:
					cout << TheList;
					break;
				case 3: 
					TheList->removeCar();
					break;
				case 4:
					TheList->searchOrg();
					break;
				case 5:
					TheList->searchName();
					break;
				case 6:
					TheList->searchModel();
					break;		
			}
		}
		option = menu();
	}
	bool result = TheList->saveFile();
	if(result)
	{
	cout << "File saved! " << endl; 
	}
	else
	cout << "File error  " << endl;
}



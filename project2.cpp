#include <iostream>
#include <cstring>
#include <fstream>
#define SEMI ';'
using namespace std;

struct carType
{
	char name[101],origin[101];
	double mpg,displacement,horsepower,weight,acceleration;
	int cylinders,model;
};

ifstream loadData(carType carList[],int &pos)
{
	ifstream inFile;
	inFile.open("cars.txt");
	inFile.get(carList[pos].name, 101,SEMI);
	while(!inFile.eof())
	{
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].mpg;
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].cylinders;
	inFile.ignore (5, SEMI);
	inFile >> carList[pos].displacement;
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].horsepower;
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].weight;
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].acceleration;
	inFile.ignore(5, SEMI);
	inFile >> carList[pos].model;
	inFile.ignore(5, SEMI);
	inFile.get(carList[pos].origin,101, '\n');
	inFile.ignore(5,'\n');
	pos++;
	inFile.get(carList[pos].name, 101,SEMI);
	}
	return inFile;
}

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

void displayAll(carType carList[],int pos)
{
	for(int i =0;i < pos; i++)
	{
		cout << i << ":" << endl;
		cout << "name: " << carList[i].name << endl;
		cout << "mpg: " << carList[i].mpg << endl;
		cout << "cylinders: " << carList[i].cylinders << endl;
		cout << "displacement: " << carList[i].displacement << endl;
		cout << "horsepower: " << carList[i].horsepower << endl;
		cout << "weight: " << carList[i].weight << endl;
		cout << "acceleration: " << carList[i].acceleration << endl;
		cout << "model: " << carList[i].model << endl;
		cout << "origin: " << carList[i].origin << endl << endl;
	}
}

void newCar(carType carList[],int &pos)
{
	cout << "Enter data for the new car" << endl << endl;
	cout << "Name: ";
	cin >> carList[pos].name;
	cout << endl << "mpg: ";
	cin >> carList[pos].mpg;
	cout << endl << "cylinders: ";
	cin >> carList[pos].cylinders;
	cout << endl << " displacement: ";
	cin >> carList[pos].displacement;
	cout << endl << "horsepower: ";
	cin >> carList[pos].horsepower;
	cout << endl << "weight: ";
	cin >> carList[pos].weight;
	cout << endl << "acceleration: ";
	cin >> carList[pos].acceleration;
	cout << endl << "model: ";
	cin >> carList[pos].model;
	cout << endl << "origin: ";
	cin >> carList[pos].origin;
	pos++;
}

void removeCar(carType carList[],int &pos)
{
	int carN;
	cout << "What is the index of the car you wish to remove ? " << endl;
	cin >> carN;
	for(int i = carN;i < pos - 1;i++)
	{
		carList[i] = carList[i+1]; 
	}
	pos--;
}

void displayOne(carType carList[],int pos)
{
	cout << endl;
	cout << pos << endl;
	cout << "Name: " << carList[pos].name << endl;
	cout << "mpg: " << carList[pos].mpg << endl;
	cout << "cylinders: " << carList[pos].cylinders << endl;
	cout << "displacement: " << carList[pos].displacement << endl;
	cout << "horsepower: " << carList[pos].horsepower << endl;
	cout << "weight: " << carList[pos].weight << endl;
	cout << "acceleration: " << carList[pos].acceleration << endl;
	cout << "model: " << carList[pos].model << endl;
	cout << "origin: " << carList[pos].origin << endl;
}

void searchOrg(carType carList[], int pos)
{
	char searchTerm[1000];
	cout << "Which origin (US,Japan,Europe)? ";
	cin >> searchTerm;
	for(int i = 0; i < pos; i++)
		if(strcmp(searchTerm,carList[i].origin)==0)
			displayOne(carList,i);
			 
			
}

void searchName(carType carList[], int pos)
{

	cout << "What Name do you want to Find ? ";
	char searchN[30];
	cin >> searchN;
	for(int i = 0;i < pos; i++)
	{
	if(strstr(carList[i].name,searchN))
		displayOne(carList,i);
	}

}

void searchModel(carType carList[],int pos)
{
	int model;
	cout << "Enter the model: ";
	cin >> model;
	for(int i = 0; i < pos; i++)
	{
		if(carList[i].model == model)
			displayOne(carList,i);
	}

}

bool saveFile(carType carList[],int pos)
{
	ofstream outFile;

	outFile.open("cars.txt");
	if(!outFile)
		return false;

	for(int i = 0; i < pos; i++ )
	{
		outFile << carList[i].name << SEMI;
		outFile << carList[i].mpg << SEMI;
		outFile << carList[i].cylinders << SEMI;
		outFile << carList[i].displacement << SEMI;
		outFile	<< carList[i].horsepower << SEMI;
		outFile << carList[i].weight << SEMI;
		outFile << carList[i].acceleration << SEMI;
		outFile << carList[i].model << SEMI;
		outFile << carList[i].origin << '\n';
	}
	return true;
}

int main()
{	
	carType carList[1000];
	int option;
	int pos = 0;
	ifstream inFile;

	inFile=loadData(carList,pos);
	if(pos == 0)
	{
		cout << "File Error" << endl;
		exit(0);
	}
	inFile.close();
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
					newCar(carList,pos);
					break;
				case 2:
					displayAll(carList,pos);
					break;
				case 3: 
					removeCar(carList,pos);
					break;
				case 4:
					searchOrg(carList,pos);
					break;
				case 5:
					searchName(carList,pos);
					break;
				case 6:
					searchModel(carList,pos);
					break;		
			}
		}
		option = menu();
	}
	bool result = saveFile(carList,pos);
	if(result)
	{
	cout << "File saved! " << endl; 
	}
	else
	cout << "File error  " << endl;
}



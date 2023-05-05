#include "CarList.h"
#define SEMI ';'
#define MAX_CARS 500
#include <iostream>
#include <fstream>
#include <string.h>


CarList::CarList()
{
	ifstream inFile;
	inFile.open("cars.txt");
	size = 0;
	CarType * TheCar;
	char iname[25], iorigin [10];
	double impg, idisplacement, ihorsepower, iweight, iacceleration;
	int icylinders, imodel;

	inFile.get(iname, 101, SEMI);
	while(!inFile.eof() && size < MAX_CARS)
	{
		 TheCar = new CarType();
		 inFile >> impg;
		 inFile.ignore(5, SEMI);
		 inFile >> icylinders;
		 inFile.ignore(5, SEMI);
		 inFile >> idisplacement;
		 inFile.ignore(5, SEMI);
		 inFile >> ihorsepower;
		 inFile.ignore(5, SEMI);
		 inFile >> iweight;
		 inFile.ignore(5, SEMI);
		 inFile >> iacceleration;
		 inFile.ignore(5, SEMI);
		 inFile >> imodel;
		 inFile.ignore(5, SEMI);
		 inFile.get (iorigin, 101, '\n');
		 TheCar->init (iname, iorigin, impg, idisplacement, ihorsepower, iweight, iacceleration, icylinders, imodel)
		 cars[size] = TheCar;
		 size++;
		 inFile.get(iname,101, SEMI);
	}
	inFile.close();
}

void CarList::displayAll()
{
	for(int i = 0;i < size; i++)
	{
		cout << i << endl;
		cars[i]->display();
	}
}

void CarList::newCar()
{
	cars[size] = new CarType(true);
	size++;
}

void CarList::removeCar()
{
	int carN;
	cout << "What is the index of the car you wish to remove ? " << endl;
	cin >> carN;
	for(int i = carN;i < size - 1;i++)
	{
		cars[i] = cars[i+1];
	}
	size--;
}

void CarList::searchOrg()
{
	char searchTerm[1000];
	cout << "which origin (US, Japan, Europe) ? ";
	cin >> searchTerm;
	for(int i = 0; i < size; i++)
		if(strcmp(searchTerm,cars[i]->getOrigin()==0))
			cars[i]->display();
}

void CarList::searchName()
{
	cout << "What Name do you want to Find ? ";
	char searchN[30];
	cin >> searchN;
	for(int i = 0;i < size; i++)
	{
	if(strcmp(cars[i]->getName(),searchN)==0)
		cars[i]->display();
	}
}

void CarList::searchModel()
{
	int model;
	cout << "Enter the model: ";
	cin >> model;
	for(int i = 0;i < size; i++)
	{
		if (cars[i]->getModel() == model)
			cars[i]->display();
	}
}

bool CarList::saveFile()
{
	ofstream outFile;

	outFile.open("cars.txt");
	if(!outFile)
		return false;

	for(int i= 0;i < size; i++)
	{
		outFile << cars[i]->getName() << SEMI;
		outFile << cars[i]->getMpg() << SEMI;
		outFile << cars[i]->getCylinders() << SEMI;
		outFile << cars[i]->getDisplacement() << SEMI;
		outFile << cars[i]->getHorsepower() << SEMI;
		outFile << cars[i]->getWeight() << SEMI;
		outFile << cars[i]->getAcceleration() << SEMI;
		outFile << cars[i]->getModel() << SEMI;
		outFile << cars[i]->getOrigin() << '\n';
	}
	return true;
}

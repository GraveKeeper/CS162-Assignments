#include "CarList.h"
#define SEMI ';'
#define MAX_CARS 700
#include <iostream>
#include <fstream>
#include <string.h>


CarList::CarList()
{
	ifstream inFile;
	inFile.open("cars.txt");
	size = 0;
	CarType * TheCar;
	char iname[100], iorigin [100];
	double impg, idisplacement, ihorsepower, iweight, iacceleration;
	int icylinders, imodel;

	inFile.get(iname, 101, ';');
	while(!inFile.eof())
	{
		 inFile.ignore(5, ';');
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
		 inFile.ignore(5, '\n');
		 TheCar = new CarType();
		 TheCar->init (iname, iorigin, impg, idisplacement, ihorsepower, iweight, iacceleration, icylinders, imodel);
		 size++;
		 cars[size] = TheCar;
		 inFile.get(iname,101, SEMI);
	}
	inFile.close();
	
}

CarList::CarList(CarList * iList)
{
	int totalcars = iList->getSize();
	for(int i = 0; i < totalcars; i++)
	{	
		cars[i] = iList->getCar(i);
	}
}

void CarList::displayAll()
{
	for(int i = 0;i < size; i++)
	{
		cout << endl << i << endl;
		cout << cars[i] << endl << endl;
	}
}

void CarList::newCar()
{
	CarType* TheCar = new CarType(true);
	CarType* holdOld[size];
	deepCopy(cars,holdOld, size);
	delete cars;
	CarType* cars[size+1];
	deepCopy(holdOld, cars, size);
	size++;
	cars[size] = TheCar;
	delete holdOld;
	delete TheCar;
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
		if(strcmp(searchTerm,cars[i]->getOrigin())==0)
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

CarType CarList::getCars()
{
	return cars;
}

int CarList::getSize()
{
	return size;
}

CarType* CarList::getCar(int index)
{
	return cars[index];
}

CarList& CarList::operator = (CarList * iList)
{
	int totalCars = iList->getSize();
	for(int i = 0; i <=totalCars; i++)
	{
		cars[i] = iList->getCar(i);
	}
	return *this;
}

ostream& operator << (ostream& os,CarList * iList)
{
	int size = iList->getSize();
	cout << size << endl;
	for(int i = 0; i < size; i++)
	{
		os << endl << i << endl;
		os << iList->cars[i] << endl << endl;
	}
	return os;
}

void CarList::deepCopy(CarType* source[], CarType* target[], int total)
{
	
	for(int i = 0; i < total; i++)
	{
		target[i]->setName(source[i]->getName());
		target[i]->setMpg(source[i]->getMpg());
		target[i]->setCylinders(source[i]->getCylinders());
		target[i]->setDisplacement(source[i]->getDisplacement());
		target[i]->setHorsepower(source[i]->getHorsepower());
		target[i]->setWeight(source[i]->getWeight());
		target[i]->setAcceleration(source[i]->getAcceleration());
		target[i]->setModel(source[i]->getModel());
		target[i]->setOrigin(source[i]->getOrigin());
	}
}

CarList::~CarList()
{
	delete cars;

}

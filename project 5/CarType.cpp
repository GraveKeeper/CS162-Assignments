#include <iostream>
#include <cstring>
#include "CarType.h"
#define SEMI ';'

CarType::CarType ()
{}

void CarType::init(char iname[],char iorigin [],double impg, double idisplacement,double ihorsepower, double iweight, double iacceleration, int icylinders, int imodel)
{
	strcpy(name,iname);
	strcpy(origin,iorigin);
	mpg = impg;
	displacement = idisplacement;
	horsepower = ihorsepower;
	weight = iweight;
	acceleration = iacceleration;
	cylinders = icylinders;
	model = imodel;
}

CarType::CarType(CarType * iCar)
{
	strcpy(name, iCar->getName());
	mpg = iCar->getMpg();
	cylinders = iCar->getCylinders();
	displacement = iCar->getDisplacement();
	horsepower = iCar->getHorsepower();
	weight = iCar->getWeight();
	acceleration = iCar->getAcceleration();
	model = iCar->getModel();
	strcpy(origin, iCar->getOrigin());
}

CarType::CarType(bool dummy)
{
	cout << "Enter data for the new car " << endl;
	cout << "Name";
	cin >> name;
	cout << endl << "mpg";
	cin >> mpg;
	cout << "cylinders";
	cin >> cylinders;
	cout << "displacement";
	cin >> displacement;
	cout << "horsepower";
	cin >> horsepower;
	cout << "weight";
	cin >> weight;
	cout << "acceleration";
	cin >> acceleration;
	cout << "model";
	cin >> model;
	cout << "origin";
	cin >> origin;
}


char * CarType::getName()
{
	return name;
}

void CarType::setName(char*iName)
{
	strcpy(name, iName);
}

double CarType::getMpg()
{
	return mpg;
}

void CarType::setMpg(double impg)
{
	mpg = impg;
}

int CarType::getCylinders()
{
	return cylinders;
}

void CarType::setCylinders(int icylinders)
{
	cylinders = icylinders;
}

double CarType::getDisplacement()
{
	return displacement;
}

void CarType::setDisplacement(double idisplacement)
{
	displacement = idisplacement;
}

double CarType::getHorsepower()
{
	return horsepower;
}

void CarType::setHorsepower(double ihorsepower)
{
	horsepower = ihorsepower;
}

double CarType::getWeight()
{
	return weight;
}

void CarType::setWeight(double iweight)
{
	weight = iweight;
}

double CarType::getAcceleration()
{
	return acceleration;
}

void CarType::setAcceleration(double iacceleration)
{
	acceleration = iacceleration;
}

int CarType::getModel()
{
	return model;
}

void CarType::setModel(int iModel)
{
	model = iModel;
}

char * CarType::getOrigin()
{
	return origin;
}

void CarType::setOrigin(char * iOrigin)
{
	strcpy(origin, iOrigin);
}

void CarType::display()
{
	cout << "Name: " << name << endl;
	cout << "mpg: " << mpg << endl;
	cout << "cylinders: " << cylinders << endl;
	cout << "displacement: " << displacement << endl;
	cout << "horsepower: " << horsepower << endl;
	cout << "weight: " << weight << endl;
	cout << "acceleration: " << acceleration << endl;
	cout << "model: " << model << endl;
	cout << "origin: " << origin << endl;
}

ostream& operator<<(ostream& os, const CarType *iCar)
{
	os << "Name: " << iCar->name << endl;
	os << "mpg: " << iCar->mpg << endl;
	os << "cylinders: " << iCar->cylinders << endl; 
	os << "displacement: " << iCar->displacement << endl;
	os << "hosepower: " << iCar->horsepower << endl;	
	os << "weight: " << iCar->weight << endl;
	os << "accleration: " << iCar->acceleration << endl;
	os << "model: " << iCar->model << endl;
	os << "origin: " << iCar->origin << endl;
	return os;
}	

CarType& CarType::operator = (CarType* iCar)
{
	strcpy(name, iCar->getName());
	mpg = iCar->getMpg();
	cylinders = iCar->getCylinders();
	displacement = iCar->getDisplacement();
	horsepower = iCar->getHorsepower();
	weight = iCar->getWeight();
	acceleration = iCar->getAcceleration();
	model = iCar->getModel();
	strcpy(origin, iCar->getOrigin());

	return *this;
}

CarType::~CarType()
{



}

#include <iostream>
#include <cstring>
#include "CarType.h"
#define SEMI ';'

CarType::CarType ()
{}

void CarType::init(char iname[],char iorigin [],double impg, double idisplacement,double ihorsepower, double iweight, double iacceleration, int icylinders, int imodel)

	name = iname;
	origin = iorigin;
	mpg = impg;
	displacement = idisplacement;
	horsepower = ihorsepower;
	weight = iweight;
	acceleration = iacceleration;
	cylinders = icylinder;
	model = imodel;
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
	cout << "acceleration"
	cin >> acceleration;
	cout << "model";
	cin >> model;
	cout << "origin";
	cin >> origin;
}


char[] CarType::getName()
{
	return name;
}

double CarType::getMpg()
{
	return mpg;
}

int CarType::getCylinders()
{
	return cylinders:
}

double CarType::getDisplacement()
{
	return displacement;
}

double CarType::getHorsepower()
{
	return horsepower;
}

double CarType::getWeight()
{
	return weight;
}

double CarType::getAcceleration()
{
	return acceleration;
}

int CarType::getModel()
{
	return model;
}

char[] CarType::getOrigin()
{
	return origin;
}

void CarType::display()
{
	cout << "Name: " << name << endl;
	cout << "mpg: " << mpg << endl;
	cout << "cylinders: " << cylinders << endl;
	cout << "displacement: " << dsplacement << endl;
	cout << "horsepower: " << horsepower << endl;
	cout << "weight: " << weight << endl;
	cout << "acceleration: " << acceleration << endl;
	cout << "model: " << model << endl;
	cout << "origin: " << origin << endl;
}


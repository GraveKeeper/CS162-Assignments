#include <iostream>
#include <fstream>
#include "CarType.h"
using namespace std;

class CarList
{
	private:
		CarType * cars[1000];
		//ifstream inFile;
		int size;
		void deepCopy(CarType* source[], CarType* target[], int total);
	public:
		CarList();
		CarList(CarList * iList);
		~CarList();
		void displayAll();
		void newCar();
		void removeCar();
		void displayOne();
		void searchOrg();
		void searchName();
		void searchModel();
		bool saveFile();
		CarType  getCars();
		int getSize();
		CarType* getCar(int index);
		CarList& operator = (CarList * iList);
		friend ostream& operator << (ostream& os,CarList * iList);
};

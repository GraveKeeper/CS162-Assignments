#include <fstream>
#include "CarType.h"
using namespace std;

class CarList
{
	private:
		CarType * cars[1000];
		ifstream inFile;
		int size;
	public:
		CarList();
		void displayAll();
		void newCar();
		void removeCar();
		void displayOne();
		void searchOrg();
		void searchName();
		void searchModel();
		bool saveFile();

};

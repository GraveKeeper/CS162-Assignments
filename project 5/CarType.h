#include <fstream>
using namespace std;

class CarType
{
	private:
		char name[101], origin[101];
		double mpg,displacement,horsepower,weight,acceleration;
		int cylinders,model;
	public:
	    CarType();
		CarType(CarType * iCar);
		CarType(bool dummy);
		void init(char iname[],char iorigin[], double impg, double idisplacement, double ihorsepower, double iweight, double iacceleration, int icylinders, int imodel);
		void setName (char * iName);
		char * getName();
		void setMpg(double impg);
		double getMpg();
		void setCylinders (int icylinders);
		int getCylinders();
		void setDisplacement (double idisplacement);
		double getDisplacement();
		void setHorsepower (double ihorsepower);
		double getHorsepower();
		void setWeight (double iweight);
		double getWeight();
		void setAcceleration (double iacceleration);
		double getAcceleration();
		void setModel (int iModel);
		int getModel();
		void setOrigin (char * iOrigin);
		char * getOrigin();
		void display();
		CarType& operator = (CarType* iCar);
		
		~CarType();
		friend ostream& operator<<(ostream& os, const CarType *iCar);
};

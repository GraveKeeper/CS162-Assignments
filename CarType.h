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
		CarType();
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
};

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//using namespace std;
class Pallet
{
private:
	double p_length;
	double p_width;
	double p_height;
	double p_cubeMetr;
	int quanity = 0;
public:
	Pallet() {}
	Pallet(double l, double w, double c, double h, int q);
	Pallet(const Pallet& p);
	~Pallet() {};

	void setCubeMetr();

	int getQuanity() { return quanity; };
	double getLength() { return p_length; };
	double getWidth() { return p_width; };
	double getHeight() { return p_height; }
	double getCube() { return p_width * p_length * quanity; };
	double getPalSize() { return p_width * p_length; };
	double getWidthSize() { return p_width * 2; };

	friend std::istream& operator>>(std::istream& is, Pallet & s);
	friend std::ostream& operator<<(std::ostream& os, const Pallet& s);
};

class Car : Pallet
{
private:
	double cubeMetr = 0.0;
	double length = 0.0;
	double width = 0.0;
	double height = 0.0;

	double * Rheight;
	double * Rlength;
	double * Rwidth;


	double area;
	int palletRow = 2;
	double Sload; //calculation
	double SloadQ;
public:
	Car() {}
	Car(double l, double w, double m, double h);
	Car(const Car& c);
	~Car() {};

	void setCubeM();

	double getLength() { return length; };
	double getWidth() { return width; };
	double getHeight() { return height; }
	double getCubeMetr() { return length * width; };
	bool loadWidth();

	friend std::istream& operator>>(std::istream& is, Car& s);
	friend std::ostream& operator<<(std::ostream& os, const Car& s);

	void setWidthArea();
	void setSloadQ();
	void setSload();

	double getArea() { return area; };
	double getLengthLoad() { return Sload; };
	double getSloadQ() { return SloadQ; };

	bool multiMachLoad();
};

class CarCatalogue
{
public:
	enum Truck { Porter, EuroTruck, Gazel, MersedesSprinter, FiveTonCar, TenTonCar };
	struct CarPorter
	{
		double length = 2.750;
		double width = 1.7;
		double area = 4.675;
		double height = 1.6;
		int quanity = 0;
		std::string name = "Porter";
	} carPorter;
	struct CarEuroTrack
	{
		double length = 13.6;
		double width = 2.4;
		double height = 2.6;
		double area = 32.64;
		int quanity = 0;
		std::string name = "EuroTruck";
	};

	struct CarGazel
	{
		double length = 3.4;
		double width = 1.56;
		double height = 1.9;
		double area = 3.61;
		int quanity = 0;
		std::string name = "Gazel";
	};
	struct CarMersedesSprinter
	{
		double length = 2.6;
		double height = 1.8;
		double width = 1.4;
		double area = 3.64;
		int quanity = 0;
		std::string name = "MersedesSprinter";
	};
	struct CarFiveTonCar
	{
		double length = 5.0;
		double width = 2.4;
		double height = 1.9;
		double area = 12;
		int quanity = 0;
		std::string name = "FiveTonTruck";
	};
	struct CarTenTonCar
	{
		double length = 8.0;
		double width = 2.4;
		double height = 1.9;
		double area = 19.2;
		int quanity = 0;
		std::string name = "TenTonTruck";
	};
	int getLoadWidth(double wp, int q);
	void fileclear();
	void getCar(double l, int w, double q, double pl, std::string ad);
};
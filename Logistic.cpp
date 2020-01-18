#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include "Lazylogistician.h"
#include <stdlib.h>

using namespace std;

#pragma warning( disable : 4244 )
#pragma warning( disable : 4101 )



//Breakfast!!!
static double _length = 0.01;
static double _height = 0.01;
static double _width = 0.01;


void BoxSize(double n);

double CarCube(double cLenght, double cWidth, double cHeight); //Returns volume of car in cubes
int QunLoadBoxWidth(double carLength, double boxWidth);
int QunLoadBoxlength(double carLength, double boxLength);
int QunLoadBoxHeigth(double carHeight, double boxHeight);
double CubOneBox(int quanity, double cube);

double cubeBox(double bLength, double bWidth, double bHeight);

//Console choices
void SingleOrder();
void MultiOrder();
void CarCheck();
void boxloading();
void CubeBoxloading();
int CarQuanOrder(double l, double h, double w, double cl, double ch, double cw);

bool loadRow(double ls, double c, int r);
int loadWidth(double it, double w);
void EatLine();

int main()
{
	
	char c;
	cout << "Data should be in meters!";
	cout << "\nExample:  ""Enter length of pallet: 1.35;\t  Enter width of pallet: 0.85\n";

	do
	{
		cout << "\n\t            Enter which calculation do you wish to do:\n";
		cout << "\n\t1) SingleOrder\n" << "\t2) MultiOrder\n" << "\t3) To check which car do you need for order\n";
		cout << "\t4) Box loading\n" << "\t5) Calculation according to cubes and quanity only\n";
		cout << "\t0) Exit\n";

		cout << "Enter your choice: ";
		cin >> c;
		switch (c)
		{
		case '1':
			SingleOrder();
			break;
		case '2':
			MultiOrder();
			break;
		case '3':
			CarCheck();
			break;
		case '4':
			boxloading();
			break;
		case '5':
			CubeBoxloading();
		case '0':
			exit(1);
		default:
			break;
		}
	} while (c != '0');


	system("pause");
	return 0;
}

void SingleOrder()
{
	Pallet p1;
	Car c1;
	cin >> c1;
	c1.setCubeM();
	cout << "\nYou entered\n";
	cout << c1;

	cout << "Enter the size of pallets\n";
	cin.get();
	cin >> p1;
	p1.setCubeMetr();

	cout << "\nYou entered\n";
	cout << p1;

	auto s = p1.getCube();
	auto v = c1.getCubeMetr();
	cout << "\nChecking if car volume is enough for order...\n";

	Sleep(500);

	if ((v - s) < 0)
		cout << "\nNot enough car size for order!\n";
	else if (c1.loadWidth() && c1.multiMachLoad() && p1.getHeight() <= c1.getHeight())
	{
		cout << "\nThe order is correct!\n";
		cout << (v - s) << " cubes left in a car!\n";
	}
	else
	{ 
		cout << "\nNot enough car size for order!\n";
		cout << (v - s) << " cubes left in a car!\n";
	}
	cout << "Enter any key start calculating size (q for exit!)\n";
}

void MultiOrder()
{
	std::vector<double> w;
	std::vector<double> l;
	std::vector<int> qun;
	std::vector<Pallet> pz;
	Pallet p;
	string* q = new string;
	int row;

	Car c1;

	cin >> c1;
	c1.setCubeM();
	cout << "\nYou entered\n";
	cout << c1;
	double carlength = c1.getLength();
	double lengthSum = 0.0;
	double widthSum = 0.0;
	

	cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	while (cin >> *q && *q != "q")
	{
		cin >> p;
		pz.push_back(p);
		if (p.getHeight() > c1.getHeight())
		{
			cout << "Car cannot be loaded, pallet(s) are too high!";
			break;
		}
		cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	} 
	if (p.getHeight() > c1.getHeight())
	{
		exit(1);
	}
	
	std::vector<Pallet>::iterator itv = pz.begin();
	//check this one!!!
	for (; itv != pz.end(); *itv++)
	{
		w.push_back(itv->getWidth());
		l.push_back(itv->getLength());
		qun.push_back(itv->getQuanity());
	}
	std::vector<int>::iterator qunit = qun.begin();

	
	for (auto it = pz.begin(); qunit != qun.end(),  it != pz.end(); *it++, *qunit++)
	{
		row = loadWidth(it->getWidth(), c1.getWidth());
		lengthSum = (((it->getLength() * it->getQuanity())) / row);


		if (loadRow(lengthSum, carlength, row) == true)
		{
			carlength -= lengthSum;
		}
		else
		{ 
			cout << "Car can't be loaded" << endl;
			carlength -= lengthSum;
			break;
		}
		
	}

	if ((carlength - 0.2) < 0.0)
	{
		cout << "Car cant be loaded!" << endl;
		cout << carlength << " length left in the car.";
	}
	else if((carlength - 0.2) > 0.0)
	{ 
		cout << "Car can be loaded!" << endl;
	cout << carlength << " length left in the car.";
	}
	else
	{ 
		cout << "Car can be loaded!" << endl;
	cout << carlength << " length left in the car.";
	}
	delete q;
}

void CarCheck()
{

	Pallet p;
	string * q = new string;
	string ad = "";

	std::vector<Pallet> pz;
	std::vector<double> len;
	std::vector<int> load;
	std::vector<string> adress;

	CarCatalogue c;
	double w = 0.0;
	double length = 0.0;

	c.fileclear();

	std::vector<string> car_order;

	cout << "Enter the size of pallets\n";
	cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	while (cin >> *q && *q != "q")
	{
		cout << "Enter delivery adress or name of destination\n";
		cin.get();
		getline(std::cin, ad);
		adress.push_back(ad);
		//EatLine();
		cin >> p;
		pz.push_back(p);
		
		cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	}

	cout << "Checking which car is best choice for order...\n";
	Sleep(500);

	std::vector<Pallet>::iterator itp = pz.begin();
	
	for (; itp != pz.end(); *itp++)
	{
		//w = c.getLoadWidth(itp->getWidth(), itp->getQuanity());
		len.push_back(length += (itp->getLength() * itp->getQuanity()));
		load.push_back(c.getLoadWidth(itp->getWidth(), itp->getQuanity()));
		length = 0.0;
	}
	
	std::vector<double>::iterator itl = len.begin();
	std::vector<int>::iterator itw = load.begin();
	std::vector<string>::iterator its = adress.begin();

	for (auto itp = pz.begin(); itl != len.end(), itp != pz.end(), itw != load.end(), its != adress.end(); *itp++, *itl++, *itw++, *its++)
	{
		c.getCar(*itl, *itw, itp->getQuanity(), itp->getLength(), *its);
		cout << "\n";
	}

	delete q, ad;
}

bool loadRow(double ls, double c, int r)
{
	double z = 0.0;
	z = ls / (double)r;

	if (z <= c)
		return true;
	else
		return false;
}

int loadWidth(double it, double w)
{
	if (it == 0)
		return 0;
	else if (it * 3 > (w + 0.2))
		return 2;
	else if (it * 2 > (w + 0.2))
		return 1;
	else if (it * 3 <= (w + 0.2))
		return 3;
	else
		return 2;
}

void EatLine()
{
	cin.clear();
	cin.ignore(255, '\n');
}

void boxloading()
{
	std::vector<double> w;
	std::vector<double> l;
	std::vector<double> h;
	std::vector<int> qun;
	string* q = new string;

	int quanity = 0;
	int row = 0;
	double height = 0.0;
	double length = 0.0;
	double width = 0.0;
	double tq = 0.0;

	Car c1;
	cin >> c1;

	c1.setCubeM();
	cout << "\nYou entered\n";
	cout << c1;
	
	double lengthSum = 0.0;
	double widthSum = 0.0;
	double heightSum = 0.0;

	cout << "Enter quanity and size of boxes you wish to enter:";

	cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	while (cin >> *q && *q != "q")
	{
		cout << "Enter quanity: ";
		cin >> quanity;
		qun.push_back(quanity);
		EatLine();
		if (quanity == 0)
		{
			length = 0;
			width = 0;
			height = 0;
			break;
		}
		cout << "Enter length of boxes: ";
		cin >> length;
		EatLine();
		cout << "Enter width of boxes: ";
		cin >> width;
		EatLine();
		cout << "Enter height of boxes: ";
		cin >> height;
		EatLine();

		w.push_back(width);
		l.push_back(length);
		h.push_back(height);
		cout << "Cube of boxes: " << (length * height * width) * quanity << endl;
		tq += (length * height * width) * quanity;
		cout << "Total cubes of order: " << tq << endl;

		cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	}
	
	vector<double>::iterator itl = l.begin();
	vector<double>::iterator itw = w.begin();
	vector<double>::iterator ith = h.begin();
	vector<int>::iterator itq = qun.begin();

	int rh, rw, rl;
	//Returns how many boxes will be loaded in width
	rw = QunLoadBoxWidth(c1.getWidth(), *itw);
	rh = QunLoadBoxHeigth(c1.getHeight(), *ith);
	rl = QunLoadBoxlength(c1.getLength(), *itl);

	//Returns how many boxes will be loaded in length
	double carLength = ((c1.getLength() * rl));
	double carWidth = ((c1.getWidth() * rw));
	double carHeight = ((c1.getHeight() * rh));

	for (; itl != l.end(); *itl++, *itw++, *ith++, *itq++)
	{
		int QQ = *itq;
		for (int i = 0; i < QQ; i++, QQ -= 3)
		{
			if ((carLength - *itl) > 0.0 && (carWidth - *itw) > 0.0 && (carHeight - *ith) > 0.0)
			{
				carLength -= *itl;
				carWidth -= *itw;
				carHeight -= *ith;
			}
			else if ((carLength - *itl) <= 0.0 && (carWidth - *itl) > 0.0 && (carHeight - *ith) >= 0 && (carLength - *itw) >= 0.0)
			{
				carLength -= *itw;
				carHeight -= *ith;
				carWidth -= *itl;
			}
			else if ((carLength - *itl) > 0.0 && (carHeight - *ith) > 0.0 && (carWidth - *itw) > 0.0)
			{
				carLength -= *itl;
				carHeight -= *ith;
				carWidth -= *itw;
			}
			else if ((carLength - *ith) > 0.0 && (carHeight - *itw) > 0.0 && (carWidth - *itl) > 0.0)
			{
				carLength -= *ith;
				carHeight -= *itw;
				carWidth -= *itl;
			}
			else if ((carLength -= *ith) > 0.0 && (carHeight - *itl) > 0.0 && (carWidth - *itw) > 0.0)
			{
				carLength -= *ith;
				carHeight -= *itl;
				carWidth -= *itw;
			}
			else if ((carLength -= *itl) < 0 && (carLength -= *itw) > 0 && (carWidth -= *itl) > 0 && (carHeight - *ith) > 0)
			{
				carLength -= *itw;
				carWidth -= *itl;
				carHeight -= *ith;
			}
			else if ((carWidth -= *itw) < 0 && (carWidth -= *itl) < 0 && (carWidth -= *ith) > 0 && (carLength -= *itl) > 0 && (carHeight -= *itw) > 0)
			{
				carWidth -= *ith;
				carLength -= *itl;
				carHeight -= *itw;
			}
			else if ((carWidth -= *itw) < 0 && (carWidth -= *ith) < 0 && (carWidth -= *itl) > 0 && (carLength -= *ith) > 0 && (carHeight -= *itw) > 0)
			{
				carWidth -= *itl;
				carLength -= *ith;
				carHeight -= *itw;
			}
			else if ((carHeight -= *ith) < 0 && (carHeight -= *itl) < 0 && (carHeight -= *itw) > 0 && (carLength -= *itl > 0 && (carWidth -= *itw) > 0))
			{
				carHeight -= *itw;
				carLength -= *itl;
				carWidth -= *ith;
			}
			else
			{
				carLength -= *itw;
				carHeight -= *itl;
				carWidth -= *ith;
			}

		}

		if (carLength < 0.0 && carWidth < 0.0 && carHeight < 0.0)
		{
			cout << "Can't be loaded!\n";
			break;
		}

	}
	cout << "Length left: " << (carLength * 0.3) << endl;
	cout << "Width left: " << (carWidth * 0.3) << endl;
	cout << "Height left: " << (carHeight * 0.3) << endl;

	if (carLength < 0 || carHeight < 0 || carWidth < 0)
		cout << "The car hasn't enough size for order!\n";
	else if (carLength > 0.0 && carHeight > 0.0 && carWidth > 0.0)
		cout << "The car has enough size for order!\n";
	else if (carLength == 0)
		cout << "The car has enough size for order!\n";

	delete q;
}

double CarCube(double cLenght, double cWidth, double cHeight)
{
	return cLenght * cWidth * cHeight;
}

//
int QunLoadBoxWidth(double carLength, double boxWidth)
{
	return (carLength / boxWidth);
}

int QunLoadBoxlength(double carLength, double boxLength)
{
	return (carLength / boxLength);
}

int QunLoadBoxHeigth(double carHeight, double boxHeight)
{
	return (carHeight / boxHeight);
}

double cubeBox(double bLength, double bWidth, double bHeight)
{
	return bLength * bWidth * bHeight;
}


void CubeBoxloading()
{
	//amount of car needed for an order
	int qcar = 0;
	//Idk but this should work
	Car c1;

	std::vector<double> w;
	std::vector<double> l;
	std::vector<double> h;
	std::vector<int> qun;
	std::cout << "Enter size of car you wish to load for order\n";
	cin >> c1;

	string* q = new string;

	double cube = 0.0;
	int quanity = 0;
	double tq = 0.0;

	//Car data

	cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	while (cin >> *q && *q != "q")
	{
		cout << "Enter quanity: ";
		cin >> quanity;
		qun.push_back(quanity);
		EatLine();

		cout << "Enter cubes of boxes: ";
		cin >> cube;
		EatLine();

		BoxSize(CubOneBox(quanity, cube));
		cout << "Cube is " << (_length * _width * _height) * quanity << endl;
		tq += (_length * _width * _height) * quanity;
		cout << "Total cube is " << tq << endl;
		w.push_back(_width);
		l.push_back(_length);
		h.push_back(_height);

		vector<double>::iterator itl = l.begin();
		vector<double>::iterator itw = w.begin();
		vector<double>::iterator ith = h.begin();
		vector<int>::iterator itq = qun.begin();

		double hs, ws, ls;
		ws = QunLoadBoxWidth(c1.getWidth(), *itw);
		hs = QunLoadBoxHeigth(c1.getHeight(), *ith);
		ls = QunLoadBoxlength(c1.getLength(), *itl);


		double carHeight = ((c1.getHeight() * hs));
		double carLength = ((c1.getLength() * ls));
		double carWidth = ((c1.getWidth() * ws));

		//Remake later
		
		for (; itl != l.end(); itl++, itw++, ith++, itq++)
		{
			int QQ = *itq;
			for(int i = 0; i < QQ; i++, QQ -= 3)
			{ 
			if (carLength < 0.00 && carHeight < 0.00 && carWidth < 0.00)
			{
				qcar++;
				carHeight = ((c1.getHeight() * hs));
				carLength = ((c1.getLength() * ls));
				carWidth = ((c1.getWidth() * ws));
			}

			if ((carLength - *itl) <= 0.0 && (carWidth - *itl) > 0.0 && (carHeight - *ith) >= 0 && (carLength - *itw) >= 0.0)
			{
				carLength -= *itw;
				carHeight -= *ith;
				carWidth -= *itl;
			}
			else if((carLength - *itl) >= 0.0 && (carHeight - *ith) >= 0.0 && (carWidth - *itw) >= 0.0)
			{
				carLength -= *itl;
				carHeight -= *ith;
				carWidth -= *itw;
			}
			else if((carLength - *ith) >= 0.0 && (carHeight - *itw) >= 0.0 && (carWidth - *itl) >= 0.0)
			{
				carLength -= *ith;
				carHeight -= *itw;
				carWidth -= *itl;
			}
			else if ((carLength -= *ith) >= 0.0 && (carHeight - *itl) >= 0.0 && (carWidth - *itw) >= 0.0)
			{
				carLength -= *ith;
				carHeight -= *itl;
				carWidth -= *itw;
			}
			else
			{
				carLength -= *itw;
				carHeight -= *itl;
				carWidth -= *ith;
			}
			}
		}
		cout << "Enter 'p' to process entering the data, 'q' for stop\n";
		_length = 0.0;
		_width = 0.0;
		_height = 0.0;
	}


	_length = 0.0;
	_width = 0.0;
	_height = 0.0;
	cout << "\nChecking how many car(s) you need for an order...\n";
	Sleep(500);

	if (qcar == 0)
	{
		cout << 1 << " car(s) you need to deliver this order!\n";
	}
	else
	cout << qcar << " car(s) you need to deliver this order!\n";
}

double CubOneBox(int quanity, double cube)
{
	return cube / quanity;
}

void BoxSize(double n)
{
	
	while ((_length * _width * _height) < n)
	{
		_length += 0.0015;
		_width += 0.0010;
		_height += 0.0010;
	}

;
	cout << "Length of one box ~" << _length << endl;
	cout << "Width of one box ~" << _width << endl;
	cout << "Height of one box ~" << _height << endl;
}

int CarQuanOrder(double l, double h, double w, double cl, double ch, double cw)
{
	int q = 0;
	q = round((abs(l / cl) + abs(w / cw) + abs(h / ch)) / 3);
	return q;
}

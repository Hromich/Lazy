#include "Lazylogistician.h"
//using namespace std;

Car::Car(double l, double w, double m, double h)
{
	cubeMetr = m;
	length = l;
	width = w;
	height = h;
}

Car::Car(const Car& c)
{
	cubeMetr = c.cubeMetr;
	length = c.length;
	width = c.width;
	height = c.height;
}

void Car::setCubeM()
{
	cubeMetr = length * width;
}

bool Car::loadWidth()
{
	if (Pallet::getWidthSize() <= width)
		return true;
	else
		return false;
}

void Car::setWidthArea()
{
	if (Pallet::getWidthSize() < 1.20)
		palletRow = 3;
	else if (Pallet::getWidth() >= 1.30)
		palletRow = 2;
	else
		palletRow = 2;
}

void Car::setSloadQ()
{
	SloadQ = Sload * Pallet::getLength();
}

bool Car::multiMachLoad()
{
	if (SloadQ < getLength())
		return true;
	else
		return false;
}

void Car::setSload()
{
	Sload = (Pallet::getQuanity() / (double)palletRow);
}


std::istream& operator>>(std::istream& is, Car& s)
{
	std::cout << "Enter length of car in meters: ";
	is >> s.length;
	std::cout << "Enter width of car in meters: ";
	is >> s.width;
	std::cout << "Enter height of car in meter: ";
	is >> s.height;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Car& s)
{
	os << "Length of car is " << s.length << "\t" << " Width of car is " << s.width << "\n";
	os << "Hieght of car is " << s.height << std::endl;
	os << "CubeMeters of car is " << s.length * s.width * s.height << "\n";
	return os;
}


Pallet::Pallet(double l, double w, double c, double h, int q)
{
	p_length = l;
	p_width = w;
	p_height = h;
	p_cubeMetr = c;
	quanity = q;
}

Pallet::Pallet(const Pallet& p)
{
	p_length = p.p_length;
	p_width = p.p_width;
	p_cubeMetr = p.p_cubeMetr;
	p_height = p.p_height;
	quanity = p.quanity;
}

void Pallet::setCubeMetr()
{
	p_cubeMetr = p_length * p_width * p_height;
}

std::istream& operator>>(std::istream& is, Pallet& s)
{
	try
	{
		std::cout << "Enter length of pallet in meters: ";
		is >> s.p_length;

		if (!is)
			throw 1;
	}
	catch (int x)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << '\a'; //in case of Breakfast!
		std::cout << "Please enter length of pallet again: ";
		is >> s.p_length;
	}
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	try
	{
		std::cout << "Enter width of pallet in meters: ";
		is >> s.p_width;

		if (!is)
			throw 2;
	}
	catch (int e)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << '\a'; //in case of Breakfast!
		std::cout << "Please enter width of pallet again: ";
		is >> s.p_width;
	}
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	try
	{
		std::cout << "Enter height of pallet in meters: ";
		is >> s.p_height;

		if (!is)
			throw 2;
	}
	catch (int e)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << '\a'; //in case of Breakfast!
		std::cout << "Please enter height of pallet again: ";
		is >> s.p_height;
	}
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	try
	{
		std::cout << "Enter how much pallet(s) do you wish to load: ";
		is >> s.quanity;

		if (!is)
			throw 3;
	}
	catch (int z)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << '\a'; //in case of Breakfast!
		std::cout << "Please enter numbers of pallet again: ";
		is >> s.quanity;
	}
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return is;
}

std::ostream& operator<<(std::ostream& os, const Pallet& s)
{
	os << "The length of pallet is " << s.p_length << "\n";
	os << "The width of pallet is " << s.p_width << "\n";
	os << "The height of pallet is " << s.p_height << "\n";
	os << "The quanity of pallet is " << s.quanity << "\n";
	os << "The cube metr of pallets is " << s.p_length * s.p_width * s.quanity << "\n";

	return os;
}


void CarCatalogue::getCar(double l, int w, double q, double pl, std::string ad)
{
	//int loadwidth = getLoadWidth(w, q);
	double length = 0.0;
	//int unsigned fileSeq = 0;
	//std::ifstream seqFileIn;
	//std::ofstream seqFileOut;

	
	//seqFileIn.open("sequeceFile.txt", std::ios::in);
	// If "sequenceFile.txt" exists, read the last sequence from it and increment it by 1.
	//if (seqFileIn.is_open())
	//{
	//	seqFileIn >> fileSeq;
	//	fileSeq++;
	//}
	//else
		//fileSeq = 1; // if it does not exist, start from sequence 1.

	// Assume newDataAvailable = true
	//bool newDataAvailable = true;

	//if (newDataAvailable) {
		std::fstream fout;
		fout.open("Order.txt", std::ofstream::app);
		//std::string fileName = "Order.txt"; //+ std::to_string(fileSeq) + 
		//std::string fileName = "afile" + std::to_string(fileSeq) + ".txt";

		//cout << "File Name is " << fileName << endl;

		
		//fout.open("Order.txt", std::ofstream::out | std::ofstream::trunc);
		//afile << "Blah blah blah! File sequence is " << fileSeq << "\n";
		//afile.close();
	//}

	//std::fstream fout;
	//std::string v = "Order ¹" + fileSeq;
	//fout.open(v);

	static CarPorter p;
	static CarEuroTrack e;
	static CarGazel g;
	static CarMersedesSprinter ms;
	static CarFiveTonCar f;
	static CarTenTonCar t;
	
	while(l >= 0)
	{ 
		l = l / w;
		if (q >= 15)
		{	
			e.quanity += 1;
			l -= e.length;
			q -= ((int)(e.length / pl) * w);

			//e.quanity = 0;
		}

		else if (l <= p.length && q <= 3)
		{
			//p.quanity += (l / p.length) + 0.2;
			//l = 0.0;
			//l = l / w;
			p.quanity += 1;
			l -= p.length;
			q -= ((int)(p.length / pl) * w);

			//p.quanity = 0;
		}

		else if (l <= ms.length && q >= 3 && q == 4)
		{
			//ms.quanity += (l / ms.length) + 0.5;
			//l = 0.0;
			//l = l / w;
			ms.quanity += 1;
			l -= ms.length;
			q -= ((int)(ms.length / pl) * w);

			//ms.quanity = 0;
		}

		else if (l <= g.length && q <= 6)
		{
			//g.quanity += (l / g.length) + 0.5;
			//l = 0.0;
			//l = l / w;
			g.quanity += 1;
			l -= g.length;
			q -= ((int)(g.length / pl) * w);

			//g.quanity = 0;

		}

		else if (l <= f.length && q <= 13 && q >= 7)
		{
			//f.quanity += (l / f.length) + 0.5;
			//l = 0.0;
			//if (f.quanity == 0)
				//f.quanity = 1;
			//l = l / w;
			f.quanity += 1;
			l -= f.length;
			q -= ((int)(f.length / pl) * w);

			//f.quanity = 0;
		}

		else if (l <= t.length && q <= 15 && q >= 7)
		{
			//t.quanity += (l / t.length) + 0.5;
			//l = 0.0;
			//if (t.quanity == 0)
				//t.quanity = 1;
			//l = l / w;
			t.quanity += 1;
			l -= t.length;
			q -= ((int)(t.length / pl) * w);

			//t.quanity = 0;
		}
		else
			exit(3); //std::cout << "Fisting is 300$" << std::endl; 
	}

	fout << ad << "\n";
	if( p.quanity != 0)
	{ 
	std::cout << "Order " << ad << std::endl;
	std::cout << p.quanity << " porter(s) you need!" << std::endl;
	fout << p.quanity << " porter\n";
	p.quanity = 0;
	}

	if (e.quanity != 0)
	{
		std::cout << "Order " << ad << std::endl;
	std::cout << e.quanity << " euro track(s) you need!" << std::endl;
	fout << e.quanity << " eurotrack\n";
	e.quanity = 0;
	}

	if (ms.quanity != 0)
	{ 
		std::cout << "Order " << ad << std::endl;
	std::cout << ms.quanity << " Mers(s) you need!" << std::endl;
	fout << ms.quanity << " mersedes sprinter\n";
	ms.quanity = 0;
	}

	if (g.quanity != 0)
	{ 
		std::cout << "Order " << ad << std::endl;
	std::cout << g.quanity << " Gazel(s) you need!" << std::endl;
	fout << g.quanity << " gazel\n";	
	g.quanity = 0;
	}

	if(f.quanity != 0)
	{ 
		std::cout << "Order " << ad << std::endl;
		std::cout << f.quanity << " Five ton car you need!" << std::endl;
		fout << f.quanity << " five ton car\n";
		f.quanity = 0;
	}

	if (t.quanity != 0)
	{
		std::cout << "Order " << ad << std::endl;
		std::cout << t.quanity << " Ten ton car you need!" << std::endl;
		fout << t.quanity << " ten ton car\n";
		t.quanity = 0;
	}
	
	// Before you exit your program, do not forget to store the last file sequence in "sequeceFile.txt".
	//seqFileOut.open("sequeceFile.txt", std::ios::out);
	//seqFileOut << fileSeq;
	fout.close();
}


void CarCatalogue::fileclear()
{
	std::fstream fout;
	fout.open("Order.txt", std::ofstream::out | std::ofstream::trunc);
	fout.close();
}

int CarCatalogue::getLoadWidth(double wp, int q)
{
	static CarPorter p;
	static CarEuroTrack e;
	static CarGazel g;
	static CarMersedesSprinter ms;
	static CarFiveTonCar f;
	static CarTenTonCar t;

	//eurotrack
	if (q > 4 && q > 12)
	{
		if ((wp * 3) <= e.width + 0.4)
		{
			return 3;
		}
		else if ((wp * 3) > e.width + 0.4)
		{
			return 2;
		}
		else if ((wp * 2) <= e.width + 0.4)
		{
			return 2;
		}
		else if ((wp * 3) > e.width + 0.4)
		{
			return 4;
		}
		else
			return 2;
	}


	//Porter
	if (q < 4)
	{
		if ((wp * 2) <= p.width)
		{
			return 2;
		}
		else if ((wp * 2) > p.width)
		{
			return 1;
		}
		else if ((wp * 3) > p.width)
		{
			return 1;
		}
		else
			return 1;
	}

	//TenTonCar and FiveTonCar
	if (q > 4 && q < 14)
	{
		if ((wp * 3) <= t.length + 0.4)
		{
			return 3;
		}
		else if ((wp * 3) > t.length + 0.4)
		{
			return 2;
		}
		else if ((wp * 2) <= t.length + 0.4)
		{
			return 2;
		}
		else if ((wp * 3) > t.length + 0.4)
		{
			return 4;
		}
		else
			return 2;
	}

	//Mers
	if (q > 4 &&  q < 6)
	{
		if ((wp * 2) <= ms.width)
		{
			return 2;
		}
		else if ((wp * 2) > ms.width)
		{
			return 1;
		}
		else if ((wp * 3) > ms.width)
		{
			return 1;
		}
		else
			return 1;
	}

	//gazel
	if (q > 4 && q <= 8)
	{
		if ((wp * 3) <= ms.width)
		{
			return 3;
		}
		else if ((wp * 2) > ms.width)
		{
			return 2;
		}
		else if ((wp * 3) > ms.width)
		{
			return 2;
		}
		else
			return 3;
	}
}
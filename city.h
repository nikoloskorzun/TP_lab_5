#pragma once
#include "lib.h"
using namespace std;



typedef struct City
{
	
	string name;
	double cargo_size;
	double delicery_hours;


} City;


inline std::ostream& operator<<(std::ostream& os, City& c)
{
	os << c.name << endl;
	os << c.cargo_size << endl;
	os << c.delicery_hours << endl;


	return os;


}

inline std::ostream& City_show(std::ostream& os, City& c)
{
	os << "        Name: ";
	os << c.name << endl;
	os << "        Cargo size: ";
	os << c.cargo_size << endl;
	os << "        Delicery hours: ";
	os << c.delicery_hours << endl;


	return os;


}


#include "lib.h"

using namespace std;
Plane::Plane() {
	type = " ";
	name = " ";
	cargo_volume = 0;
	cargo_size = 0;
	cities;

	cout << "<Constructor Plane without parameters was called>" << endl;

}

Plane::Plane(string type) {

	this->type = type;

	cout << "<Constructor Plane with parameters was called>" << endl;

}

Plane::Plane(const Plane& plane_copy)
{
	cout << "<Copy constructor Plane was called>" << endl;
	type = plane_copy.type;
	name = plane_copy.name;
	cargo_volume = plane_copy.cargo_volume;
	cargo_size = plane_copy.cargo_size;
	cities = plane_copy.cities;

}
Plane::~Plane()
{
	cout << "<Destructor Plane was called>" << endl;

}



void Plane::set_type(string type) {
	this->type = type;
}
void Plane::set_name(string name) {
	this->name = name;
}
void Plane::set_cargo_volume(double cargo_volume) {
	this->cargo_volume = cargo_volume;
}
void Plane::set_cargo_size(double cargo_size) {
	this->cargo_size = cargo_size;
}
void Plane::set_cities(List<City> route) {
	this->cities = route;
}



string Plane::get_type() const{
	return type;
}
string Plane::get_name() const {
	return name;
}
double Plane::get_cargo_volume() const {
	return cargo_volume;
}
double Plane::get_cargo_size() const {
	return cargo_size;
}
List<City> Plane::get_cities() const {
	return cities;
}



void Plane::show() {

	cout << "-------------------------------" << endl;
	cout << "Plane" << endl;
	cout << "	Type: " << type << endl;
	cout << "	Name: " << name << endl;
	cout << "	Cargo volume: " << cargo_volume << endl;
	cout << "	Cargo size: " << cargo_size << endl;
	Route_show(cout, cities);

}
void Plane::saving() {
	ofstream fout;
	string initfile = IO_FILENAME;
	fout.open(initfile, ios_base::app);
	if (!fout)
	{
		throw ERROR_MESSAGE_OPEN_FILE_ERROR;
		system("pause");
		exit(1);
	}
	else
	{
		fout << "2" << endl << type << endl << name << endl << cargo_volume << endl << cargo_size << endl << cities << endl;
		fout.close();
	}

}

void Plane::rewrite()
{

	cout << "-------------------------------" << endl;
	cout << "Plane" << endl;

	cout << "	Input type: " << endl;
	cin >> type;
	cout << "	Input name: " << endl;
	cin >> name;
	cout << "	Input cargo volume: " << endl;
	cin >> cargo_volume;
	cout << "	Input cargo size: " << endl;
	cin >> cargo_size;
	cout << "	Input cities: " << endl;
	Route_input(cin, cities);
	//cin >> cities;


}

void Plane::redact(List<City> route) {


	this->cities = route;
	

}


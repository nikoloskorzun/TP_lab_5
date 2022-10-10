#include "lib.h"


Car::Car() {
	cout << "<Constructor Car without parameters was called>" << endl;
	brand = " ";
	model = " ";
	year_of_issue = 0;
	cities;
	

}

Car::Car(string model) {
	
	cout << "<Constructor Car with parameters was called>" << endl;

	this->model = model;

}

Car::Car(const Car& car_copy)
{
	cout << "<Copy constructor Car was called>" << endl;
	brand = car_copy.brand;
	model = car_copy.model;
	year_of_issue = car_copy.year_of_issue;
	cities = car_copy.cities;

}
Car::~Car()
{
	cout << "<Destructor Car was called>" << endl;
	

}

void Car::set_brand(string brand) {
	this->brand = brand;
}
void Car::set_model(string model) {
	this->model = model;
}
void Car::set_year_of_issue(uint32_t year_of_issue) {
	this->year_of_issue = year_of_issue;
}
void Car::set_cities(List<City> route) {
	this->cities = route;

}


string Car::get_brand() const {
	return brand;
}
string Car::get_model() const {
	return model;

}
uint32_t Car::get_year_of_issue() const {
	return year_of_issue;

}
List<City> Car::get_cities() const {
	return cities;

}

void Car::show() {
	cout << "-------------------------------" << endl;
	cout << "Car" << endl;
	cout << "	Model: "<<model<<endl;
	cout << "	Brand: "<<brand << endl;
	cout << "	Year of issue: "<<year_of_issue << endl;
	Route_show(cout, cities);
	

}
void Car::saving() {
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
		fout << "1" << endl << model << endl << brand << endl << year_of_issue << endl << cities << endl;
		fout.close();
	}

}

void Car::rewrite()
{

	cout << "-------------------------------" << endl;
	cout << "Car" << endl;

	cout << "	Input model: " << endl;
	cin >> model;
	cout << "	Input brand: " << endl;
	cin >> brand;
	cout << "	Input year of issue: " << endl;
	cin >> year_of_issue;
	cout << "	Input cities: " << endl;
	Route_input(cin, cities);


}

void Car::redact(List<City> route) {


	this->cities = route;


}


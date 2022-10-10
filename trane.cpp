#include "lib.h"

using namespace std;
Trane::Trane() {

	name = " ";
	year_of_issue = 0;
	count_railway_carriage = 0;
	cargo_size = 0;
	route;



	cout << "<Constructor Trane without parameters was called>" << endl;

}

Trane::Trane(string name) {

	this->name = name;

	cout << "<Constructor Trane with parameters was called>" << endl;

}

Trane::Trane(const Trane& trane_copy)
{
	cout << "<Copy constructor Trane was called>" << endl;
	name = trane_copy.name;
	year_of_issue = trane_copy.year_of_issue;
	count_railway_carriage = trane_copy.count_railway_carriage;
	cargo_size = trane_copy.cargo_size;
	route = trane_copy.route;

}
Trane::~Trane()
{
	cout << "<Destructor Trane was called>" << endl;

}



void Trane::set_name(string name) {
	this->name = name;
}
void Trane::set_year_of_issue(uint32_t year_of_issue) {
	this->year_of_issue = year_of_issue;
}
void Trane::set_count_railway_carriage(uint32_t count_railway_carriage) {
	this->count_railway_carriage = count_railway_carriage;
}
void Trane::set_cargo_size(double cargo_size) {
	this->cargo_size = cargo_size;
}
void Trane::set_route(List<City> route) {
	this->route = route;
}


string Trane::get_name() const {
	return name;
}
uint32_t Trane::get_year_of_issue() const {
	return year_of_issue;
}
uint32_t Trane::get_count_railway_carriage() const {
	return count_railway_carriage;
}
double Trane::get_cargo_size() const {
	return cargo_size;
}
List<City> Trane::get_route() const {
	return route;
}





void Trane::show() {

	cout << "-------------------------------" << endl;
	cout << "Trane" << endl;

	cout << "	Name: " << name << endl;
	cout << "	Year of issue: " << year_of_issue << endl;
	cout << "	Count railway carriage: " << count_railway_carriage << endl;
	cout << "	Cargo size: " << cargo_size << endl;
	Route_show(cout, route);


}
void Trane::saving() {
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
		fout << "3" << endl << name << endl << year_of_issue << endl << count_railway_carriage << endl << cargo_size << endl << route << endl;
		fout.close();
	}

}

void Trane::rewrite()
{

	cout << "-------------------------------" << endl;
	cout << "Trane" << endl;

	cout << "	Input name: " << endl;
	cin >> name;
	cout << "	Input year of issue: " << endl;
	cin >> year_of_issue;
	cout << "	Input count railway carriage: " << endl;
	cin >> count_railway_carriage;
	cout << "	Input cargo size: " << endl;
	cin >> cargo_size;
	cout << "	Input route: " << endl;
	Route_input(cin, route);


}

void Trane::redact(List<City> route) {

	
	this->route = route;

}


void Trane::draw()
{

	cout << "    #          ";
	for (uint32_t i = 0; i < count_railway_carriage; i++)
	{
		cout << RAILWAY_CARRIAGE_1;
	}
	cout<<endl;
	cout << "    #   ###### ";
	for (uint32_t i = 0; i < count_railway_carriage; i++)
	{
		cout << RAILWAY_CARRIAGE_2 ;
	}
	cout << endl;
	cout << "  /####### ### ";
	for (uint32_t i = 0; i < count_railway_carriage; i++)
	{
		cout << RAILWAY_CARRIAGE_3 ;
	}	cout << endl;
	cout << " /############-";

	for (uint32_t i = 0; i < count_railway_carriage; i++)
	{
		cout << RAILWAY_CARRIAGE_4 ;
	}	cout << endl;
	cout << "/© © ©      ©© ";

	for (uint32_t i = 0; i < count_railway_carriage; i++)
	{
		cout << RAILWAY_CARRIAGE_5 ;
	}	cout << endl;

}


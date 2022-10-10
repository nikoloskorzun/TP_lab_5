#include "lib.h"
using namespace std;
Keeper::Keeper()
{
	
	size = 0;
	head = nullptr;
}
Keeper::Keeper(int size) :head(nullptr)
{
	this->size = size;
}
Keeper::~Keeper() {
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Carrier();
			delete(buffer);
		}
		head->data->~Carrier();
		delete(head);
	}
}
int Keeper::get_size()
{
	return size;
}
Carrier* Keeper::operator[] (const int index)
{
	if ((index >= size) || (index < 0))
	{
		throw ERROR_MESSAGE_INCORRECT_INDEX;
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->data);
	}
}
void Keeper::insert(Carrier* n_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (size == 0) {
		tmp->data = n_data;
		tmp->next = 0;
		++size;
	}
	else {
		tmp->data = n_data;
		tmp->next = head;
		++size;
	}
	head = tmp;
}
void Keeper::remove(int index)
{
	if (size == 0) {
		throw ERROR_MESSAGE_EMPTY;
	}
	int cnt = 0;
	while (cnt < index - 1)
	{
		head = head->next;
		cnt++;
	}
	if (index == 0)
	{
		size--;
		head->data->~Carrier();
		head = head->next;
		return;
	}
	Elem* prev = head;
	prev->next->data->~Carrier();
	prev->next->next;
	delete(prev->next);
	--size;
}
void Keeper::save()
{
	ofstream fout;
	string initfile = IO_FILENAME;
	fout.open(initfile, ios_base::trunc);
	if (!fout)
	{
		throw ERROR_MESSAGE_OPEN_FILE_ERROR;
		system("pause");
		exit(1);
	}
	else
	{
		fout << size << endl;
		fout.close();
	}
	Elem* buf = head;
	for (int i = 0; i < size; i++) {
		buf->data->saving();
		buf = buf->next;
	}
}
void Keeper::load()
{
	setlocale(LC_ALL, "Russian");
	/*if (size != 0)
	{
		Elem* buffer;
		

		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Carrier();
			delete(head);
		}


		head->data->~Carrier();
		delete(head);
		
	}
	*/
	ifstream fin;
	string initfile = IO_FILENAME;
	Carrier* transports;
	int fsize;// для считывания количества объектов в файле
	int num_type;//1- машина, 2- самолет, 3= поезд

	string plane_type;
	string plane_name;
	double plane_cargo_volume;
	double plane_cargo_size;
	List<City> plane_cities;

	string car_brand;
	string car_model;
	uint32_t car_year_of_issue;
	List<City> car_cities;

	string trane_name;
	uint32_t trane_year_of_issue;
	uint32_t trane_count_railway_carriage;
	double trane_cargo_size;
	List<City> trane_route;

	fin.open(initfile, ios_base::in);
	if (!fin) {
		throw ERROR_MESSAGE_OPEN_FILE_ERROR;
		system("pause");
		exit(1);
	}
	fin >> fsize;

	for (int i = 0; i < fsize; i++) {
		fin >> num_type;
		//fin.ignore(32767, '\n');
		if (num_type == 1) {

			fin >> car_brand >> car_model >> car_year_of_issue >> car_cities;
			
			Car* car;
			car = new Car;
			car->set_brand(car_brand);
			car->set_model(car_model);
			car->set_year_of_issue(car_year_of_issue);
			car->set_cities(car_cities);
			transports = car;
			insert(transports);
		}
		if (num_type == 2) {
			fin >> plane_type >> plane_name >> plane_cargo_volume >> plane_cargo_size>> plane_cities;

			Plane* plane;
			plane = new Plane;
			plane->set_type(plane_type);
			plane->set_name(plane_name);
			plane->set_cargo_volume(plane_cargo_volume);
			plane->set_cargo_size(plane_cargo_size);
			plane->set_cities(plane_cities);

			transports = plane;
			insert(transports);
		}
		if (num_type == 3)
		{

			fin >> trane_name >> trane_year_of_issue >> trane_count_railway_carriage >> trane_cargo_size >> trane_route;

			Trane* trane;
			trane = new Trane;
			trane->set_name(trane_name);
			trane->set_year_of_issue(trane_year_of_issue);
			trane->set_count_railway_carriage(trane_count_railway_carriage);
			trane->set_cargo_size(trane_cargo_size);
			trane->set_route(trane_route);

			transports = trane;
			insert(transports);
		}

		fin.ignore(32767, '\n');
	}
}
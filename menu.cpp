#include "lib.h"
using namespace std;

void Menu::main_menu()
{
	while (exit == 1) {
		switch (show_options())
		{
		case 1:
			show_all_transport();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_transport();
			break;
		case 7:
			exit_from_programm();
			break;
		
		}
	}
}
int Menu::show_options()
{

	int c1;
	cout << "	Select action:" << endl;
	cout << "1 - Show all transport" << endl;
	cout << "2 - Edit data" << endl;
	cout << "3 - Add transport" << endl;
	cout << "4 - Save in file: \"" << IO_FILENAME<<"\"" << endl;
	cout << "5 - Load from file: \"" << IO_FILENAME << "\"" << endl;
	cout << "6 - Delete transport" << endl;
	
	cout << "7 - Exit" << endl;
	cin >> c1;
	return c1;
}

void Menu::show_all_transport()
{
	try
	{
		if (list.get_size() == 0) {
			throw ERROR_MESSAGE_EMPTY;
		}
		for (int i = 0; i < list.get_size(); i++) {
			list[i]->show();
		}
	}
	catch (const char* er)
	{
		cout << er << endl;
		cout << ERROR_MESSAGE_EXCEPTION_HANDLED << endl;
	}

}

void Menu::change_data()
{
	//#TODO
	int c2;
	try
	{
		cout << "What transport do you want to change?" << endl;
		cout << "Input number from 1 to " << list.get_size() << endl;
		cin >> c2;
		if (c2<1 || c2>list.get_size()) {
			throw ERROR_MESSAGE_INCORRECT_INDEX;
		}
		list[c2 - 1]->show();
		cout << "	Select action:" << endl;
		cout << "1 - Change all options" << endl;
		cout << "2 - Change route only" << endl;
		int par;
		
		cin >> par;
		switch (par) {
		case 1:
			cout << "Ñhange: " << endl;
			list[c2 - 1]->rewrite();
			break;
		case 2:
			List<City> r;
			
			cin >> r;
			list[c2 - 1]->redact(r);


			break;
		}
		cout << "Data changed." << endl;

	}
	catch (const char* err)
	{
		cout << err << endl;
		cout << ERROR_MESSAGE_EXCEPTION_HANDLED << endl;
	}

}


void Menu::add_new()
{
	int c3;
	cout << "What transport needs to be added?" << endl;
	cout << "1 - Car" << endl;
	cout << "2 - Plane" << endl;
	cout << "3 - Trane" << endl;
	cin >> c3;
	switch (c3) {
	case 1:
		Car * car;
		car = new Car;
		transports = car;
		car->rewrite();
		list.insert(transports);
		break;
	case 2:
		Plane * plane;
		plane = new Plane;
		transports = plane;
		plane->rewrite();
		list.insert(transports);
		break;	
	case 3:
		Trane * trane;
		trane = new Trane;
		transports = trane;
		trane->rewrite();
		list.insert(transports);
		break;


	default:
		break;
	}
	cout << "New transport has been added!" << endl;
}
void Menu::save_to_file()
{
	try
	{
		if (list.get_size() == 0) {
			throw ERROR_MESSAGE_EMPTY;
		}
		list.save();
		cout << "Data saved into file \""<< IO_FILENAME <<"\"" << endl;
	}
	catch (...)
	{
		cout << ERROR_MESSAGE_EXCEPTION_THROW << endl;
		cout << ERROR_MESSAGE_EXCEPTION_HANDLED << endl;
	}

}
void Menu::load_from_file()
{
	list.load();
	cout << "Data extracted from file \"" << IO_FILENAME << "\"" << endl;
}
void Menu::delete_transport()
{
	int c4;
	try
	{
		if (list.get_size() == 0) {
			throw ERROR_MESSAGE_EMPTY;
		}
	}
	catch (...)
	{
		cout << ERROR_MESSAGE_EXCEPTION_THROW << endl;
		cout << ERROR_MESSAGE_EXCEPTION_HANDLED << endl;
	}

	cout << "What transport needs to be deleted?" << endl;
	cout << "Input number from 1 to " << list.get_size() << endl;
	
	try
	{
		cin >> c4;
		if (c4<1 || c4>list.get_size())
		{
			throw ERROR_MESSAGE_INCORRECT_INDEX;
		}
		list.remove(list.get_size() - c4);
		cout << "Selected transport removed" << endl;

	}
	catch (...)
	{
		cout << ERROR_MESSAGE_EXCEPTION_THROW << endl;
		cout << ERROR_MESSAGE_EXCEPTION_HANDLED << endl;
	}

}

void Menu::exit_from_programm()
{
	exit = 0;
}
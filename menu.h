#pragma once

#include "lib.h"
class Menu {
protected:
	Keeper list;
	Carrier* transports;
	int flag_draw_train = 0;
	int exit = 1;
public:
	void main_menu();
	int show_options();
	void show_all_transport();
	void change_data();
	void add_new();
	void save_to_file();
	void load_from_file();
	void delete_transport();
	void exit_from_programm();
};
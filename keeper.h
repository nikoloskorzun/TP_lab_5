#pragma once
#include "lib.h"
using namespace std;

class Keeper {
private:
	int size;
	Elem* head = nullptr;
public:
	Keeper();
	Keeper(int size);
	~Keeper();
	int get_size();
	Carrier* operator[] (const int index);

	void insert(Carrier* n_data);
	void remove(int index);
	void save();
	void load();
};

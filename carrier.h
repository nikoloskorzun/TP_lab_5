#pragma once


#include "lib.h"

using namespace std;

class Carrier
{
public:
    Carrier() {};
    virtual ~Carrier() {};
	virtual void show() = 0;
	virtual void saving() = 0;
	virtual void rewrite() = 0;
	virtual void redact(List<City> route) = 0;
	
	

};
typedef struct Elem
{
    Carrier* data;
    Elem* next;
} Elem;

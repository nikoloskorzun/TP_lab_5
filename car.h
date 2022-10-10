#pragma once
#include "lib.h"
using namespace std;

class Car : public Carrier
{
public:
	Car();
	Car(string model);
	Car(const Car& car_copy);

	~Car();

	void set_brand(string brand);
	void set_model(string model);
	void set_year_of_issue(uint32_t year_of_issue);
	void set_cities(List<City> route);

	string get_brand() const;
	string get_model() const;
	uint32_t get_year_of_issue() const;
	List<City> get_cities() const;

	virtual void show() override;
	virtual void saving() override;
	virtual void rewrite() override;
	void redact(List<City> route) override;




private:
	string brand;
	string model;
	uint32_t year_of_issue;
	List<City> cities;
};
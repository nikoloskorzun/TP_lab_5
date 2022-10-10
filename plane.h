#pragma once
#include "lib.h"
using namespace std;

class Plane : public Carrier
{
public:
	Plane();
	Plane(string type);
	Plane(const Plane& plane_copy);

	~Plane();

	void set_type(string type);
	void set_name(string name);
	void set_cargo_volume(double cargo_volume);
	void set_cargo_size(double cargo_size);
	void set_cities(List<City> route);

	string get_type() const;
	string get_name() const;
	double get_cargo_volume() const;
	double get_cargo_size() const;
	List<City> get_cities() const;

	

	virtual void show() override;
	virtual void saving() override;
	virtual void rewrite() override;
	void redact(List<City> route) override;




private:
	string type;
	string name;
	double cargo_volume;
	double cargo_size;
	List<City> cities;
};
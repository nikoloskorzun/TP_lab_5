#pragma once
#include "lib.h"
using namespace std;

class Trane : public Carrier
{
public:
	Trane();
	Trane(string type);
	Trane(const Trane& trane_copy);

	~Trane();

	void set_name(string name);
	void set_year_of_issue(uint32_t year_of_issue);
	void set_count_railway_carriage(uint32_t count_railway_carriage);
	void set_cargo_size(double cargo_size);
	void set_route(List<City> route);

	string get_name() const;
	uint32_t get_year_of_issue() const;
	uint32_t get_count_railway_carriage() const;
	double get_cargo_size() const;
	List<City> get_route() const;



	virtual void show() override;
	virtual void saving() override;
	virtual void rewrite() override;
	void redact(List<City> route) override;


	void draw();

private:
	string name;
	uint32_t year_of_issue;
	uint32_t count_railway_carriage;
	double cargo_size;
	List<City> route;
};


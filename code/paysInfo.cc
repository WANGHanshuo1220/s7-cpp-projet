#include "paysInfo.hh"
#include<sstream>

paysInfo::paysInfo(string _name, int surface, int population):
name(_name),surface(surface), population(population)
{
	name = _name;
}

paysInfo::~paysInfo(){}

double paysInfo::prediction() const
{
	return 0.0;
}


string paysInfo::evaluation() const
{
	stringstream out;
	out << name << " a " << surface << "surface avec" << population << "population";
	return out.str();
}

string paysInfo::show_name() const
{
	return name;
}

int paysInfo::show_surface() const
{
	return surface;
}

int paysInfo::show_population() const
{
	return population;
}
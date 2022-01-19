#pragma once
#include<iostream>
#include<string>

using namespace std;

class pays
{
public:
	pays(){}
	pays(string name);
	//pays(pays &_pays);
	~pays();

	//Cinq fonctions virtuelles pures pour l'impression d'informations
	virtual int show_surface() const = 0;
	virtual int show_population() const = 0;
	virtual string show_name() const = 0;
	virtual double prediction() const = 0;
	virtual string evaluation() const = 0;
protected:
	string name;
};
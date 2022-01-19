#pragma once
#include"pays.hh"

class paysInfo : public pays
{
public:
	paysInfo();
	paysInfo(string _name, int surface, int population);

	/*Cinq fonctions d'impression d'informations, 
	 *couvrant les fonctions virtuelles pures de la classe parente
	 */
	double prediction() const;
	string evaluation() const;
	string show_name() const;
	int show_surface() const;
	int show_population() const;

	~paysInfo();
protected:
	string name;
	int surface;
	int population;
};
#pragma once
#include<iostream>
#include<string>
#include"militaire.hh"
#include "paysInfo.hh"

using namespace std;

class navales: public militaire
{
public:
	navales(pays &_pays, int popultaion_na, int nb_navire, int rank_na, int depense_na);
	~navales();

	/*Ces cinq fonctions sont des fonctions virtuelles de la classe parente, 
	 *elles sont couvertes ici
	 */
	string show_name() const;
	double prediction() const;
	string evaluation() const;
	int show_surface() const;
	int show_population() const;

	/*Cette fonction est utilisée pour produire l'évaluation d'un pays 
	 *et la prévision future du pays
	 */
	friend ostream& operator<<(ostream & out, navales &a);
	//Ces trois fonctions permettent de comparer la force d'economie entre deux pays
	friend bool operator<(navales &pays_1, navales &pays_2);
	friend bool operator>(navales &pays_1, navales &pays_2);
	friend bool operator==(navales &pays_1, navales &pays_2);

private:
	int population_na;
	int nb_navire;
	int rank_na;
	int depense_na;
};
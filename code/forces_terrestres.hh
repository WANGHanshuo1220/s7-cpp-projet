#pragma once
#include<iostream>
#include<string>
#include"militaire.hh"
#include "paysInfo.hh"

using namespace std;

class terrestres: public militaire
{
public:
	terrestres(pays &_pays, int population_te, int nb_tank, int rank_te, int depense_te);
	~terrestres();

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
	friend ostream& operator<<(ostream & out, terrestres &a);
	//Ces trois fonctions permettent de comparer la force de terrestres entre deux pays
	friend bool operator<(terrestres &pays_1, terrestres &pays_2);
	friend bool operator>(terrestres &pays_1, terrestres &pays_2);
	friend bool operator==(terrestres &pays_1, terrestres &pays_2);

private:
	int population_te;
	int nb_tank;
	int rank_te;
	int depense_te;
};
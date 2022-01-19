#pragma once
#include<iostream>
#include<string>
#include"militaire.hh"
#include "paysInfo.hh"

using namespace std;

class aeriennes: public militaire
{
public:
	aeriennes(pays &_pays, int population_ae, int nb_avion, int rank_ae, int depense_ae);
	~aeriennes();

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
	friend ostream& operator<<(ostream & out, aeriennes &a);
	//Ces trois fonctions permettent de comparer la force d'aeriennes entre deux pays
	friend bool operator<(aeriennes &pays_1, aeriennes &pays_2);
	friend bool operator>(aeriennes &pays_1, aeriennes &pays_2);
	friend bool operator==(aeriennes &pays_1, aeriennes &pays_2);

private:
	int population_ae;
	int nb_avion;
	int rank_ae;
	int depense_ae;
};
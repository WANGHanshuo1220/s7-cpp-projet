#pragma once
#include"pays.hh"
#include "paysInfo.hh"
#include<sstream>

class technologie : public pays
{
public:
	technologie(pays &_pays, double frais_aug, double tech_population_aug, double rank_universite);
	~technologie();

	//Fonction d'impression des informations
	double show_frais_aug() {return frais_aug;}
	double show_tech_population_aug() {return tech_population_aug;}
	double show_rank_universite() {return rank_universite;}

	/*Ces cinq fonctions sont des fonctions virtuelles de la classe parente, 
	 *elles sont couvertes ici
	 */
	double prediction() const;
	string evaluation() const;
	string show_name() const;
	int show_surface() const;
	int show_population() const;

	/*Cette fonction est utilisée pour produire l'évaluation d'un pays 
	 *et la prévision future du pays
	 */
	friend ostream& operator<<(ostream& out, technologie &pays);
	//Ces trois fonctions permettent de comparer la force de technologie entre deux pays
	friend bool operator<(technologie &pays_1, technologie &pays_2);
	friend bool operator>(technologie &pays_1, technologie &pays_2);
	friend bool operator==(technologie &pays_1, technologie &pays_2);
private:
	pays &_pays;
	double frais_aug;
	double tech_population_aug;
	double rank_universite;
};
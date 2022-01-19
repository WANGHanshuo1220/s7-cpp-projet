#pragma once
#include"pays.hh"
#include "paysInfo.hh"
#include<sstream>

class economie : public pays
{
public:
	economie(pays &_pays,double PIB_speed, double IPC_fluctuation, double Taux_emploi);
	~economie();

	//Fonction d'impression des informations
	double show_PIB_speed(){return PIB_speed;}
	double show_IPC_fluctuation(){return IPC_fluctuation;}
	double show_Taux_emploi(){return Taux_emploi;}

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
	friend ostream& operator<<(ostream& out, economie &pays);
	//Ces trois fonctions permettent de comparer la force économique entre deux pays
	friend bool operator<(economie &pays_1, economie &pays_2);
	friend bool operator>(economie &pays_1, economie &pays_2);
	friend bool operator==(economie &pays_1, economie &pays_2);

private:
	pays &_pays;
	double PIB_speed;
	double IPC_fluctuation;
	double Taux_emploi;
};
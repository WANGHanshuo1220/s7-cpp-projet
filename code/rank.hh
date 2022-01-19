#pragma once
#include"pays.hh"
#include"militaire.hh"
#include"economie.hh"
#include"technologie.hh"
#include"forces_navales.hh"
#include"forces_terrestres.hh"
#include"forces_aeriennes.hh"
#include<vector>
#include<map>

using namespace std;


class ranks
{
public:
	ranks(vector<technologie> des_pays);
	~ranks();
	//Trouvez le pays avec le taux de croissance futur le plus élevé
	string Meilleur_pays();
	//Tous les joueurs du vecteur sont triés en fonction de leur future valeur prédite
	vector<pair<string, float>> sort_pays();

private:
	vector<technologie> _des_pays;
};
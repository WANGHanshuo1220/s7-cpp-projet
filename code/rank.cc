#include"rank.hh"
#include <algorithm>

typedef pair<string, float> PAIR;

//Définir une structure pour comparer les valeurs prédites
struct CmpValue{
	bool operator()(const PAIR& lhs, const PAIR& rhs){
		return lhs.second < rhs.second;
	}
};

ranks::ranks(vector<technologie> des_pays):_des_pays(des_pays){}

ranks::~ranks(){}

//Trier par prévisions de pays
vector<pair<string, float>> ranks::sort_pays()
{
	map<string, float> technologie_rank;
	//Stockez le nom du pays et la valeur prévue correspondante dans le map
	for(auto &i:_des_pays)
	{
		technologie_rank.insert(pair<string,float>(i.show_name(),i.prediction()));
	}
	//Convertir le map en vecteur
	vector<PAIR> technologie_rank_vector(technologie_rank.begin(), technologie_rank.end());
	//Utilisez une structure personnalisée pour trier les éléments dans le vecteur
	sort(technologie_rank_vector.begin(), technologie_rank_vector.end(), CmpValue());

	return technologie_rank_vector;
}


string ranks::Meilleur_pays()
{
	//Fonction de classe d'appel
	vector<pair<string, float>> rank = sort_pays();
	stringstream out;

	cout << "pays\t" << "prediction\t"<< endl;

	//Imprimer les informations de commande de pays triées
	for(auto i:rank)
	{
		cout << i.first << "\t" << i.second << "\t" << endl;
	}
	//Imprimer le nom du pays avec la meilleure valeur prévue
	cout << "le Meilleur_pays est: " << rank[0].first << " avec " << rank[0].second << endl; 

	return rank[0].first;
}

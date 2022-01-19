#include"forces_navales.hh"

navales::navales(pays &_pays, int population_na, int nb_navire, int rank_na, int depense_na):
militaire(_pays), population_na(population_na), nb_navire(nb_navire), rank_na(rank_na), depense_na(depense_na)
{
	name = _pays.show_name();
}

navales::~navales(){}

double navales::prediction() const
{
	//Nous avons personnalisé une combinaison linéaire pour prédire l'avenir
	double tauxDeCroissant = 0.0;
	tauxDeCroissant = (depense_na*0.5 + rank_na*0.1 + nb_navire*0.2 + population_na*0.2)/
	                  (depense_na + rank_na + nb_navire + population_na);
	return tauxDeCroissant;
}

string navales::evaluation() const
{
	//Faire une évaluation basée sur la situation actuelle dans ce pays
	string s;
	s += to_string(population_na);
	s += " soldats et ";
	s += to_string(nb_navire);
	s += " réservoirs dans la marine; ";
	s += "\nLes dépenses de la marine cette année sont de ";
	s += to_string(depense_na);
	s += " euros; Classement mondial: ";
	s += to_string(rank_na);

	return s;
}

string navales::show_name() const
{
	return _pays.show_name();
}

int navales::show_surface() const
{
	return _pays.show_surface();
}

int navales::show_population() const
{
	return _pays.show_population();
}

ostream& operator<<(ostream & out, navales &a)
{
	out << a.show_name() << ":\n" << a.evaluation() << "\n" << "Taux de croissance estimé: " << a.prediction() << endl;
	return out;
}

bool operator<(navales &pays_1, navales &pays_2)
{
	if(pays_1.prediction()<pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator>(navales &pays_1, navales &pays_2)
{
	if(pays_1.prediction() > pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator==(navales &pays_1, navales &pays_2)
{
	if(pays_1.prediction() == pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}
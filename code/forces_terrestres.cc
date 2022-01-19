#include"forces_terrestres.hh"

terrestres::terrestres(pays &_pays, int population_te, int nb_tank, int rank_te, int depense_te):
militaire(_pays), population_te(population_te), nb_tank(nb_tank), rank_te(rank_te), depense_te(depense_te)
{
	name = _pays.show_name();
}

terrestres::~terrestres(){}

double terrestres::prediction() const
{
	//Nous avons personnalisé une combinaison linéaire pour prédire l'avenir
	double tauxDeCroissant = 0.0;
	tauxDeCroissant = (depense_te*0.5 + rank_te*0.1 + nb_tank*0.2 + population_te*0.2)/
	                  (depense_te + rank_te + nb_tank + population_te);
	return tauxDeCroissant;
}

string terrestres::evaluation() const
{
	//Faire une évaluation basée sur la situation actuelle dans ce pays
	string s;
	s += to_string(population_te);
	s += " soldats et ";
	s += to_string(nb_tank);
	s += " réservoirs dans l'armée de terre; ";
	s += "\nLes dépenses de l’armée de terre cette année sont de ";
	s += to_string(depense_te);
	s += " euros; Classement mondial: ";
	s += to_string(rank_te);

	return s;
}

string terrestres::show_name() const
{
	return _pays.show_name();
}

int terrestres::show_surface() const
{
	return _pays.show_surface();
}

int terrestres::show_population() const
{
	return _pays.show_population();
}

ostream& operator<<(ostream & out, terrestres &a)
{
	out << a.show_name() << ":\n" << a.evaluation() << "\n" << "Taux de croissance estimé: " << a.prediction() << endl;
	return out;
}

bool operator<(terrestres &pays_1, terrestres &pays_2)
{
	if(pays_1.prediction()<pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator>(terrestres &pays_1, terrestres &pays_2)
{
	if(pays_1.prediction() > pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator==(terrestres &pays_1, terrestres &pays_2)
{
	if(pays_1.prediction() == pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}
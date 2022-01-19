#include"forces_aeriennes.hh"

aeriennes::aeriennes(pays &_pays, int population_ae, int nb_avion, int rank_ae, int depense_ae):
militaire(_pays),population_ae(population_ae), nb_avion(nb_avion), rank_ae(rank_ae), depense_ae(depense_ae)
{
	name = _pays.show_name();
}

aeriennes::~aeriennes(){}

double aeriennes::prediction() const
{
	//Nous avons personnalisé une combinaison linéaire pour prédire l'avenir
	double tauxDeCroissant = 0.0;
	tauxDeCroissant = (depense_ae*0.5 + rank_ae*0.1 + nb_avion*0.2 + population_ae*0.2)/
	                  (depense_ae + rank_ae + nb_avion + population_ae);
	return tauxDeCroissant;
}

string aeriennes::evaluation() const
{
	//Faire une évaluation basée sur la situation actuelle dans ce pays
	string s;
	s += to_string(population_ae);
	s += " soldats et ";
	s += to_string(nb_avion);
	s += " réservoirs dans l'armée de l'air; ";
	s += "\nLes dépenses de l’armée de l'air cette année sont de ";
	s += to_string(depense_ae);
	s += " euros; Classement mondial: ";
	s += to_string(rank_ae);

	return s;
}

string aeriennes::show_name() const
{
	return _pays.show_name();
}

int aeriennes::show_surface() const
{
	return _pays.show_surface();
}

int aeriennes::show_population() const
{
	return _pays.show_population();
}

ostream& operator<<(ostream & out, aeriennes &a)
{
	out << a.show_name() << ":\n" << a.evaluation() << "\n" << "Taux de croissance estimé: " << a.prediction() << endl;
	return out;
}

bool operator<(aeriennes &pays_1, aeriennes &pays_2)
{
	if(pays_1.prediction()<pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator>(aeriennes &pays_1, aeriennes &pays_2)
{
	if(pays_1.prediction() > pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator==(aeriennes &pays_1, aeriennes &pays_2)
{
	if(pays_1.prediction() == pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}
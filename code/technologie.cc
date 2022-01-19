#include"technologie.hh"

technologie::technologie(pays &_pays, double frais_aug, double tech_population_aug, double rank_universite):
_pays(_pays),frais_aug(frais_aug),tech_population_aug(tech_population_aug),rank_universite(rank_universite){}


technologie::~technologie(){}


double technologie::prediction() const
{
	//Nous avons personnalisé une combinaison linéaire pour prédire l'avenir
	return (frais_aug*0.4 + tech_population_aug*0.4 + rank_universite*0.2)*10;
}


string technologie::evaluation() const
{
	//Faire une évaluation basée sur la situation actuelle dans ce pays
	stringstream now;
	now << "   Le frais_aug est:" << frais_aug << "\n";
	now << "   Le tech_population_aug est:" << tech_population_aug <<"\n";
	now << "   Le rank_universite est:" << rank_universite << "\n";
	if(frais_aug<0.2 || tech_population_aug < 0.3)
	{
		now << "   Faibles perspectives de développement technologique!";
	}else
	{
		now << "   Bonnes perspectives d'évolution technologique et les perspectives de développement sont bonnes!";
	}
	return now.str();
}

string technologie::show_name() const
{
	return _pays.show_name();
}

int technologie::show_surface() const
{
	return _pays.show_surface();
}

int technologie::show_population() const
{
	return _pays.show_population();
}

ostream& operator<<(ostream& out, technologie &pays)
{
	out << "->" << pays.show_name() << endl;
	out << " @ pour l'instante:\n" << pays.evaluation() << endl;
	out << " @ pour la future,le potentiel de croissance est:" << pays.prediction() << endl;
	return out;
}


bool operator<(technologie &pays_1, technologie &pays_2)
{
	if(pays_1.prediction()<pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator>(technologie &pays_1, technologie &pays_2)
{
	if(pays_1.prediction() > pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator==(technologie &pays_1, technologie &pays_2)
{
	if(pays_1.prediction() == pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}
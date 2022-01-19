#include"economie.hh"

economie::economie(pays &_pays,double PIB_speed, double IPC_fluctuation, double Taux_emploi):
_pays(_pays),PIB_speed(PIB_speed),IPC_fluctuation(IPC_fluctuation),Taux_emploi(Taux_emploi){}

economie::~economie(){}


double economie::prediction() const
{
	//Nous avons personnalisé une combinaison linéaire pour prédire l'avenir
	return (PIB_speed*0.5 + IPC_fluctuation*0.2 + Taux_emploi*0.3)/(PIB_speed + IPC_fluctuation + Taux_emploi);
}


string economie::evaluation() const
{
	//Faire une évaluation basée sur la situation actuelle dans ce pays
	stringstream now;
	now << "   Le PIB_speed est:" << PIB_speed << "\n";
	now << "   Le IPC_fluctuation est:" << IPC_fluctuation <<"\n";
	now << "   Le taux de croissance de l'emploi est:" << Taux_emploi << "\n";
	if(IPC_fluctuation>0.2 || Taux_emploi < 0.3 || PIB_speed <=0)
	{
		now << "   Conditions économiques instables!";
	}else
	{
		now << "   La situation économique est stable et les perspectives de développement sont bonnes!";
	}
	return now.str();
}

string economie::show_name() const
{
	return _pays.show_name();
}

int economie::show_surface() const
{
	return _pays.show_surface();
}

int economie::show_population() const
{
	return _pays.show_population();
}


ostream& operator<<(ostream& out, economie &pays)
{
	out << "->" << pays.show_name() << endl;
	out << " @ pour l'instante:\n" << pays.evaluation() << endl;
	out << " @ pour la future,le potentiel de croissance est: " << pays.prediction() << endl;
	out << endl;
	return out;
}


bool operator<(economie &pays_1, economie &pays_2)
{
	if(pays_1.prediction()<pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator>(economie &pays_1, economie &pays_2)
{
	if(pays_1.prediction() > pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}


bool operator==(economie &pays_1, economie &pays_2)
{
	if(pays_1.prediction() == pays_2.prediction())
	{
		return true;
	}else
	{
		return false;
	}
}
#pragma once
#include"pays.hh"
#include"paysInfo.hh"

class militaire : public pays
{
public:
	//militaire();
	militaire(pays &country);
	~militaire();

	/*Ces cinq fonctions héritent de la classe parente 
	 *et sont toujours de pures fonctions virtuelles
	 */	
	virtual int show_surface() const = 0;
	virtual int show_population() const = 0;
	virtual string show_name() const = 0;
	virtual double prediction() const = 0;
	virtual string evaluation() const = 0;
protected:
	pays &_pays;
};
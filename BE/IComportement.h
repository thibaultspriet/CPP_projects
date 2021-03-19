#ifndef DEF_ICOMPORTEMENT
#define DEF_ICOMPORTEMENT

#include <vector>
#include <iostream>
#include <string>
#include "Bestiole.h"
#include <tuple>

class Bestiole;

// diff�rents types de comportements possibles
enum ComportType
{
	GREG,
	KAMIK,
	MULTI,
	PEUR,
	PREV,
};

class IComportement {
	public :
	// fonction virtuelle permettant de r�cup�rer le vecteur directeur de vitesse et le coefficient multiplicateur de la valeur de la vitesse
	virtual std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) = 0;
	IComportement() {};
	virtual ~IComportement() {};
	// fonction virtuelle permettant de r�cup�rer le type de comportement de l'�num�ration ci-dessus
	virtual ComportType getComportementType() = 0;
};


#endif
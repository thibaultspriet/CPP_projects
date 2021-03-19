#ifndef DEF_ICOMPORTEMENT
#define DEF_ICOMPORTEMENT

#include <vector>
#include <iostream>
#include <string>
#include "Bestiole.h"
#include <tuple>

class Bestiole;

// différents types de comportements possibles
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
	// fonction virtuelle permettant de récupérer le vecteur directeur de vitesse et le coefficient multiplicateur de la valeur de la vitesse
	virtual std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) = 0;
	IComportement() {};
	virtual ~IComportement() {};
	// fonction virtuelle permettant de récupérer le type de comportement de l'énumération ci-dessus
	virtual ComportType getComportementType() = 0;
};


#endif
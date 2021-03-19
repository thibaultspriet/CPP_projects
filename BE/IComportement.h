#ifndef DEF_ICOMPORTEMENT
#define DEF_ICOMPORTEMENT

#include <vector>
#include <iostream>
#include <string>
#include "Bestiole.h"
#include <tuple>

class Bestiole;

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
	virtual std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) = 0;
	IComportement() {};
	virtual ~IComportement() {};
	virtual ComportType getComportementType() = 0;
};


#endif
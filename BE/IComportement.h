#ifndef DEF_ICOMPORTEMENT
#define DEF_ICOMPORTEMENT

#include <vector>
#include <iostream>
#include <string>
#include "Bestiole.h"
#include <tuple>

class IComportement {
	public :
	virtual std::tuple<vector<double, double>, double> calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee) = 0;
};

#endif
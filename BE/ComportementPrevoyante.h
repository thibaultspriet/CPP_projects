#ifndef DEF_COMPORTEMENTPREVOYANTE
#define DEF_COMPORTEMENTPREVOYANTE

#include <vector>
#include <iostream>
#include "IComportement.h"

class ComportementPrevoyante : public IComportement {
	public:
	ComportementPrevoyante();
	~ComportementPrevoyante();
	std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return PREV; };
};

#endif

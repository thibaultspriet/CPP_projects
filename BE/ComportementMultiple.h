#ifndef DEF_COMPORTEMENTMULTIPLE
#define DEF_COMPORTEMENTMULTIPLE

#include <iostream>
#include "IComportement.h"
#include "ComportementPeureuse.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPrevoyante.h"
#include <vector>

class ComportementMultiple : public IComportement {
	private:
	vector<IComportement*> comportements;
	IComportement* comportementActif;
	int m_tempsAvant;
	static const int m_tempsEntreDeux = 10;

	public:
	ComportementMultiple();
	~ComportementMultiple();
	std::tuple<vector<double>,double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return MULTI; };

};

#endif

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
	vector<IComportement*> comportements; // vecteur qui contient tous les autres types de comportements
	IComportement* comportementActif; // comportement actuel de la bestiole associée
	int m_tempsAvant; // temps avant futur changement de comportement 
	static const int m_tempsEntreDeux = 10; // temps entre deux changements de comportement (fixé à 10)

	public:
	ComportementMultiple();
	~ComportementMultiple();
	std::tuple<vector<double>,double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return MULTI; };

};

#endif

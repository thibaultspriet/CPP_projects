#include "ComportementPeureuse.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

ComportementPeureuse::ComportementPeureuse(int seuil) : IComportement() {
	m_seuil = seuil;
	cout << "construct comp PEUR" << endl;
}

ComportementPeureuse::ComportementPeureuse() :IComportement()
{
	// on initialise al�atoirement le seuil si le client ne l'indique pas dans le constructeur
	m_seuil = rand() % 4 + 1;
	cout << "construct comp PEUR" << endl;
}

ComportementPeureuse::~ComportementPeureuse()
{
	cout << "destruct Comportement PEUR" << endl;
}

pair<vector<double>, double> ComportementPeureuse::calculDirection(vector<ICreature*> voisins, ICreature& creatureAssociee) {
	// si le nb de voisins est sup�rieur au seuil, la bestiole prend la direction inverse de ses voisins 2 fois plus vite
	if (voisins.size() >= m_seuil) {
		vector<double> moyenne_direction(2);
		double moyenne_direction_x = 0;
		double moyenne_direction_y = 0;
		// calcul de la moyenne de direction de ses voisins
		for (int i = 0; i < voisins.size(); i++) {
			moyenne_direction_x += voisins.at(i)->getDirection()[0];
			moyenne_direction_y += voisins.at(i)->getDirection()[1];
		}
		moyenne_direction_x = moyenne_direction_x / voisins.size();
		moyenne_direction_y = moyenne_direction_y / voisins.size();
		moyenne_direction[0] = - moyenne_direction_x;
		moyenne_direction[1] = - moyenne_direction_y;
		return make_pair(moyenne_direction, 2);
	}
	// sinon, la bestiole part avec la m�me direction et m�me vitesse que pr�c�demment
	else {
		return make_pair(creatureAssociee.getDirection(), 1);
	}
}

// m�thode permettant de r�cup�rer le seuil
int ComportementPeureuse::getSeuil() {
	return m_seuil;
}
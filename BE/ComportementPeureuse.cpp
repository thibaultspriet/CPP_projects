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
	// si le nb de voisins est sup�rieur au seuil, la bestiole prend la direction opposée 2 fois plus vite
	if (voisins.size() >= m_seuil) {
		// calcul de la moyenne de direction de ses voisins
		vector<double> direction_inverse = creatureAssociee.getDirection();
		direction_inverse.at(0) *= -1;
		direction_inverse.at(1) *= -1;
		return make_pair(direction_inverse, 2);
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
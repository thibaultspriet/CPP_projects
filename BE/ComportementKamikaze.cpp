#include "ComportementKamikaze.h"

#include <iostream>
#include <vector>

using namespace std;

// coefficient multiplicateur = 3
const int ComportementKamikaze::m_coefAttaque = rand() % 3 + 1;
//const int ComportementKamikaze::m_coefAttaque = 3;

ComportementKamikaze::ComportementKamikaze() : IComportement() {
	cout << "construct Comportement KAMIK" << endl;
}

ComportementKamikaze::~ComportementKamikaze() {
	cout << "destruct Comportement KAMIK" << endl;
}

pair<vector<double>, double> ComportementKamikaze::calculDirection(vector<ICreature*> voisins, ICreature& creatureAssociee) {
	// si la bestiole n'a pas de voisins, elle repart dans la m�me direction et � la m�me vitesse que pr�c�demment
	if (voisins.size() == 0)
	{
		return make_pair(creatureAssociee.getDirection(), 1);
	}
	// sinon, la bestiole part dans la direction de la bestiole la plus proche pour l'attaquer (avec le coefficient d'attaque)
	else {
		int positionBestiole_x = creatureAssociee.getX();
		int positionBestiole_y = creatureAssociee.getY();
		// tableau qui contiendra la distance de chaque voisin � la bestiole
		//vector<int> distanceVoisins(voisins.size());
		double min = 1.79769e+308; // maximum double c++
		int argmin = -1;
		for (int i = 0; i < voisins.size(); i++) {
			double distanceVoisins = calculDistance(voisins.at(i)->getX(), voisins.at(i)->getY(), positionBestiole_x, positionBestiole_y);
			if (distanceVoisins < min) {
				min = distanceVoisins;
				argmin = i;
			}
		}
		return make_pair(voisins.at(argmin)->getDirection(), m_coefAttaque);
	}
}

double calculDistance(int xA, int yA, int xB, int yB) {
	return sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
}
#include "ComportementKamikaze.h"

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// coefficient multiplicateur = 3
const int ComportementKamikaze::m_coefAttaque = 3;

ComportementKamikaze::ComportementKamikaze() : IComportement() {
	cout << "construct Comportement KAMIK" << endl;
}

ComportementKamikaze::~ComportementKamikaze() {
	cout << "destruct Comportement KAMIK" << endl;
}

tuple<vector<double>, double> ComportementKamikaze::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) {
	// si la bestiole n'a pas de voisins, elle repart dans la même direction et à la même vitesse que précédemment
	if (voisins.size() == 0)
	{
		return make_tuple(bestioleAssociee.getDirection(), 1);
	}
	// sinon, la bestiole part dans la direction de la bestiole la plus proche pour l'attaquer (avec le coefficient d'attaque)
	else {
		int positionBestiole_x = bestioleAssociee.getX();
		int positionBestiole_y = bestioleAssociee.getY();
		// tableau qui contiendra la distance de chaque voisin à la bestiole
		vector<int> distanceVoisins(voisins.size());
		double min = 1.79769e+308; // maximum double c++
		int argmin = -1;
		for (int i = 0; i < voisins.size(); i++) {
			distanceVoisins[i] = calculDistance(voisins.at(i)->getX(), voisins.at(i)->getY(), positionBestiole_x, positionBestiole_y);
			if (distanceVoisins[i] < min) {
				min = distanceVoisins[i];
				argmin = i;
			}
		}
		return make_tuple(voisins.at(argmin)->getDirection(), m_coefAttaque);
	}
}

double calculDistance(int xA, int yA, int xB, int yB) {
	return sqrt((xB - xA) * (xB - xA + (yB - yA) * (yB - yA)));
}
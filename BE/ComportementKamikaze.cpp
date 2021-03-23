#include "ComportementKamikaze.h"

#include <iostream>
#include <vector>

using namespace std;

const int ComportementKamikaze::m_coefAttaque = rand() % 3 + 1;

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
		double min = 1.79769e+308; // maximum double c++
		int argmin = -1;
		for (int i = 0; i < voisins.size(); i++) {
			double distanceVoisins = calculDistance(voisins.at(i)->getX(), voisins.at(i)->getY(), positionBestiole_x, positionBestiole_y);
			if (distanceVoisins < min) {
				min = distanceVoisins;
				argmin = i;
			}
		}
		vector<double> vecteur_creatures = vecteurEntreDeuxPoints(positionBestiole_x, positionBestiole_y,voisins.at(argmin)->getX(),voisins.at(argmin)->getY());
		vecteur_creatures.at(0) /= min;
		vecteur_creatures.at(1) /= min;
		return make_pair(vecteur_creatures, m_coefAttaque);
	}
}

double calculDistance(int xA, int yA, int xB, int yB) {
	return sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
}

vector<double> vecteurEntreDeuxPoints(int xA, int yA, int xB, int yB) {
	vector<double> vecteurAB(2);
	vecteurAB[0] = xB - xA;
	vecteurAB[1] = yB - yA;
	return vecteurAB;
}
#include "ComportementGregaire.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

ComportementGregaire::ComportementGregaire() : IComportement() {
	cout << "construct comp GREG" << endl;
}

ComportementGregaire::~ComportementGregaire() {
	cout << "destruct Comportement GREG" << endl;
}

pair<vector<double>, double> ComportementGregaire::calculDirection(vector<ICreature*> voisins, ICreature& creatureAssociee) {
	// si la bestiole ne poss�de pas de voisins, elle continue son chemin � la m�me vitesse et dans la m�me direction
	if (voisins.size() == 0)
	{
		vector<double> direction = creatureAssociee.getDirection();
		return make_pair(direction, 1);
	}
	// sinon, la bestiole repart dans la direction moyenne de ses voisins et � la m�me vitesse que pr�c�demment
	else {
		double moyenne_direction_x = 0;
		double moyenne_direction_y = 0;
		vector<double> moyenne_direction(2);
		// calcul de la moyenne des directions des voisins de la bestiole
		for (int i = 0; i < voisins.size(); i++) {
			moyenne_direction_x += voisins.at(i)->getDirection()[0];
			moyenne_direction_y += voisins.at(i)->getDirection()[1];
		}
	moyenne_direction_x = moyenne_direction_x / voisins.size();
	moyenne_direction_y = moyenne_direction_y / voisins.size();
	moyenne_direction[0] = moyenne_direction_x;
	moyenne_direction[1] = moyenne_direction_y;
	
	return make_pair(moyenne_direction, 1);
	}
}
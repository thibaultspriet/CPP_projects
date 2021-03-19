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

tuple<vector<double>, double> ComportementGregaire::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) {
	if (voisins.size() == 0)
	{
		vector<double> direction = bestioleAssociee.getDirection();
		return make_tuple(direction, 1);
	}
	else {
		double moyenne_direction_x = 0;
		double moyenne_direction_y = 0;
		vector<double> moyenne_direction(2);
		for (int i = 0; i < voisins.size(); i++) {
			moyenne_direction_x += voisins.at(i)->getDirection()[0];
			moyenne_direction_y += voisins.at(i)->getDirection()[1];
	}
	moyenne_direction_x / voisins.size();
	moyenne_direction_y / voisins.size();
	moyenne_direction[0] = moyenne_direction_x;
	moyenne_direction[1] = moyenne_direction_y;
	return make_tuple(moyenne_direction, 1);
}
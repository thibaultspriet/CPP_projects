#include "ComportementGregaire.h"
#include "IComportement.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

ComportementGregaire::ComportementGregaire() {

}

tuple<vector<double, double>, double> ComportementGregaire::calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee) {
	double moyenne_direction_x = 0;
	double moyenne_direction_y = 0;
	vector<double, double> moyenne_direction;
	for (int i = 0; i < voisins.size(); i++) {
		moyenne_direction_x += voisins[i].getDirection()[0];
		moyenne_direction_y += voisins[i].getDirection()[1];
	}
	moyenne_direction_x / voisins.size();
	moyenne_direction_y / voisins.size();
	moyenne_direction[0] = moyenne_direction_x;
	moyenne_direction[1] = moyenne_direction_y;
	return make_tuple(moyenne_direction, 1);
}
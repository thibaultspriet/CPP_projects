#include "ComportementPeureuse.h"
#include "IComportement.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

ComportementPeureuse::ComportementPeureuse(int seuil): m_seuil(seuil) {

}

tuple<vector<double, double>, double> ComportementPeureuse::calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee) {
	if (voisins.size() >= m_seuil) {
		vector<double, double> moyenne_direction;
		double moyenne_direction_x = 0;
		double moyenne_direction_y = 0;
		for (int i = 0; i < voisins.size(); i++) {
			moyenne_direction_x += voisins[i].getDirection()[0];
			moyenne_direction_y += voisins[i].getDirection()[1];
		}
		moyenne_direction_x / voisins.size();
		moyenne_direction_y / voisins.size();
		moyenne_direction[0] = - moyenne_direction_x;
		moyenne_direction[1] = - moyenne_direction_y;
		return make_tuple(moyenne_direction, 2);
	}
	else {
		return make_tuple(bestioleAssociee.getDirection(), 1);
	}
}
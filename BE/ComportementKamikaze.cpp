#include <iostream>
#include "ComportementKamikaze.h"
#include "IComportement.h"
#include <tuple>
#include <vector>

using namespace std;

ComportementKamikaze::ComportementKamikaze() {

}

tuple<vector<double,double>, double> ComportementKamikaze::calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee) {
	int positionBestiole_x = bestioleAssociee.getX();
	int positionBestiole_y = bestioleAssociee.getY();
	vector<int> distanceVoisins(voisins.size());
	int min = 100000000;
	int argmin = 0;
	for (int i = 0; i < voisins.size(); i++) {
		distanceVoisins[i] = calculDistance(voisins[i].getX(), voisins[i].getY(), positionBestiole_x, positionBestiole_y);
		if (distanceVoisins[i] < min) {
			min = distanceVoisins[i];
			argmin = i;
		}
	}
	return make_tuple(voisins[argmin].getDirection(), m_coefAttaque);

}

double calculDistance(int xA, int yA, int xB, int yB) {
	return sqrt((xB - xA) * (xB - xA + (yB - yA) * (yB - yA)));
}
#include "ComportementPrevoyante.h"
#include <vector>
#include <iostream>

using namespace std;

ComportementPrevoyante::ComportementPrevoyante() : IComportement() {
    // cout << "construct comp PREV" << endl;
}

ComportementPrevoyante::~ComportementPrevoyante() {
    // cout << "destruct Comportement PREV" << endl;
}

pair<vector<double>, double> ComportementPrevoyante::calculDirection(vector<ICreature*> voisins, ICreature& creatureAssociee)
{
    //� r�fl�chir
    return make_pair(creatureAssociee.getDirection(), 1);
}





#include <vector>
#include "ComportementPrevoyante.h"
#include <iostream>
#include <tuple>

using namespace std;

ComportementPrevoyante::ComportementPrevoyante() : IComportement() {
    cout << "construct comp PREV" << endl;
}

ComportementPrevoyante::~ComportementPrevoyante() {
    cout << "destruct Comportement PREV" << endl;
}

tuple<vector<double>, double> ComportementPrevoyante::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    //à réfléchir
    return make_tuple(bestioleAssociee.getDirection(), 1);
}





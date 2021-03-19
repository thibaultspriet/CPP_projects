#include <iostream>
#include "ComportementMultiple.h"
#include <tuple>
#include <vector>

using namespace std;

ComportementMultiple::ComportementMultiple() : IComportement()
{
    comportements = vector<IComportement*>();
    comportements.push_back(new ComportementPeureuse());
    comportements.push_back(new ComportementGregaire());
    comportements.push_back(new ComportementPrevoyante());
    comportements.push_back(new ComportementKamikaze());
    int compChoix = rand() % comportements.size();
    comportementActif = comportements.at(compChoix);
    m_tempsAvant = m_tempsEntreDeux;
    cout << "construct Comportement MULTI" << endl;
}

ComportementMultiple::~ComportementMultiple() {
    for (int i = 0; i < comportements.size(); i++)
    {
        delete comportements.at(i);
    }
    cout << "destruct Comportement MULTI" << endl;
    //comportementActif est déjà détruit
}

tuple<vector<double>, double> ComportementMultiple::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) {
    m_tempsAvant--;
    if (m_tempsAvant <= 0)
    {
        int compChoix = rand() % comportements.size();
        comportementActif = comportements.at(compChoix);
        m_tempsAvant = m_tempsEntreDeux;
    }
    return comportementActif->calculDirection(voisins, bestioleAssociee);
}

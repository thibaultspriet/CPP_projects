#include <iostream>
#include "ComportementMultiple.h"
#include <tuple>
#include <vector>

using namespace std;

ComportementMultiple::ComportementMultiple() : IComportement()
{
    // on initialise la liste des comportements qui contient les autres comportements d�finis
    comportements = vector<IComportement*>();
    comportements.push_back(new ComportementPeureuse());
    comportements.push_back(new ComportementGregaire());
    comportements.push_back(new ComportementPrevoyante());
    comportements.push_back(new ComportementKamikaze());
    // on initialise le comportement actif de fa�on al�atoire
    int compChoix = rand() % comportements.size();
    comportementActif = comportements.at(compChoix);
    // on initialise le temps avant le prochain changement de comportement en lui affectant la valeur du temps entre deux changements de comportement
    m_tempsAvant = m_tempsEntreDeux;
    cout << "construct Comportement MULTI" << endl;
}

ComportementMultiple::~ComportementMultiple() {
    for (int i = 0; i < comportements.size(); i++)
    {
        delete comportements.at(i);
    }
    cout << "destruct Comportement MULTI" << endl;
    //comportementActif est d�j� d�truit
}

tuple<vector<double>, double> ComportementMultiple::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) {
    m_tempsAvant--;
    // si le temps avant le prochain changement de comportement est �coul�, on affecte � la bestiole un nouveau comportement al�atoirement
    if (m_tempsAvant <= 0)
    {
        int compChoix = rand() % comportements.size();
        comportementActif = comportements.at(compChoix);
        // on r� initialise le temps avant le prochain changement de comportement
        m_tempsAvant = m_tempsEntreDeux;
    }
    // on retourne la direction et le coefficient multiplicateur de la vitesse pour le comportement d�sormais actif
    return comportementActif->calculDirection(voisins, bestioleAssociee);
}

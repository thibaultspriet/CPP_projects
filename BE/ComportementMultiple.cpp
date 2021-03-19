#include <iostream>
#include "ComportementMultiple.h"
#include <tuple>
#include <vector>

using namespace std;

ComportementMultiple::ComportementMultiple() : IComportement()
{
    // on initialise la liste des comportements qui contient les autres comportements définis
    comportements = vector<IComportement*>();
    comportements.push_back(new ComportementPeureuse());
    comportements.push_back(new ComportementGregaire());
    comportements.push_back(new ComportementPrevoyante());
    comportements.push_back(new ComportementKamikaze());
    // on initialise le comportement actif de façon aléatoire
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
    //comportementActif est déjà détruit
}

tuple<vector<double>, double> ComportementMultiple::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) {
    m_tempsAvant--;
    // si le temps avant le prochain changement de comportement est écoulé, on affecte à la bestiole un nouveau comportement aléatoirement
    if (m_tempsAvant <= 0)
    {
        int compChoix = rand() % comportements.size();
        comportementActif = comportements.at(compChoix);
        // on ré initialise le temps avant le prochain changement de comportement
        m_tempsAvant = m_tempsEntreDeux;
    }
    // on retourne la direction et le coefficient multiplicateur de la vitesse pour le comportement désormais actif
    return comportementActif->calculDirection(voisins, bestioleAssociee);
}

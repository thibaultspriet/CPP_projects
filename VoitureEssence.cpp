#include <iostream>
#include "VoitureEssence.h"


VoitureEssence::VoitureEssence(){
    cout << "constructeur voiture essence" << endl;
};
void VoitureEssence::fillUp(){
    cout << "Remplir le réservoir d'essence." << endl;
};
VoitureEssence::~VoitureEssence(){
    cout << "Destructeur voiture essence" << endl;
};
#include <iostream>
#include "VoitureEssence.h"


VoitureEssence::VoitureEssence(string color,int number){
    this->setColor(color);
    this->setNumber(number);
};
void VoitureEssence::fillUp(){
    cout << "Remplir le réservoir d'essence." << endl;
};

void VoitureEssence::toString(){
    cout << "Voiture essence - couleur " << this->getColor() << " - numéro " << this->getNumber() << endl;
};

VoitureEssence::~VoitureEssence(){
};
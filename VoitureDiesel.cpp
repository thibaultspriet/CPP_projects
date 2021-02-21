#include <iostream>
#include "VoitureDiesel.h"

VoitureDiesel::VoitureDiesel(string color,int number){
    this->setColor(color);
    this->setNumber(number);
};


void VoitureDiesel::fillUp(){
    cout << "Remplir le réservoir de diésel." << endl;
};

void VoitureDiesel::toString(){
    cout << "Voiture diesel - couleur " << this->getColor() << " - numéro " << this->getNumber() << endl;
};

VoitureDiesel::~VoitureDiesel(){
};


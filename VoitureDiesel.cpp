#include <iostream>
#include "VoitureDiesel.h"

VoitureDiesel::VoitureDiesel(){
    cout << "Constructeur voiture diesel" << endl;
};


void VoitureDiesel::fillUp(){
    cout << "Remplir le réservoir de diésel." << endl;
};

VoitureDiesel::~VoitureDiesel(){
    cout << "Destructeur voiture diesel" << endl;
};


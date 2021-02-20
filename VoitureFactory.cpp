#include "VoitureFactory.h"
using namespace std;
#include <iostream>

VoitureFactory::~VoitureFactory(){
    cout << "destructor factory" << endl;
};

void VoitureFactory::fillUp(){
    Voiture* voiture = this->getVoiture();
    voiture->fillUp();
    delete voiture;
}
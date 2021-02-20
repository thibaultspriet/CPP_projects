#include "VoitureFactory.h"
using namespace std;
#include <iostream>

VoitureFactory::~VoitureFactory(){
    cout << "destructor factory" << endl;
};

void VoitureFactory::fillUp(){
    // Ne connaît pas le type de voiture à l'avance
    Voiture* voiture = this->getVoiture();
    // Mais ce qui compte c'est que chaque voiture puisse faire le plein de carburant
    voiture->fillUp();
    delete voiture;
}
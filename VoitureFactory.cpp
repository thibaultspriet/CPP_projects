#include "VoitureFactory.h"
using namespace std;
#include <iostream>

VoitureFactory::~VoitureFactory(){
    cout << "destructor factory" << endl;
};


string VoitureFactory::getColor(){
    return this->color;
};

int VoitureFactory::getNumber(){
    return this->number;
};

void VoitureFactory::setColor(string color){
    this->color = color;
};

void VoitureFactory::setNumber(int number){
    this->number = number;
}

void VoitureFactory::fillUp(){
    // Ne connaît pas le type de voiture à l'avance
    Voiture* voiture = this->getVoiture();
    // Mais ce qui compte c'est que chaque voiture puisse faire le plein de carburant
    voiture->fillUp();
    delete voiture;
}

void VoitureFactory::getInfo(){
    // Ne connaît pas le type de voiture à l'avance
    Voiture* voiture = this->getVoiture();
    // Mais ce qui compte c'est que chaque "Voiture" puisse donner ses infos
    voiture->toString();
    delete voiture;
}
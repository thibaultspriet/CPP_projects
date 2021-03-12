#include "ConcreteCreatorDiesel.h"
#include "VoitureDiesel.h"


ConcreteCreatorDiesel::ConcreteCreatorDiesel(string color,int number){
    this->setColor(color);
    this->setNumber(number);
};

Voiture* ConcreteCreatorDiesel::getVoiture(){
    return new VoitureDiesel(this->getColor(),this->getNumber());
};
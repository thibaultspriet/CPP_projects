#include "ConcreteCreatorEssence.h"
#include "VoitureEssence.h"


ConcreteCreatorEssence::ConcreteCreatorEssence(string color,int number){
    this->setColor(color);
    this->setNumber(number);
}

Voiture* ConcreteCreatorEssence::getVoiture(){
    return new VoitureEssence(this->getColor(),this->getNumber());
};
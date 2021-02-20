#include "ConcreteCreatorEssence.h"
#include "VoitureEssence.h"


Voiture* ConcreteCreatorEssence::getVoiture(){
    return new VoitureEssence();
};
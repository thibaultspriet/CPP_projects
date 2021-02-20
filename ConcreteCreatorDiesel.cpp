#include "ConcreteCreatorDiesel.h"
#include "VoitureDiesel.h"


Voiture* ConcreteCreatorDiesel::getVoiture(){
    return new VoitureDiesel();
};
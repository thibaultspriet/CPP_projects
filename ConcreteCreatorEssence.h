#ifndef FACTORY
#define FACTORY
#include "VoitureFactory.h"
#endif

class ConcreteCreatorEssence : public VoitureFactory
{
    public:
        Voiture* getVoiture();
};

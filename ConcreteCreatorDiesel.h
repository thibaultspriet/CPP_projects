#ifndef FACTORY
#define FACTORY
#include "VoitureFactory.h"
#endif

class ConcreteCreatorDiesel : public VoitureFactory
{
    public:
        Voiture* getVoiture();
};

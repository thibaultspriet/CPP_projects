#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif

struct VoitureFactory
{
    virtual Voiture* getVoiture() = 0;
    virtual ~VoitureFactory();
    void fillUp();

};

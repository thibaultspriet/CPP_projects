using namespace std;
#include <string>
#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif

class VoitureEssence : public Voiture{

    public:
        VoitureEssence();
        ~VoitureEssence();
        void fillUp();
};
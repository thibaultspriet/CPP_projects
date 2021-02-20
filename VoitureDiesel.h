using namespace std;
#include <string>
#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif

class VoitureDiesel : public Voiture {

    public:
        VoitureDiesel();
        void fillUp();
        ~VoitureDiesel();
};
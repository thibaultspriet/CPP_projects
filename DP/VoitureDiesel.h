using namespace std;
#include <string>
#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif


/*!
Classe qui reprèsente une voiture diesel et qui instancie la classe abstraite voiture.
*/


class VoitureDiesel : public Voiture {

    public:
        /*!
        Constructeur de voiture diesel
        \param color string
        \param number entier
        \return VoitureDiesel une instance
        */
        VoitureDiesel(string color,int number);

        /*!
        simule le remplissage du réservoir
        */
        void fillUp();

        /*!
        print les informations relatives à l'instance
        */
        void toString();

        /*!
        destructeur par défaut
        */
        ~VoitureDiesel();
};
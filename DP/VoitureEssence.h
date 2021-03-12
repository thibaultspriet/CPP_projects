using namespace std;
#include <string>
#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif


/*!
Classe qui reprèsente une voiture essence et qui instancie la classe abstraite voiture.
*/
class VoitureEssence : public Voiture{

    public:

        /*!
        Constructeur de voiture essence
        \param color string
        \param number entier
        \return VoitureEssence une instance
        */
        VoitureEssence(string color,int number);

        /*!
        Destructeur par défaut.
        */
        ~VoitureEssence();

        /*!
        simule le remplissage du réservoir
        */
        void fillUp();

        /*!
        print les informations relatives à l'instance
        */
        void toString();
};
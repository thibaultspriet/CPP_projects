#ifndef FACTORY
#define FACTORY
#include "VoitureFactory.h"
#endif

/*!
Class ConcreteCreatorDiesel qui s'occupe de la création des objets spécifiques VoitureDiesel
*/

class ConcreteCreatorDiesel : public VoitureFactory
{
    public:
        /*!
        Constructeur
        \param color (string)
        \param number (entier)
        */
        ConcreteCreatorDiesel(string color,int number);

        /*!
        Méthode qui crée l'objet voiture diesel
        */
        Voiture* getVoiture();
};

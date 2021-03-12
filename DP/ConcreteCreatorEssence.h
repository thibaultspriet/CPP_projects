#ifndef FACTORY
#define FACTORY
#include "VoitureFactory.h"
#endif

/*!
Class ConcreteCreatorEssence qui s'occupe de la création des objets spécifiques VoitureEssence
*/

class ConcreteCreatorEssence : public VoitureFactory
{
    public:
        /*!
        Constructeur
        \param color (string)
        \param number (entier)
        */
        ConcreteCreatorEssence(string color,int number);

        /*!
        Méthode qui crée l'objet voiture essence
        Retourne un pointeur sur une voiture. Allocation dynamique
        */
        Voiture* getVoiture();
};

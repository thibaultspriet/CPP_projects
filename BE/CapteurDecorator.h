#ifndef _CAPTEUR_DECORATOR_
#define _CAPTEUR_DECORATOR_

#include "CreatureDecorator.h"
#include "ICreature.h"


/**
 * @brief Interface CapteurDecorator
 * 
 * Cette classe défini les méthodes qui peuvent être réimplémentées par les décorateurs capteurs.
 * 
 */
class CapteurDecorator : public CreatureDecorator{

    public:
        /**
         * @brief Méthode jeTeVois.
         * 
         * @param ic créature qui doit être testée
         * @return true 
         * @return false 
         */
        virtual bool jeTeVois(const ICreature & ic) const = 0;

        /**
         * @brief Constructeur de CapteurDecorator
         * 
         * @param ic 
         */
        CapteurDecorator(ICreature* ic) : CreatureDecorator(ic){};

        /**
         * @brief Destructeur de CapteurDecorator
         * 
         */
        virtual ~CapteurDecorator(){};

};

#endif
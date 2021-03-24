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
        CapteurDecorator(ICreature* ic) : CreatureDecorator(ic){/* cout << "const capteur decorator call" << endl; */};

    

        /**
         * @brief Destructeur de CapteurDecorator
         * 
         */
        virtual ~CapteurDecorator() {};


        /**
         * @brief Méthode virtuelle pure
         * 
         * Dans les classes filles (oreille, yeux, nageoire ..) permet de dessiner la créature avec son capteur
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        virtual void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) = 0; 

        /**
         * @brief permet de cloner une créature avec son capteur
         * 
         * @return ICreature* 
         */
        virtual ICreature* clone(void) = 0;

};

#endif
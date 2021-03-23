#ifndef _ACCESSOIRE_DECORATOR_
#define _ACCESSOIRE_DECORATOR_

#include "CreatureDecorator.h"
#include "ICreature.h"


/**
 * @brief Class AccessoireDecorator. 
 * 
 * Cette classe définit les méthodes qui seront réimplémentées par ses classes filles.
 * 
 * Chaque classe fille rédéfini une ou plusieurs méthodes, mais elles ne sont pas obligées de toutes les redéfinir.
 * C'est pourquoi AccessoireDecorator, appelle la méthode de la créature emballée.
 * 
 */
class AccessoireDecorator : public CreatureDecorator{

    public:

        /**
         * @brief méthode getVitesse
         * 
         * @return std::vector<double> 
         */
        virtual std::vector<double> getVitesse() {return CreatureDecorator::getVitesse();} ;

        /**
         * @brief méthode setVitesse
         * 
         * @param vx  vitesse horizontale
         * @param vy vitesse verticale
         */
        virtual void setVitesse(double vx, double vy) {CreatureDecorator::setVitesse(vx,vy);};

        /**
         * @brief Constructeur de AccessoireDecorator
         * 
         * @param ic créature emballée
         */
        AccessoireDecorator(ICreature* ic) : CreatureDecorator(ic){};

        /**
         * @brief Destructeur de AccessoireDecorator
         * 
         */
        virtual ~AccessoireDecorator() {};
        
        /**
         * @brief méthode getCamouflage
         * 
         * @return double 
         */
        virtual double getCamouflage(void) const {return CreatureDecorator::getCamouflage();};

        /**
         * @brief méthode getProbDeath
         * 
         * @return double 
         */
        virtual double getProbDeath(void) const {return CreatureDecorator::getProbDeath();};

        /**
         * @brief Méthode virtuelle pure
         * 
         * Dans les classes filles (oreille, yeux, nageoire ..) permet de dessiner la créature avec son accessoire
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        virtual void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) = 0;

        /**
         * @brief permet de cloner une créature avec son accessoire
         * 
         * @return ICreature* 
         */
        virtual ICreature* clone(void) = 0;

};

#endif
#ifndef _CAMOUFLEGE_DECORATOR_
#define _CAMOUFLEGE_DECORATOR_

#include "AccessoireDecorator.h"


/**
 * @brief Class CamouflageDecorator
 * 
 * Ce decorateur permet à la créature d'être moins visible par les autres.
 * 
 */
class CamouflageDecorator : public AccessoireDecorator{

    protected:
        static const double CAMOUF_MIN; /*!< valeur de camouflage min */
        static const double CAMOUF_MAX; /*!< valeur de camouflage max */

    private:
        double camouflage; /*!< valeur du camouflage de la créature */
    public:
        
        /**
         * @brief Constructeur de CamouflageDecorator
         * 
         * @param ic créature à emballer
         */
        CamouflageDecorator(ICreature* ic);

        /**
         * @brief Copie une créature avec un camouflage
         * 
         * @return ICreature* 
         */
        ICreature* clone(void) override;
        
        /**
         * @brief Destructeur de CamouflageDecorator
         * 
         */
        ~CamouflageDecorator(){};

        /**
         * @brief méthode getCamouflage
         * 
         * @return double 
         */
        double getCamouflage(void) const override final;

        /**
         * @brief Déssine une créature camouflée
         * 
         * La queue a une opacité réduite.
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) override;

};

#endif
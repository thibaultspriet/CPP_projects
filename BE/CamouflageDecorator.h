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

};

#endif
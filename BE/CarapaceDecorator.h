#ifndef _CARAPACE_DECORATOR_
#define _CARAPACE_DECORATOR_

#include "AccessoireDecorator.h"

/**
 * @brief Classe CarapaceDecorator
 * 
 * Ce decorateur permet à la bestiole d'être plus résistante lors d'une collision
 * 
 */
class CarapaceDecorator : public AccessoireDecorator{
    private:
        double protection_death; /*!< facteur qui réduit la probabilité de mourir de la créature */
        double decrease_vitesse; /*!< facteur qui diminue la vitesse de la créature */
    public:

        /**
         * @brief Constructeur de CarapaceDecorator
         * 
         * @param ic créature à emballer
         */
        CarapaceDecorator(ICreature* ic);
        
        /**
         * @brief Destructeur de CarapaceDecorator
         * 
         */
        ~CarapaceDecorator(){};

        /**
         * @brief méthode getVitesse
         * 
         * @return std::vector<double> 
         */
        std::vector<double> getVitesse(void) override;

        /**
         * @brief méthode setVitesse
         * 
         * @param vx vitesse horizontale
         * @param vy vitesse verticale
         */
        void setVitesse(double vx, double vy) override;

        /**
         * @brief méthode getProbDeath
         * 
         * @return double 
         */
        double getProbDeath(void) const override;

};

#endif
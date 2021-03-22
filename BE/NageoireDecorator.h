#ifndef _NAGEOIRE_DECORATOR_
#define _NAGEOIRE_DECORATOR_

#include "AccessoireDecorator.h"


/**
 * @brief Classe NageoireDecorator.
 * 
 * Cette classe permet à la créature emballée de se déplacer plus vite.
 * 
 */
class NageoireDecorator : public AccessoireDecorator{

    protected:
        static const double MULTIPLE_VITESSE_MAX;

    private:
        double multiple_vitesse; /*!< facteur multiplicateur de la vitesse */
    public:

        /**
         * @brief Constructeur de NageoireDecorator
         * 
         * @param ic créature à emballée.
         */
        NageoireDecorator(ICreature* ic);
        
        /**
         * @brief Destructeur de NageoireDecorator
         * 
         */
        ~NageoireDecorator(){};

        /**
         * @brief méthode getVitesse
         * 
         * @return std::vector<double> 
         */
        std::vector<double>  getVitesse() override;

        /**
         * @brief méthode setVitesse
         * 
         * @param vx vitesse horizontale
         * @param vy vitesse verticale
         */
        void setVitesse(double vx, double vy) override;

};

#endif
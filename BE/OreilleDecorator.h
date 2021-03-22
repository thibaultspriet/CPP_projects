#ifndef _OREILLE_DECORATOR_
#define _OREILLE_DECORATOR_

#include "CapteurDecorator.h"

/**
 * @brief Classe OreilleDecorator.
 * 
 * Ce décorateur permet à la créature d'augmenter son champ de vison d'une certaine distance tout autour d'elle.
 * 
 */
class OreilleDecorator : public CapteurDecorator{

    protected:
        static const double DIST_MIN;
        static const double DIST_MAX;
        
        static const double DETECTION_MIN;
        static const double DETECTION_MAX;

    private:
        double distance; /*!< distance à laquelle la créature peut en voir une autre */
        double detection; /*!< probabilité de détection. si detection > camouflage la créature voit l'autre créature. */
    public:

        /**
         * @brief Constructeur de OreilleDecorator
         * 
         * @param ic créature à emballée
         */
        OreilleDecorator(ICreature* ic);
        
        /**
         * @brief Destructeur de OreilleDecorator
         * 
         */
        ~OreilleDecorator(){};

        /**
         * @brief méthode jeTeVois
         * 
         * @param ic créature à tester.
         * @return true 
         * @return false 
         */
        bool jeTeVois(const ICreature & ic) const override final;


};

#endif
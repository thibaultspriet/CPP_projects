#ifndef _YEUX_DECORATOR_
#define _YEUX_DECORATOR_

#include "CapteurDecorator.h"


/**
 * @brief Class YeuxDecorator
 * 
 * Cette classe permet à la créature emballée d'augmenter son champ de vision d'un certain angle sur une certaine distance.
 * 
 */
class YeuxDecorator : public CapteurDecorator{

    protected:
        static const double ALPHA_MIN;
        static const double ALPHA_MAX;

        static const double DIST_MIN;
        static const double DIST_MAX;
        
        static const double DETECTION_MIN;
        static const double DETECTION_MAX;


    private:
        double champVision; /*!< angle du champ de vision */
        double distance; /*!< distance sur laquelle la créature est capable de voir */
        double detection; /*!< probabilité de detection. Si detection > camouflage alors la créature voit l'autre créature */
    public:

        /**
         * @brief Constructeur de YeuxDecorator
         * 
         * @param ic 
         */
        YeuxDecorator(ICreature* ic);
        
        /**
         * @brief Destructeur de YeuxDecorator
         * 
         */
        ~YeuxDecorator(){};

        /**
         * @brief Méthode jeTeVois.
         * 
         * @param ic créature à tester
         * @return true 
         * @return false 
         */
        bool jeTeVois(const ICreature & ic) const override final;

};

#endif
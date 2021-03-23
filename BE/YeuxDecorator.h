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
        static const double ALPHA_MIN; /*!< champ de vision min avec des yeux */
        static const double ALPHA_MAX; /*!< champ de vision max avec des yeux */

        static const double DIST_MIN; /*!< distance min */
        static const double DIST_MAX; /*!< distance max */
        
        static const double DETECTION_MIN; /*!< seuil de détection min */
        static const double DETECTION_MAX; /*!< seuil de détection max */


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
         * @brief Copie une créature avec des yeux
         * 
         * @return ICreature* 
         */
        ICreature* clone(void) override;
        
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

        /**
         * @brief Dessine une créature avec ses yeux.
         * 
         * Modélisé par un point noir au bout de la tête
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) override;

};

#endif
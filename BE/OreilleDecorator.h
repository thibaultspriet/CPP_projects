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
        static const double DIST_MIN; /*!< paramètre de détection , distance minimum */
        static const double DIST_MAX; /*!< paramètre de détection , distance maximum */
        
        static const double DETECTION_MIN; /*!< paramètre de détection , seuil de détection min */
        static const double DETECTION_MAX; /*!< paramètre de détection , seuil de détection max */

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
         * @brief clone une créature avec des oreilles
         * 
         * @return ICreature* 
         */
        ICreature* clone(void) override;
        
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

        /**
         * @brief dessine deux cercles au niveau de la tête pour représenter les oreilles
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) override;


};

#endif
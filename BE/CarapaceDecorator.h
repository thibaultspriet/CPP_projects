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

    protected:
        static const double PROTEC_DEATH_MAX; /*!< seuil de protection max */
        static const double DECREASE_VITESSE_MAX; /*!< facteur réducteur de la vitesse max */

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
         * @brief Copie une créature avec une carapace
         * 
         * @return ICreature* 
         */
        ICreature* clone(void) override;
        
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

        
        /**
         * @brief Déssine une créature avec une carapace.
         * 
         * Représentée par un rond noir au milieu de la queue
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) override;

      // ===================== BEGIN Fonctions de  DEBUG =====================
      virtual void printCreature(void) override {    
      cout << "====== BEGIN PRINT CARAPACE ======" << endl;
      cout << "créature " << identite << endl;
      cout << "vitesse : (" << getVitesse().at(0) << " ; " << getVitesse().at(1) << ")" << endl << "prob death : " << getProbDeath() << endl;
      cout << "prob death : " << getProbDeath() << endl;
      cout << "====== END PRINT CARAPACE ======" << endl;
      
   };
   // ===================== END Fonctions de  DEBUG =====================

};

#endif
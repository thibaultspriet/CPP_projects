#ifndef _CREATURE_DECORATOR_
#define _CREATURE_DECORATOR_

#include "ICreature.h"


/**
 * @brief Class CreatureDecorator.
 * 
 * Classe abstraite de base pour le design pattern decorator.
 * C'est cette classe qui indique qu'elles sont les méthodes à redefinir.
 * 
 * De plus cette classe délègue dans un premier temps le comportement original à la créature emballée.
 * 
 */
class CreatureDecorator : public ICreature{

    protected:
        ICreature * creature; /*!< Créature emballée */

    public:

        /**
         * @brief Constructeur de CreatureDecorator
         * 
         * @param ic créature emballée
         */
        CreatureDecorator(ICreature* ic);

        /**
         * @brief Destructeur de CreatureDecorator
         * 
         */
        virtual ~CreatureDecorator() {delete creature;};


        /**
         * @brief méthode je te vois. Redéfinie par les CapteurDecorators
         * 
         * @param ic créature qui est testéé pour voir si elle est dans le champ de vision de notre créature courante.
         * @return true 
         * @return false 
         */
        bool jeTeVois(const ICreature & ic) const;

        /**
         * @brief méthode getVitesse. Rédéfini par NageoireDecorator et CarapaceDecorator
         * 
         * @return std::vector<double> 
         */
        std::vector<double> getVitesse();

        /**
         * @brief méthode setVitesse. Rédéfinir par NageoireDecorator et CarapaceDecorator.
         * 
         * @param vx vitesse horizontale
         * @param vy vitesse verticale
         */
        void setVitesse(double vx, double vy);

        /**
         * @brief méthode getCamouflage. Rédéfini par CamouflageDecorator.
         * 
         * @return double 
         */
        double getCamouflage(void) const;

        /**
         * @brief méthode getProbDeath. Rédéfinir par CarapaceDecorator.
         * 
         * @return double 
         */
        double getProbDeath(void) const;


        /**
         * @brief Méthode virtuelle pure
         * 
         * Dans les classes filles (oreille, yeux, nageoire ..) permet de dessiner la créature avec son décorateur
         * 
         * @param support 
         * @param monMilieu 
         * @param creatureToDraw 
         */
        virtual void draw(UImg & support, Milieu& monMilieu, ICreature& creatureToDraw) = 0;

        /**
         * @brief permet de cloner une créature avec son décorateur
         * 
         * @return ICreature* 
         */
        virtual ICreature* clone(void) = 0;

};

#endif
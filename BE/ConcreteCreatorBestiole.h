#ifndef _CONCRETE_H_
#define _CONCRETE_H_

#include "IFactoryNaissance.h"
#include "Bestiole.h"

/**
 * @brief Classe ConcreteCreatorBestiole
 * 
 * Hérite de IFactoryNaissance et implémente la création de bestioles
 * 
 */
class ConcreteCreatorBestiole : public IFactoryNaissance
{
    public:

        /**
         * @brief Constructeur de ConcreteCreatorBestiole
         * 
         */
        ConcreteCreatorBestiole();
        
        /**
         * @brief Implémentation de create. Renvoie un pointeur vers une créature
         * 
         * @param comportement 
         * @return ICreature* 
         */
        ICreature* create(IComportement* comportement) override;

};

#endif
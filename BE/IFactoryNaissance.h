#ifndef _I_FACTO_H_
#define _I_FACTO_H_

#include "ICreature.h"

/**
 * @brief Interface IFactoryNaissance qui définit la méthode create
 * 
 * La méthode create renvoie un type de créature, dans notre cas il n'y a que des bestioles
 * 
 */
class IFactoryNaissance
{
public:
    /**
     * @brief Méthode virtuelle pure qui doit être redéfinie par les classes filles.
     * 
     * @param comportement 
     * @return ICreature* 
     */
    virtual ICreature* create(IComportement* comportement) = 0;
};
#endif
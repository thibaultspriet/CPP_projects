#ifndef _CLONE_H_
#define _CLONE_H_

#include "Bestiole.h"
#include "IFactoryNaissance.h"

class Clone {
    public : 

    Bestiole* getMultiple() const;
    Bestiole* getGregaire() const;
    Bestiole* getPrevoyante() const;
    Bestiole* getPeureuse() const;
    Bestiole* getKamikaze() const;

    private : 
    Bestiole* bestioleMultiple;
    Bestiole* bestioleGregaire;
    Bestiole* bestiolePrevoyante;
    Bestiole* bestiolePeureuse;
    Bestiole* bestioleKamikaze;

};

#endif

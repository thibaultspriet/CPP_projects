#include "Clone.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "IComportement.h"
#include "ComportementMultiple.h"


Clone::clone()
{
    bestioleGregaire = new Bestiole(0, 1, 1, 10, 10000, 0.5, 0.005, new ComportementGregaire(), M_PI, 2);
    bestiolePeureuse = new Bestiole(0, 1, 1, 10, 10000, 0.5, 0.005, new ComportementPeureuse(), M_PI, 2);
    bestioleKamikaze = new Bestiole(0, 1, 1, 10, 10000, 0.5, 0.005, new ComportementKamikaze(), M_PI, 2);
    bestioleMultiple = new Bestiole(0, 1, 1, 10, 10000, 0.5, 0.005, new ComportementMultiple(), M_PI, 2);
    bestiolePrevoyante = new Bestiole(0, 1, 1, 10, 10000, 0.5, 0.005, new ComportementPrevoyante(), M_PI, 2); 


}

Clone::~clones()
{
    delete bestioleGregaire;
    delete bestiolePeureuse;
    delete bestioleKamikaze;
    delete bestioleMultiple;
    delete bestiolePrevoyante;
}

Bestiole* Clone::getGregaire() const{
    return this ->bestioleGregaire;
}

Bestiole* Clone::getPeureuse() const{
    return this ->bestiolePeureuse;
}

Bestiole* Clone::getKamikaze() const{
    return this ->bestioleKamikaze;
}

Bestiole* Clone::getMultiple() const{
    return this ->bestioleMultiple;
}

Bestiole* Clone::getPrevoyante() const{
    return this ->bestiolePrevoyante;
}











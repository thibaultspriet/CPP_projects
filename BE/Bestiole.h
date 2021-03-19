#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "ICreature.h"

#include <iostream>


using namespace std;


//class Milieu;


/**
 * @brief Classe bestiole
 * 
 */
class Bestiole : public ICreature
{
   public:
      Bestiole(void);
      ~Bestiole(void) { cout << "dest bestiole" << identite << endl;};
};


#endif

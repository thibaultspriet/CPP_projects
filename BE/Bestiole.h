#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "ICreature.h"

#include <iostream>


using namespace std;




/**
 * @brief Classe bestiole
 * 
 */
class Bestiole : public ICreature
{
   public:
      /**
       * @brief Constructeur de bestiole
       * 
       */
      Bestiole(void) : ICreature(){};

      /**
       * @brief destructeur de bestiole
       * 
       */
      ~Bestiole(void) { cout << "dest bestiole" << identite << endl;};
};


#endif

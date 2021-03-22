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
       * @param comportement comportement à attribuer à la bestiole
       */
      Bestiole(IComportement* comportement) : ICreature(comportement){};

      /**
       * @brief Constructeur par copie d'une bestiole
       * 
       * @param b 
       */
      Bestiole(const Bestiole& b) : ICreature(b){cout << "constructeur par copie de bestiole" << endl;};

      /**
       * @brief destructeur de bestiole
       * 
       */
      ~Bestiole(void) { cout << "dest bestiole" << identite << endl;};

};


#endif

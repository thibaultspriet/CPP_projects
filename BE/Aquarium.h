#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#ifdef __APPLE__
#include <string.h>
#include <clocale>
#endif

#include <iostream>
#include "CImg.h"


//using namespace std;
using namespace cimg_library;

class Milieu;


/**
 * @brief classe Aquarium qui contient le milieu.
 * 
 * Aquarium définit les dimensions et gère le lancement de la simulation.
 */
class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte; /*!< aggrège une instance de milieu  */

   int            delay; /*!< période d'actualisation */

public :
   /**
    * @brief Construit un nouvel objet Aquarium
    * 
    * @param width largeur de l'aquarium
    * @param height hauteur de l'aquarium
    * @param _delay période d'actualisation
    */
   Aquarium( int width, int height, int _delay );

   /**
    * @brief Détruit l'objet Aquarium
    * 
    */
   ~Aquarium( void );

   /**
    * @brief Retourne l'objet milieu agrégé
    * 
    * @return référence au milieu
    */
   Milieu & getMilieu( void ) { return *flotte; }


   /**
    * @brief Lance la simulation
    * 
    * Arrête la simulation lorsque l'utilisateur appuit sur "esc".
    */
   void run( void );

};


#endif

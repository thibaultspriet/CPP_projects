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
    * @brief Constructeur par défaut
    * 
    */
   Aquarium(){};

   /**
    * @brief Construit un nouvel objet Aquarium
    * 
    * @param width largeur de l'aquarium
    * @param height hauteur de l'aquarium
    * @param _delay période d'actualisation
    */
   Aquarium( int width, int height, int _delay );

   /**
    * @brief Constructeur Aquarium avec une configuration particulière
    * 
    * @param width 
    * @param height 
    * @param _delay 
    * @param nbCreatures 
    * @param kamik 
    * @param greg 
    * @param peur 
    * @param prev 
    */
   Aquarium(int width, int height, int _delay, int nbCreatures, int kamik, int greg, int peur, int prev);

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
   Milieu & getMilieu( void ) const { return *flotte; }


   /**
    * @brief Lance la simulation
    * 
    * @param pathFileSim chemin vers le fichier pour enregistrer les données de la simulation
    * 
    * Arrête la simulation lorsque l'utilisateur appuit sur "esc".
    */
   void run( const char* pathFileSim );

};


#endif

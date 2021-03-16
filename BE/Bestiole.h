#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu;


/**
 * @brief Classe bestiole
 * 
 */
class Bestiole
{

private :
   static const double     AFF_SIZE; /*!< diamètre des bestioles  */
   static const double     MAX_VITESSE; /*!< vitesse maximale des bestioles */
   static const double     LIMITE_VUE; /*!< limite de vision des bestioles */

   static int              next; /*!< permet de gérer l'attribution d'une identité à chaque bestiole */

private :
   int               identite; /*!< identifiant unique pour chaque bestiole */
   int               x, y; /*!< position graphique de la bestiole. Affichage sur une grille de pixel, les positions doivent être des entiers */
   double            cumulX, cumulY; /*!< position réelle de la bestiole */ 
   double probDeath; /*!< coefficient déterminant la probabilité de décès d'une bestiole lors d'une collision. si 0 la bestiole est invincible ; si 1 elle meurt à coup sûr.  */
   vector<double> vitesse; /*!< vecteur vitesse de la bestiole. vitesse[0] = vx ; vitesse[1] = vy */
   T               * couleur; /*!< couleur de la bestiole */

private :

   /**
    * @brief déplace la bestiole dans la limite du milieu
    * 
    * @param xLim posiiton horizontale max
    * @param yLim  position verticale max
    */
   void bouge( int xLim, int yLim );

   /**
    * @brief gère la collision entre les bestioles
    * 
    * La collision se fait entre deux cercles de rayon ADD_SIZE / 2.
    * Parcourt la liste de toutes les autres bestioles. Si une collision, le sens du vecteur vitesse est inversé et il y a un tirage aléatoire qui détermine la mort ou non de la bestiole.
    * 
    * @param monMilieu référence du milieu
    * @param toRemoveBestioles paramètre intermédiaire qui permet de stocker les bestioles à supprimer à la fin d'une "step"
    */
   void collide(Milieu & monMilieu, std::vector<Bestiole*> & toRemoveBestioles);

public :     

   /**
    * @brief Constructeur d'un objet bestiole
    * 
    */
   Bestiole( void );    

   /**
    * @brief Constructeur par copie d'une bestiole
    * 
    * @param b 
    */
   Bestiole( const Bestiole & b );

   /**
    * @brief Destructeur d'un objet bestiole
    * 
    */
   ~Bestiole( void );                              

   /**
    * @brief méthode appelée sur la bestiole à chaque pas de simulation
    * 
    * @param monMilieu référence du milieu
    * @param toRemoveBestioles paramètre intermédiaire qui permet de stocker les bestioles à supprimer à la fin d'une "step"
    */
   void action( Milieu & monMilieu, std::vector<Bestiole*> & toRemoveBestioles );

   /**
    * @brief Affichage d'une bestiole
    * 
    * @param support 
    */
   void draw( UImg & support );


   /**
    * @brief détermine si la bestiole détecte la bestiole passée en argument
    * 
    * @param b référence constante d'une bestiole
    * @return true 
    * @return false 
    */
   bool jeTeVois( const Bestiole & b ) const;

   
   /**
    * @brief retourne l'attribut probDeath
    * 
    * @return double 
    */
   double getProbDeath(void) const;
   

   /**
    * @brief Place la bestiole de manière aléatoire à sa naissance
    * 
    * @param xLim limite horizontale
    * @param yLim limite verticale
    */
   void initCoords( int xLim, int yLim );

   /**
    * @brief Redéfinition de l'opérateur ==
    * 
    * @param b1 première bestiole
    * @param b2 seconde bestiole
    * @return true 
    * @return false 
    */
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   /**
    * @brief Renvoie l'identifiant de la bestiole
    * 
    * @return int 
    */
   int getIdentite(void){return identite;};

   /**
    * @brief Renvoie la position x de la bestiole
    *
    * @return int
    */
   int getX(void);

   /**
    * @brief Renvoie la position y de la bestiole
    *
    * @return int
    */
   int getY(void);

   /**
    * @brief Renvoie le vecteur directeur de déplacement de la bestiole
    *
    * @return vector<double>
    */
    vector<double> getDirection(void);

};


#endif

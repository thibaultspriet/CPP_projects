#ifndef _ICREATURE_H_
#define _ICREATURE_H_

#include <iostream>
#include <vector>
#include "UImg.h"

using namespace std;

class Milieu;

class ICreature{

protected :
   static const double     AFF_SIZE; /*!< diamètre des bestioles  */
   static const double     MAX_VITESSE; /*!< vitesse maximale des bestioles */
   static const double     LIMITE_VUE; /*!< limite de vision des bestioles */

   static int              next; /*!< permet de gérer l'attribution d'une identité à chaque bestiole */

protected :
   int               identite; /*!< identifiant unique pour chaque bestiole */
   int               x, y; /*!< position graphique de la bestiole. Affichage sur une grille de pixel, les positions doivent être des entiers */
   double            cumulX, cumulY; /*!< position réelle de la bestiole */ 
   double probDeath; /*!< coefficient déterminant la probabilité de décès d'une bestiole lors d'une collision. si 0 la bestiole est invincible ; si 1 elle meurt à coup sûr.  */
   double camouflage;
   std::vector<double> vitesse; /*!< vecteur vitesse de la bestiole. vitesse[0] = vx ; vitesse[1] = vy */
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
    * @param toRemoveCreature paramètre intermédiaire qui permet de stocker les bestioles à supprimer à la fin d'une "step"
    */
   void collide(Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreature);

public :     

   /**
    * @brief Constructeur d'un objet bestiole
    * 
    */
   ICreature( void );    

   /**
    * @brief Constructeur par copie d'une bestiole
    * 
    * @param b 
    */
   ICreature( const ICreature & ic );

   /**
    * @brief Destructeur d'un objet bestiole
    * 
    */
   virtual ~ICreature( void );                              

   /**
    * @brief méthode appelée sur la bestiole à chaque pas de simulation
    * 
    * @param monMilieu référence du milieu
    * @param toRemoveCreatures paramètre intermédiaire qui permet de stocker les bestioles à supprimer à la fin d'une "step"
    */
   void action( Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures );

   /**
    * @brief Affichage d'une bestiole
    * 
    * @param support 
    */
   void draw( UImg & support );


   /**
    * @brief détermine si la bestiole détecte la bestiole passée en argument
    * 
    * @param ic référence constante d'une bestiole
    * @return true 
    * @return false 
    */
   virtual bool jeTeVois( const ICreature & ic ) const;

   
   /**
    * @brief retourne l'attribut probDeath
    * 
    * @return double 
    */
   virtual double getProbDeath(void) const;
   virtual double getCamouflage(void) const;

   int getX() const {return x;};
   int getY() const {return y;};

   virtual std::vector<double> getVitesse(void);
   virtual void setVitesse(double vx, double vy);
   

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
   friend bool operator==( const ICreature & ic1, const ICreature & ic2 );

   /**
    * @brief Renvoie l'identifiant de la bestiole
    * 
    * @return int 
    */
   int getIdentite(void) {return identite;};
        



};

#endif
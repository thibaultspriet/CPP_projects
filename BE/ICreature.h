#ifndef _ICREATURE_H_
#define _ICREATURE_H_

#include <iostream>
#include <vector>
#include "UImg.h"
#include "IComportement.h"

using namespace std;

class Milieu;


/**
 * @brief Class ICreature, définit les attributs et méthodes des bestio
 * 
 */
class ICreature{

protected :
   static const double     AFF_SIZE; /*!< diamètre des créatures  */
   static const double     MAX_VITESSE; /*!< vitesse maximale des créatures */
   static const double     LIMITE_VUE; /*!< limite de vision des créatures */

   static int              next; /*!< permet de gérer l'attribution d'une identité à chaque créature */

protected :
   int               identite; /*!< identifiant unique pour chaque créature */
   int               x, y; /*!< position graphique de la créature. Affichage sur une grille de pixel, les positions doivent être des entiers */
   double            cumulX, cumulY; /*!< position réelle de la créature */ 
   double probDeath; /*!< coefficient déterminant la probabilité de décès d'une créature lors d'une collision. si 0 la créature est invincible ; si 1 elle meurt à coup sûr.  */
   double camouflage; /*!< coéfficient de camouflage de la bestiole. camouflage > détection la créature ne sera pas vue. Par défaut cette valeur est 0 */
   std::vector<double> vitesse; /*!< vecteur vitesse de la créature. vitesse[0] = vx ; vitesse[1] = vy */
   T               * couleur; /*!< couleur de la créature */
   ComportType comportement;

private :

   /**
    * @brief déplace la créature dans la limite du milieu
    * 
    * @param xLim posiiton horizontale max
    * @param yLim  position verticale max
    */
   void bouge( int xLim, int yLim );

   /**
    * @brief gère la collision entre les créatures
    * 
    * La collision se fait entre deux cercles de rayon AFF_SIZE / 2.
    * Parcourt la liste de toutes les autres créatures. Si une collision, le sens du vecteur vitesse est inversé et il y a un tirage aléatoire qui détermine la mort ou non de la créature.
    * 
    * @param monMilieu référence du milieu
    * @param toRemoveCreature paramètre intermédiaire qui permet de stocker les créatures à supprimer à la fin d'une "step"
    */
   void collide(Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreature);

public :     

   /**
    * @brief Constructeur d'un objet créature
    * 
    */
   ICreature( void );    

   /**
    * @brief Constructeur par copie d'une créature
    * 
    * @param b 
    */
   ICreature( const ICreature & ic );

   /**
    * @brief Destructeur d'un objet créature
    * 
    */

   virtual ~ICreature( void );                              

   /**
    * @brief méthode appelée sur la créature à chaque pas de simulation
    * 
    * @param monMilieu référence du milieu
    * @param toRemoveCreatures paramètre intermédiaire qui permet de stocker les créatures à supprimer à la fin d'une "step"
    */
   void action( Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures );
   
   
   virtual ICreature clone() {};

   /**
    * @brief Affichage d'une créature
    * 
    * @param support 
    */
   void draw( UImg & support );


   /**
    * @brief détermine si la créature détecte la créature passée en argument
    * 
    * @param ic référence constante d'une créature
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

   /**
    * @brief retourne l'attribut camouflage
    * 
    * @return double 
    */
   virtual double getCamouflage(void) const;


   /**
    * @brief retourne la position horizontale de la créature
    * 
    * @return int 
    */
   int getX() const {return x;};

   /**
    * @brief retourne la position verticale de la créature
    * 
    * @return int 
    */
   int getY() const {return y;};

   
   /**
    * @brief retourne le vecteur vitesse de la créature. En position 0 : vitesse horizontale ; en position 1 : vitesse verticale
    * 
    * @return std::vector<double> 
    */
   virtual std::vector<double> getVitesse(void);

   /**
   * @brief Renvoie le vecteur directeur de déplacement de la bestiole
   *
   * @return vector<double>
   */
   vector<double> getDirection(void);


   /**
    * @brief attribut une nouvelle valeur au vecteur vitesse de la créature.
    * 
    * @param vx 
    * @param vy 
    */
   virtual void setVitesse(double vx, double vy);
   

   /**
    * @brief Place la créature de manière aléatoire à sa naissance
    * 
    * @param xLim limite horizontale
    * @param yLim limite verticale
    */
   void initCoords( int xLim, int yLim );

   /**
    * @brief Redéfinition de l'opérateur ==
    * 
    * @param b1 première créature
    * @param b2 seconde créature
    * @return true 
    * @return false 
    */
   friend bool operator==( const ICreature & ic1, const ICreature & ic2 );

   /**
    * @brief Renvoie l'identifiant de la créature
    * 
    * @return int 
    */
   int getIdentite(void) {return identite;};
        



};



#endif
#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;



/**
 * @brief Classe milieu qui contient les bestioles.
 * 
 */
class Milieu : public UImg
{

private :
   static const T          white[]; /*!< couleur blanche */

   int                     width, height; /*!< largeur et hauteur du milieu */
   //std::vector<Bestiole*> listeBestioles; /*!< vecteur de pointeurs vers les bestioles de l'environnement */
   std::vector<ICreature*> listeCreatures; /*!< vecteur de pointeurs vers les bestioles de l'environnement */
   

public :
   /**
    * @brief Constructeur d'un objet Milieu
    * 
    * @param _width largeur
    * @param _height hauteur
    */
   Milieu( int _width, int _height );

   /**
    * @brief Destructeur de l'objet milieu
    * 
    */
   ~Milieu( void );

   /**
    * @brief renvoie la largeur du milieu
    * 
    * @return int 
    */
   int getWidth( void ) const { return width; };

   /**
    * @brief renvoie la hauteur du milieu
    * 
    * @return int 
    */
   int getHeight( void ) const { return height; };


   /**
    * @brief appelé à chaque intervalle de temps de la simulation
    * 
    * Parcours la liste des bestioles présentes et invoque leur comportement.
    */
   void step( void );

   /**
    * @brief ajoute une bestiole à la simulation
    * 
    * En plus elle donne une position aléatoire à la nouvelle bestiole.
    * 
    * @param b pointeur sur une bestiole
    */
   //void addMember(  Bestiole* b ) { listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
   void addMember(  ICreature* ic ) { listeCreatures.push_back(ic); listeCreatures.back()->initCoords(width, height); }
   
   /**
    * @brief supprime une bestiole de la simulation
    * 
    * La bestiole est supprimé de la liste des bestiole, mais l'objet bestiole lui même est également supprimé
    * 
    * @param b pointeur sur une bestiole
    */
   // void removeMember( Bestiole * b);
   void removeMember( ICreature * ic);

   /**
    * @brief supprime plusieurs bestioles en même temps
    * 
    * @param bestioles vecteur de pointeur des bestioles à supprimer
    */
   void removeMember( std::vector<ICreature*> creatures );



   /**
    * @brief renvoie le nombre de bestiole que la bestiole passée en argument détecte
    * 
    * @param b référence d'une bestiole
    * @return int 
    */
   int nbVoisins( const ICreature & ic );

   /**
    * @brief Renvoie une référence de la liste des bestioles
    * 
    * @return std::vector<Bestiole*>& 
    */
   std::vector<ICreature*> & getCreatures();

};


#endif

#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Configuration.h"

#include <iostream>
#include <vector>

using namespace std;



/**
 * @brief Classe milieu qui contient les créatures.
 * 
 */
class Milieu : public UImg
{

private :
   static const T          white[]; /*!< couleur blanche */

   int                     width, height; /*!< largeur et hauteur du milieu */
   std::vector<ICreature*> listeCreatures; /*!< vecteur de pointeurs vers les créatures de l'environnement */

   Configuration* config; /*!< objet configuration qui contient le pourcentage de chaque comportement */

   

public :
   /**
    * @brief Constructeur d'un objet Milieu
    * 
    * @param _width largeur
    * @param _height hauteur
    */
   Milieu( int _width, int _height );

   Milieu( int _width, int _height, Configuration* config);

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
    * Parcours la liste des créatures présentes et invoque leur comportement.
    */
   void step( void );

   /**
    * @brief ajoute une créature à la simulation
    * 
    * En plus elle donne une position aléatoire à la nouvelle créature.
    * 
    * @param ic pointeur sur une créature
    */
   void addMember(  ICreature* ic ) { listeCreatures.push_back(ic); listeCreatures.back()->initCoords(width, height); }

   void randomNaissance(std::map<ComportType,int>);
   
   /**
    * @brief supprime une créature de la simulation
    * 
    * La créature est supprimé de la liste des créatures, mais l'objet créature lui même est également supprimé
    * 
    * @param ic pointeur sur une créature
    */
   void removeMember( ICreature * ic);

   /**
    * @brief supprime plusieurs créatures en même temps
    * 
    * @param creatures vecteur de pointeur des créatures à supprimer
    */
   void removeMember( std::vector<ICreature*> creatures );



   /**
    * @brief renvoie le nombre de céatures que la créature passée en argument détecte
    * 
    * @param ic référence d'une créature
    * @return int 
    */
   int nbVoisins( const ICreature & ic );

   /**
    * @brief renvoie un pointeur des créatures que la créature passée en argument détecte
    *
    * @param ic référence d'une bestiole
    * @return vector<Bestiole*>
    **/
   std::vector<ICreature*> getVoisins(const ICreature& ic);

   /**
    * @brief Renvoie une référence de la liste des créatures
    * 
    * @return std::vector<ICreature*>& 
    */
   std::vector<ICreature*> & getCreatures();


   /**
    * @brief Retourne l'objet configuration
    * 
    * @return Configuration* 
    */
   Configuration* getConfig(void){return config;};

};


#endif

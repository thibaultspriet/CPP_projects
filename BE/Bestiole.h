#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   //double probDeath;
   vector<double> vitesse;
   T               * couleur;

private :
   void bouge( int xLim, int yLim );
   // void collide(vector<Bestiole> bestioles); // Méthode appelée après bouge, parcourt les bestioles, si collision inverse le sens du vecteur vitesse
   void collide(vector<Bestiole*> bestioles); // Méthode appelée après bouge, parcourt les bestioles, si collision inverse le sens du vecteur vitesse

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   //double getProbDeath(void) const;
   
   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );


};


#endif

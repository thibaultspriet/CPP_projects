#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>



const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;

   // vitesse initiale aléatoire
   vitesse.push_back(static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE);
   vitesse.push_back(static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE);

   // définit la couleur de la bestiole
   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   probDeath = (rand() % 101)/100.0 ;// valeur entre 0 et 100

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole " << identite << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{
   double         nx, ny;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + vitesse.at(0) + cx;
   ny = y + vitesse.at(1) + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      vitesse.at(0) = -vitesse.at(0);
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      vitesse.at(1) = -vitesse.at(1);
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::collide(Milieu & monMilieu, std::vector<Bestiole*> & toRemoveBestioles){

   std::vector<Bestiole*> & bestioles = monMilieu.getBestioles();
   bool alreadyCollide = false;

   for ( auto it = bestioles.begin() ; it != bestioles.end() ; ++it ){
      if(!((**it) == *this)){            
         double         dist;
         dist = std::sqrt( (x-(**it).x)*(x-(**it).x) + (y-(**it).y)*(y-(**it).y) );
         if(dist <= Bestiole::AFF_SIZE){ // si collision, tirage aléatoire pour savoir si la bestiole doit mourir
            double death = (rand() % 101)/100.0;
            if(death < this->getProbDeath() && !alreadyCollide){
               cout << "Bestiole " << identite << " va mourir" << endl;
               toRemoveBestioles.push_back(this);
            }
            if(!alreadyCollide){ // inversr le sens du vecteur vitesse à la première collision
               vitesse.at(0) *= -1;
               vitesse.at(1) *= -1;
               alreadyCollide = !alreadyCollide;
            }
         }
      }
   }
}




void Bestiole::action( Milieu & monMilieu, std::vector<Bestiole*> & toRemoveBestioles )
{
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
   collide(monMilieu, toRemoveBestioles);

}



void Bestiole::draw( UImg & support )
{

   double orientation = -atan(vitesse.at(1)/vitesse.at(0));

   double dx = cos( orientation )*AFF_SIZE/2.1;
   double dy = -sin( orientation )*AFF_SIZE/2.1;

   double         xt = vitesse.at(0) > 0 ? x + dx : x - dx;
   double         yt = vitesse.at(0) > 0 ? y + dy : y - dy;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

double Bestiole::getProbDeath() const{
   return this->probDeath;
}

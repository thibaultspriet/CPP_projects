#include "ICreature.h"
#include "Milieu.h"

#include <cstdlib>
#include <cmath>



const double      ICreature::AFF_SIZE = 8.;
const double      ICreature::MAX_VITESSE = 10.;
const double      ICreature::LIMITE_VUE = 30.;

int               ICreature::next = 0;


ICreature::ICreature( void )
{

   identite = ++next;

   cout << "const creature (" << identite << ") par defaut" << endl;

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
   camouflage = 0.0;

}


ICreature::ICreature( const ICreature & ic )
{

   identite = ++next;

   cout << "const creature (" << identite << ") par copie" << endl;

   x = ic.x;
   y = ic.y;
   cumulX = cumulY = 0.;
   vitesse = ic.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, ic.couleur, 3*sizeof(T) );

}


ICreature::~ICreature( void )
{

   delete[] couleur;

   cout << "dest creature " << identite << endl;

}


void ICreature::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;
    

}


void ICreature::bouge( int xLim, int yLim )
{
   double         nx, ny;
   int            cx, cy;
   
   //cout << "======= BEGIN bouge ========" << endl;
   std::vector<double> vit = getVitesse();
   //cout << "Final vitesse : " << vit.at(0) << " " << vit.at(1) << endl;
   //cout << "======= END bouge ========" << endl;

   
   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + vit.at(0) + cx;
   ny = y + vit.at(1) + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
        setVitesse(-vit.at(0),vit.at(1));
        cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      setVitesse(vit.at(0),-vit.at(1));
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
   
}

void ICreature::collide(Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures){

   std::vector<ICreature*> & creatures = monMilieu.getCreatures();
   bool alreadyCollide = false;

   for ( vector<ICreature*>::iterator it = creatures.begin() ; it != creatures.end() ; ++it ){
      if(!((**it) == *this)){            
         double         dist;
         dist = std::sqrt( (x-(**it).x)*(x-(**it).x) + (y-(**it).y)*(y-(**it).y) );

         if(dist <= ICreature::AFF_SIZE){ // si collision, tirage aléatoire pour savoir si la bestiole doit mourir
            double survive = (rand() % 101)/100.0;
            double death = this->getProbDeath();
            cout << "death : " << death <<  " survive : " << survive << endl;
            if(death > survive && !alreadyCollide){
               cout << "Creature " << identite << " va mourir" << endl;
               toRemoveCreatures.push_back(this);
            }
            if(!alreadyCollide){ // inversr le sens du vecteur vitesse à la première collision
               std::vector<double> vit = getVitesse();
               setVitesse(-vit.at(0),-vit.at(1));
               alreadyCollide = !alreadyCollide;
            }
         }
      }
   }
}




void ICreature::action( Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures )
{
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
   collide(monMilieu, toRemoveCreatures);

}



void ICreature::draw( UImg & support )
{

   std::vector<double> vit = getVitesse();
   double orientation = -atan(vit.at(1)/vit.at(0));

   double dx = cos( orientation )*AFF_SIZE/2.1;
   double dy = -sin( orientation )*AFF_SIZE/2.1;

   double         xt = vit.at(0) > 0 ? x + dx : x - dx;
   double         yt = vit.at(0) > 0 ? y + dy : y - dy;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const ICreature & ic1, const ICreature & ic2 )
{

   return ( ic1.identite == ic2.identite );

}


bool ICreature::jeTeVois( const ICreature & ic ) const
{

   double         dist;

   dist = std::sqrt( (x-ic.x)*(x-ic.x) + (y-ic.y)*(y-ic.y) );
   return ( dist <= LIMITE_VUE );

}

double ICreature::getProbDeath() const{
   return this->probDeath;
}

double ICreature::getCamouflage() const{
   return camouflage;
}


std::vector<double> ICreature::getVitesse(){
    return vitesse;
};

void ICreature::setVitesse(double vx,double vy){
    vitesse.at(0) = vx;
    vitesse.at(1) = vy;
};

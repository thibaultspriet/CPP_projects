#include "ICreature.h"
#include "Milieu.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPeureuse.h"
#include "ComportementPrevoyante.h"

#include <cstdlib>
#include <cmath>



const double      ICreature::AFF_SIZE = 8.0;
const double      ICreature::MAX_VITESSE = 10.0;
const double      ICreature::LIMITE_VUE = 30.0;


int               ICreature::next = 0;


void ICreature::initCreature(){
   identite = ++next;
   x = this->y = 0;
   cumulX = this->cumulY = 0.;

   // vitesse initiale aléatoire
   vitesse.push_back(static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE);
   vitesse.push_back(static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE);

   // définit la couleur de la bestiole
   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   probDeath = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   camouflage = 0.0;
   dureeVie = rand() % 100 + 300;
   cloneRate = 1.0 / 1000.0; // une créature peut avoir un taux de clonnage compris entre 0 et 3%
}

ICreature::ICreature( void )
{
   initCreature();
   comportement = new ComportementKamikaze();
   // cout << "const creature (" << identite << ") par defaut" << endl;
}


ICreature::ICreature( const ICreature & ic ) :  identite(++next), x(ic.x), y(ic.y), cumulX(ic.cumulX), cumulY(ic.cumulY), vitesse(ic.vitesse), dureeVie(ic.dureeVie), cloneRate(ic.cloneRate), probDeath(ic.probDeath), camouflage(ic.camouflage)
{

   // cout << "const creature (" << identite << ") par copie" << endl;
   couleur = new T[ 3 ];
   memcpy( couleur, ic.couleur, 3*sizeof(T) );
   comportement = (ic.comportement)->clone();

}

ICreature::ICreature(IComportement* comportement) : comportement(comportement){

   initCreature();
   switch (comportement->getComportementType())
   {
   case KAMIK:
      setColor(230,0,0);
      break;
   case GREG:
      setColor(230,230,230);
      break;
   case PEUR:
      setColor(0,230,0);
      break;
   case PREV:
      setColor(0,0,230);
      break;
   }
   // cout << "const creature (" << identite << ") comportement" << endl;
}

ICreature* ICreature::clone(){
   ICreature* creature_clone = new ICreature(*this);
   // cout << "clonage ICreature" << endl;
   return creature_clone;
} 


ICreature::~ICreature( void )
{

   delete[] couleur;
   delete comportement;

   // cout << "dest creature " << identite << endl;

}




void ICreature::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;
    

}


void ICreature::bouge( Milieu& monMilieu )
{
   double         nx, ny;
   int            cx, cy;
   int xLim = monMilieu.getWidth();
   int yLim = monMilieu.getHeight();
   
   vector<double> vit_effective = getComportementVitesseMultiple(monMilieu);
   vector<double> vit_to_set = getComportementVitesse(monMilieu);


   
   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + vit_effective.at(0) + cx;
   ny = y + vit_effective.at(1) + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
        setVitesse(-vit_to_set.at(0),vit_to_set.at(1));
        cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      setVitesse(vit_to_set.at(0),-vit_to_set.at(1));
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

   for ( auto it = creatures.begin() ; it != creatures.end() ; ++it ){
      if(!((**it) == *this)){            
         double         dist;
         dist = std::sqrt( (x-(**it).x)*(x-(**it).x) + (y-(**it).y)*(y-(**it).y) );

         if(dist <= ICreature::AFF_SIZE){ // si collision, tirage aléatoire pour savoir si la bestiole doit mourir
            double survive = (rand() % 101)/100.0;
            double death = this->getProbDeath();
            // cout << "death : " << death <<  " survive : " << survive << endl;
            if(death > survive && !alreadyCollide){
               // cout << "Creature " << identite << " va mourir" << endl;
               toRemoveCreatures.push_back(this);
            }
            if(!alreadyCollide){ // inversr le sens du vecteur vitesse à la première collision
               vector<double> vit_to_set = getComportementVitesse(monMilieu);
               setVitesse(-vit_to_set.at(0),-vit_to_set.at(1));
               alreadyCollide = !alreadyCollide;
            }
         }
      }
   }
}




void ICreature::action( Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures, std::vector<ICreature*> & toAppendCreatures )
{
   // clonnage
   double clonnage = ((rand() % 1001) + 1) / 1000.0;
   if( clonnage <= cloneRate){
      ICreature* creature_clone = clone();
      toAppendCreatures.push_back(creature_clone);
      // cout << "clonnage rate : " << cloneRate << " ; random : " << clonnage << endl;
   }
   bouge( monMilieu );
   collide(monMilieu, toRemoveCreatures);
   decreaseDureeVie();
}



void ICreature::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{

   vector<double> vit = creatureToDraw.getComportementVitesseMultiple(monMilieu);

   double orientation = -atan(vit.at(1)/vit.at(0));

   double dx = cos( orientation )*AFF_SIZE/2.1;
   double dy = -sin( orientation )*AFF_SIZE/2.1;

   int x = creatureToDraw.getX();
   int y = creatureToDraw.getY();

   double         xt = vit.at(0) > 0 ? x + dx : x - dx;
   double         yt = vit.at(0) > 0 ? y + dy : y - dy;


   double opacity = creatureToDraw.getCamouflage() == 0 ? 1 : .3;
   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur, opacity );
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

double ICreature::getNormeVitesse(std::vector<double> vit){
   return sqrt(vit.at(0)*vit.at(0) + vit.at(1)*vit.at(1));
}


vector<double> ICreature::getDirection() {
    vector<double> vit = getVitesse();
    vector<double> vitUnit(2);
    double norme = sqrt(vit.at(0) * vit.at(0) + vit.at(1) * vit.at(1));
    vitUnit.at(0) = vit.at(0) / norme;
    vitUnit.at(1) = vit.at(1) / norme;
    return vitUnit;
}

std::vector<double> ICreature::getComportementVitesse(Milieu& monMilieu){
   pair<vector<double>, double> direction = comportement->calculDirection(monMilieu.getVoisins(*this),*this);
   std::vector<double> vit;
   double normeVit = getNormeVitesse(getVitesse());
   vit.push_back(direction.first.at(0) * normeVit);
   vit.push_back(direction.first.at(1) * normeVit);

   return vit;
}

vector<double> ICreature::getComportementVitesseMultiple(Milieu& monMilieu){
   pair<vector<double>, double> direction = comportement->calculDirection(monMilieu.getVoisins(*this),*this);
   std::vector<double> vit;
   double normeVit = getNormeVitesse(getVitesse());
   vit.push_back(direction.first.at(0) * direction.second * normeVit);
   vit.push_back(direction.first.at(1) * direction.second * normeVit);
   return vit;
}

void ICreature::setVitesse(double vx,double vy){
    vitesse.at(0) = vx;
    vitesse.at(1) = vy;
};

void ICreature::setColor(int r, int g, int b){
   couleur[0] = r;
   couleur[1] = g;
   couleur[2] = b;

}

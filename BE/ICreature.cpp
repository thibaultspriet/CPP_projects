#include "ICreature.h"
#include "Milieu.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPeureuse.h"
#include "ComportementPrevoyante.h"

#include <cstdlib>
#include <cmath>



const double      ICreature::AFF_SIZE = 8.;
const double      ICreature::MAX_VITESSE = 10.;
const double      ICreature::LIMITE_VUE = 30.;

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

   probDeath = (rand() % 101)/100.0 ;// valeur entre 0 et 1
   camouflage = 0.0;
}

ICreature::ICreature( void )
{
   initCreature();
   comportement = new ComportementKamikaze();
   cout << "const creature (" << identite << ") par defaut" << endl;
}


ICreature::ICreature( const ICreature & ic ) :  identite(++next), x(ic.x), y(ic.y), cumulX(ic.cumulX), cumulY(ic.cumulY), vitesse(ic.vitesse)
{

   // identite = ++next;

   cout << "const creature (" << identite << ") par copie" << endl;
   // cout << "jusqu'ici" << endl;
   // x = ic.x;
   // cout << "jusqu'ici" << endl;
   // y = ic.y;
   // cumulX = cumulY = 0.;
   // vitesse = ic.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, ic.couleur, 3*sizeof(T) );
   comportement = new IComportement(*(ic.comportement));

}

ICreature::ICreature(IComportement* comportement) : comportement(comportement){

   initCreature();
   cout << "const creature (" << identite << ") comportement" << endl;
}

/* ICreature::ICreature(ComportType comport) {
    identite = ++next;

    cout << "const creature (" << identite << ") par defaut" << endl;

    x = y = 0;
    cumulX = cumulY = 0.;

    // vitesse initiale aléatoire
    vitesse.push_back(static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE);
    vitesse.push_back(static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE);

    // définit la couleur de la bestiole
    couleur = new T[3];
    couleur[0] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);
    couleur[1] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);
    couleur[2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);

    probDeath = (rand() % 101) / 100.0;// valeur entre 0 et 100
    camouflage = 0.0;
    switch (comport)
    {
    case GREG:
        comportement = new ComportementGregaire();
        break;

    case KAMIK:
        comportement = new ComportementKamikaze();
        break;

   //  case MULTI:
   //      comportement = new ComportementMultiple();
   //      break;

    case PEUR:
        comportement = new ComportementPeureuse();
        break;

    case PREV:
    default:
        comportement = new ComportementPrevoyante();
        break;
    }
} */

ICreature::~ICreature( void )
{

   delete[] couleur;
   delete comportement;

   cout << "dest creature " << identite << endl;

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
               vector<double> vit_to_set = getComportementVitesse(monMilieu);
               setVitesse(-vit_to_set.at(0),-vit_to_set.at(1));
               alreadyCollide = !alreadyCollide;
            }
         }
      }
   }
}




void ICreature::action( Milieu & monMilieu, std::vector<ICreature*> & toRemoveCreatures )
{
   bouge( monMilieu );
   collide(monMilieu, toRemoveCreatures);

}



void ICreature::draw( UImg & support, Milieu& monMilieu )
{

   vector<double> vit = getComportementVitesseMultiple(monMilieu);

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

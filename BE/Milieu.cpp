#include "Milieu.h"
#include "ICreature.h"
#include "Bestiole.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   std::vector<ICreature*> toRemoveCreatures; // objet temporaire qui stocke les creatures à supprimer à la fin du pas de simulation
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<ICreature*>::iterator it = listeCreatures.begin() ; it != listeCreatures.end() ; ++it ) // appelle l'action et déssinne chaque créature
   {
      (*it)->action( *this, toRemoveCreatures);
      (*it)->draw( *this );
   } // for
   if(!toRemoveCreatures.empty()){ // supprime les créatures qui sont mortes pendant le pas de simulation
      removeMember(toRemoveCreatures);
   }

}

void Milieu::removeMember(ICreature* ic){
   std::vector<ICreature*>::iterator itr = std::find(listeCreatures.begin(),listeCreatures.end(),ic); 
   int idxRemove = std::distance(listeCreatures.begin(),itr); // index de la créature à supprimer
   listeCreatures.erase(listeCreatures.begin() + idxRemove);
   delete ic;

}

void Milieu::removeMember(std::vector<ICreature*> creatures){
   for(auto it = creatures.begin() ; it != creatures.end() ; ++it){
      removeMember(*it);
   }
}

int Milieu::nbVoisins( const ICreature & ic )
{
   int         nb = 0;

   for ( std::vector<ICreature*>::iterator itc = listeCreatures.begin() ; itc != listeCreatures.end() ; ++itc )
      if(!((**itc) == ic ) && ic.jeTeVois((**itc)) ){
         ++nb;
      }

   return nb;

}

vector<ICreature*> & Milieu::getCreatures(){
   return listeCreatures;
}


vector<ICreature*> Milieu::getVoisins(const ICreature& ic)
{
    std::vector<ICreature*> voisins;
    for (std::vector<ICreature*>::iterator it = listeCreatures.begin(); it != listeCreatures.end(); ++it)
        if (!(ic == **it) && ic.jeTeVois(**it)){
            voisins.push_back(*it);
        }
    return voisins;
}

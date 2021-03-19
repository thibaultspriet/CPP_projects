#include "Milieu.h"

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

   std::vector<Bestiole*> toRemoveBestioles; // objet temporaire qui stocke les bestioles à supprimer à la fin du pas de simulation
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ) // appelle l'action et désinne chaque bestiole
   {
      (*it)->action( *this, toRemoveBestioles);
      (*it)->draw( *this );

   } // for
   if(!toRemoveBestioles.empty()){ // supprime les bestioles qui sont mortes pendant le pas de simulation
      removeMember(toRemoveBestioles);
   }

}

void Milieu::removeMember(Bestiole* b){
   std::vector<Bestiole*>::iterator itr = std::find(listeBestioles.begin(),listeBestioles.end(),b); 
   int idxRemove = std::distance(listeBestioles.begin(),itr); // index de la bestiole à supprimer
   listeBestioles.erase(listeBestioles.begin() + idxRemove);
   delete b;

}

void Milieu::removeMember(std::vector<Bestiole*> bestioles){
   for(auto it = bestioles.begin() ; it != bestioles.end() ; ++it){
      removeMember(*it);
   }
}

int Milieu::nbVoisins( const Bestiole & b )
{
   int         nb = 0;


   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}

vector<Bestiole*> Milieu::getVoisins(const Bestiole& b)
{
    vector<Bestiole*> voisins;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
        if (!(b == **it) && b.jeTeVois(**it))
            voisins.push_back(**it);

    return voisins;
}

vector<Bestiole*> & Milieu::getBestioles(){
   return listeBestioles;
}

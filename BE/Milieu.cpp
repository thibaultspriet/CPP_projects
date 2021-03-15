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

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->action( *this );
      (*it)->draw( *this );

   } // for

}

void Milieu::removeMember(Bestiole* b){
   std::vector<Bestiole*>::iterator itr = std::find(listeBestioles.begin(),listeBestioles.end(),b);
   int idxRemove = std::distance(listeBestioles.begin(),itr);
   Bestiole* toDelete = listeBestioles[idxRemove];
   listeBestioles[idxRemove] = listeBestioles.back();

   cout << "After pushing back : ";
   for(auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it){
      cout << (*it)->getIdentite() << " ";
   }
   cout << endl;

   listeBestioles.pop_back();
   cout << "After pop : ";
   for(auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it){
      cout << (*it)->getIdentite() << " ";
   }
   cout << endl;
   delete toDelete;

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

vector<Bestiole*> & Milieu::getBestioles(){
   return listeBestioles;
}

#include "Aquarium.h"
#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}

Aquarium::Aquarium(int width, int height, int _delay, int nbCreatures, int kamik, int greg, int peur, int prev) : CImgDisplay(), delay(_delay)
{
   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height, nbCreatures, kamik, greg, peur, prev );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );
}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( const char* pathFileSim )
{

   cout << "running Aquarium" << endl;
   int iteration = 0;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) {close(); delete this; break;};
      }

      if(iteration == 1000 ) {close(); delete this; break;};


      flotte->step(pathFileSim);
      display( *flotte );

      ++iteration;

      wait( delay );


   } // while

}

#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 ); // Construit l'aquarium de la simulation

   for ( int i = 1; i <= 20 ; ++i )
      ecosysteme.getMilieu().addMember( new Bestiole() ); // ajoute les bestioles à la simulation
   ecosysteme.run(); // lance la simulation


   return 0;

}

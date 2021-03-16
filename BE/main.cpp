#include "Aquarium.h"
#include "Milieu.h"
#include "ICreature.h"
#include "YeuxDecorator.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 ); // Construit l'aquarium de la simulation

   for ( int i = 1; i <= 20 ; ++i )
      if(i==10){
         Bestiole* bestiole = new Bestiole();
         YeuxDecorator* bestiole_voyante = new YeuxDecorator(bestiole);
         ecosysteme.getMilieu().addMember( bestiole_voyante );
      }
      else{
         ecosysteme.getMilieu().addMember( new Bestiole() );
      }
       // ajoute les bestioles à la simulation
   ecosysteme.run(); // lance la simulation

   // vector<ICreature*> & creatures = ecosysteme.getMilieu().getCreatures();
   // ICreature* b10 = creatures[11];
   // YeuxDecorator* by = new YeuxDecorator(b10);
   // replace(creatures.begin(),creatures.end(),b10,by);


   return 0;

}

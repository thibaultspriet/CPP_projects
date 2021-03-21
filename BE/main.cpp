#include "Aquarium.h"
#include "Milieu.h"
#include "ICreature.h"
#include "YeuxDecorator.h"
#include "OreilleDecorator.h"
#include "NageoireDecorator.h"
#include "CamouflageDecorator.h"
#include "CarapaceDecorator.h"

#include "ComportementKamikaze.h"
#include "ComportementPeureuse.h"
#include "ComportementGregaire.h"
#include "ComportementPrevoyante.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30); // Construit l'aquarium de la simulation

   for ( int i = 1; i <= 20 ; ++i )
      if(i<=10){

         Bestiole* bestiole = new Bestiole(new ComportementKamikaze());
         OreilleDecorator* bestiole_rapide = new OreilleDecorator(bestiole);
         CarapaceDecorator* bestiole_solide = new CarapaceDecorator(bestiole_rapide);
         ecosysteme.getMilieu().addMember(bestiole_solide);



         //Bestiole* bestiole = new Bestiole();
         // YeuxDecorator* bestiole_voyante = new YeuxDecorator(bestiole);
         // ecosysteme.getMilieu().addMember( bestiole_voyante );
         
         // OreilleDecorator* bestiole_entend = new OreilleDecorator(bestiole);
         // ecosysteme.getMilieu().addMember( bestiole_entend );

         // NageoireDecorator* bestiole_rapide = new NageoireDecorator(bestiole);
         // ecosysteme.getMilieu().addMember( bestiole_rapide );

         // CamouflageDecorator* bestiole_invisible = new CamouflageDecorator(bestiole);
         // ecosysteme.getMilieu().addMember( bestiole_invisible );
         
         // CarapaceDecorator* bestiole_solide = new CarapaceDecorator(bestiole);
         // ecosysteme.getMilieu().addMember( bestiole_solide );

         // NageoireDecorator* bestiole_rapide = new NageoireDecorator(bestiole);
         // CarapaceDecorator* bestiole_rapide_resitante = new CarapaceDecorator(bestiole_rapide);
         // YeuxDecorator* bestiole_rapide_resitante_voyante = new YeuxDecorator(bestiole_rapide_resitante);
         // ecosysteme.getMilieu().addMember(bestiole_rapide_resitante_voyante);
      }
      else{
         //ecosysteme.getMilieu().addMember( new Bestiole() );
         Bestiole* bestiole = new Bestiole(new ComportementPeureuse());
         ecosysteme.getMilieu().addMember(bestiole);
      }
       // ajoute les bestioles à la simulation
   ecosysteme.run(); // lance la simulation



   return 0;

}

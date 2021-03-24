#include "Aquarium.h"
#include "Milieu.h"

#include "ICreature.h"
#include "ConcreteCreatorBestiole.h"

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
#include <fstream>


using namespace std;


// Premier argument passsé : nom du fichier de simulation
int main(int argc, char *argv[])
{

   if(argc >= 2){
      ofstream file;
      file.open(argv[1],std::ios::app);
      file << "KAMIK,GREG,PEUR,PREV,\n";
      file.close();
   }



   Aquarium       ecosysteme( 640, 480, 30); // Construit l'aquarium de la simulation
   ConcreteCreatorBestiole bestioleCreator;
   Configuration* configuration = ecosysteme.getMilieu().getConfig();


   // ajoute les bestioles à la simulation
   for(int i = 1 ; i <= configuration->getKamik() ; ++i ){
      ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementKamikaze()));   
   };
   
   for(int i = 1 ; i <= configuration->getGreg() ; ++i ){
      ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementGregaire()));   
   };
   
   for(int i = 1 ; i <= configuration->getPeur() ; ++i ){
      ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementPeureuse()));   
   };
   
   for(int i = 1 ; i <= configuration->getPrev() ; ++i ){
      ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementPrevoyante()));   
   };
   

   //ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementPeureuse()));

   ecosysteme.run(argc >= 2 ? argv[1] : ""); // lance la simulation



   return 0;

}

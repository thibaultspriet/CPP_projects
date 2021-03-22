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

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30); // Construit l'aquarium de la simulation
   ConcreteCreatorBestiole bestioleCreator;
   Configuration* configuration = ecosysteme.getMilieu().getConfig();


   //ajoute les bestioles à la simulation
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
   // for(int i = 1 ; i<=20 ; ++i){
   //    ecosysteme.getMilieu().addMember(bestioleCreator.create(new ComportementPrevoyante()));
   // }  
   ecosysteme.run(); // lance la simulation



   return 0;

}

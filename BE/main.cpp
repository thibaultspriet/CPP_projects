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

   // argv 7 = chemin pour le fichier d'enregistrement
   if(argc >= 7){
      ofstream file;
      file.open(argv[7],std::ios::app);
      file << "KAMIK,GREG,PEUR,PREV,\n";
      file.close();
   }

   Aquarium* ecosysteme;

   if(argc >= 6){
      // argv :
      // 2 = nbCreature
      // 3 = pourcentage kamikaze
      // 4 = pourcentage gregaire
      // 5 = pourcentage peureuse
      // 6 = pourcentage prévoyante
      ecosysteme = new Aquarium( 640, 480, 30, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])); // Construit l'aquarium de la simulation
   }
   else{
      ecosysteme = new Aquarium( 640, 480, 30); // Construit l'aquarium de la simulation
   }
   
   ConcreteCreatorBestiole bestioleCreator;
   Configuration* configuration = ecosysteme->getMilieu().getConfig();


   // ajoute les bestioles à la simulation
   for(int i = 1 ; i <= configuration->getKamik() ; ++i ){
      ecosysteme->getMilieu().addMember(bestioleCreator.create(new ComportementKamikaze()));   
   };
   
   for(int i = 1 ; i <= configuration->getGreg() ; ++i ){
      ecosysteme->getMilieu().addMember(bestioleCreator.create(new ComportementGregaire()));   
   };
   
   for(int i = 1 ; i <= configuration->getPeur() ; ++i ){
      ecosysteme->getMilieu().addMember(bestioleCreator.create(new ComportementPeureuse()));   
   };
   
   for(int i = 1 ; i <= configuration->getPrev() ; ++i ){
      ecosysteme->getMilieu().addMember(bestioleCreator.create(new ComportementPrevoyante()));   
   };
   


   const char* pathFile = (argc >= 2) ? argv[1] : "";
   ecosysteme->run(pathFile); // lance la simulation



   return 0;

}

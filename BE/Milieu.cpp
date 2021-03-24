#include "Milieu.h"
#include "ICreature.h"
#include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"

#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPeureuse.h"
#include "ComportementPrevoyante.h"

#include <cstdlib>
#include <ctime>
#include <vector>

#include <fstream>

using namespace std;

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ), width(_width), height(_height)
{
   cout << "const Milieu" << endl;

   // Configuration par défaut
   config = new Configuration();

   std::srand( time(NULL) );
};

Milieu::Milieu(int _width, int _heigh, Configuration* _config) : UImg( _width, _height, 1, 3 ), width(_width), height(_height), config(_config)
{

   cout << "const Milieu" << endl;
   std::srand( time(NULL) );  

}


Milieu::~Milieu( void )
{
   cout << "dest Milieu" << endl;
}


void Milieu::step( const char* pathFileSim )
{
   if(strcmp("",pathFileSim) != 0) {
      writeHowManyCreature(pathFileSim);
   };
   std::vector<ICreature*> toRemoveCreatures; // objet temporaire qui stocke les creatures à supprimer à la fin du pas de simulation
   std::vector<ICreature*> toAppendCreatures; // objet temporaire qui stocke les creatures à ajouter à la fin du pas de simulation
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for (auto it = listeCreatures.begin() ; it != listeCreatures.end() ; ++it ) // appelle l'action et déssinne chaque créature
   {
      (*it)->action( *this, toRemoveCreatures, toAppendCreatures);
      if((*it)->getDureeVie() == 0){
         if(find(toRemoveCreatures.begin(),toRemoveCreatures.end(),*it) == toRemoveCreatures.end()){
            toRemoveCreatures.push_back(*it);
         }
      }
      (*it)->draw( *this, *this, **it );
   } // for
   if(!toRemoveCreatures.empty()){ // supprime les créatures qui sont mortes pendant le pas de simulation
      removeMember(toRemoveCreatures);
   }
   if(!toAppendCreatures.empty()){ // ajoute les créatures qui sont nées pendant le pas de simulation
      for(auto it = toAppendCreatures.begin() ; it != toAppendCreatures.end() ; ++it){
         addMember(*it);
      }
   }
   randomNaissance(config->getConfig());

   

}


void Milieu::randomNaissance(std::map<ComportType,int> config_){
   // Naissance spontanée aléatoire de bestioles
   ConcreteCreatorBestiole bestiole_creator;
   if(config_.find(KAMIK) != config_.end()){
      if(::rand() % 100 + 1 < config_[KAMIK]){
         addMember(bestiole_creator.create(new ComportementKamikaze()));
      }
   }
   
   if(config_.find(GREG) != config_.end()){
      if(::rand() % 100 + 1 < config_[GREG]){
         addMember(bestiole_creator.create(new ComportementGregaire()));
      }
   }
   
   if(config_.find(PEUR) != config_.end()){
      if(::rand() % 100 + 1 < config_[PEUR]){
         addMember(bestiole_creator.create(new ComportementPeureuse()));
      }
   }
   
   if(config_.find(PREV) != config_.end()){
      if(::rand() % 100 + 1 < config_[PREV]){
         addMember(bestiole_creator.create(new ComportementPrevoyante()));
      }
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


int Milieu::howManyCreature(ComportType comportementName) {
      int counter = 0;
      for (auto it = listeCreatures.begin() ; it != listeCreatures.end() ; ++it){
         if((**it).getComportement()->getComportementType() == comportementName){
            ++counter;
         }
      }
      return counter;
}


void Milieu::writeHowManyCreature(std::string path){
   ofstream file;
   file.open(path,std::ios::app);
   int kamik = howManyCreature(KAMIK);
   int greg = howManyCreature(GREG);
   int peur = howManyCreature(PEUR);
   int prev = howManyCreature(PREV);
   file << kamik << "," << greg << "," << peur << "," << prev << "," << endl;
   file.close();
}

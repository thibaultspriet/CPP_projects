#include "ConcreteCreatorEssence.h"
#include "ConcreteCreatorDiesel.h"



int main(int argc, char *argv[]){
    
    VoitureFactory* voiture_essence = new ConcreteCreatorEssence("blue",13453);
    voiture_essence->fillUp();

    VoitureFactory* voiture_diesel = new ConcreteCreatorDiesel("green",5930);
    voiture_diesel->fillUp();

    voiture_diesel->getInfo();
    voiture_essence->getInfo();


    delete voiture_essence; 
    delete voiture_diesel; 

    return 0;
}







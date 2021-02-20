#include "ConcreteCreatorEssence.h"
#include "ConcreteCreatorDiesel.h"



int main(int argc, char *argv[]){
    
    VoitureFactory* voiture_essence = new ConcreteCreatorEssence();
    voiture_essence->fillUp();

    VoitureFactory* voiture_diesel = new ConcreteCreatorDiesel();
    voiture_diesel->fillUp();

    delete voiture_essence; 
    delete voiture_diesel; 

    return 0;
}







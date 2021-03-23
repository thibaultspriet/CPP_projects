#include "NageoireDecorator.h"

#include <iostream>
#include <random>
#include <vector>
using namespace std;

const double NageoireDecorator::MULTIPLE_VITESSE_MAX = 4.0;

NageoireDecorator::NageoireDecorator(ICreature* ic) : AccessoireDecorator(ic){

    std::default_random_engine re;
    std::uniform_real_distribution<double> vitesse_range(1,MULTIPLE_VITESSE_MAX);

    multiple_vitesse = vitesse_range(re);
};

ICreature* NageoireDecorator::clone(){
    cout << "clonage Nageoire decorator" << endl;
    NageoireDecorator* creature_clone = new NageoireDecorator(*this);
    creature_clone->creature = this->creature->clone();
    return creature_clone;
}

std::vector<double> NageoireDecorator::getVitesse() {
    std::vector<double> vitesse = AccessoireDecorator::getVitesse();
    std::transform(
        vitesse.begin(),
        vitesse.end(),
        vitesse.begin(),
        [this](double v){return multiple_vitesse*v;}
    );
    return vitesse;
}

void NageoireDecorator::setVitesse(double vx, double vy){
    AccessoireDecorator::setVitesse(vx / multiple_vitesse,vy / multiple_vitesse);
}

void NageoireDecorator::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{

   creature->draw(support,monMilieu,creatureToDraw);

   T black[] = {(T) 0, (T) 0, (T) 0};
   
   vector<double> vit = creatureToDraw.getComportementVitesseMultiple(monMilieu);

   double orientation = -atan(vit.at(1)/vit.at(0));

   double dx = cos( orientation )*AFF_SIZE/2.1;
   double dy = -sin( orientation )*AFF_SIZE/2.1;

   int x = creatureToDraw.getX();
   int y = creatureToDraw.getY();

   double nx = sin(orientation)*AFF_SIZE/2;
   double ny = cos(orientation)*AFF_SIZE/2;

   double         xt = vit.at(0) > 0 ? x + dx : x - dx;
   double         yt = vit.at(0) > 0 ? y + dy : y - dy;

   support.draw_line(xt - nx, yt - ny, xt - nx*2, yt - ny*2,black);
   support.draw_line(xt + nx, yt + ny, xt + nx*2, yt + ny*2,black);

}

#include "OreilleDecorator.h"

#include <iostream>
#include <random>

using namespace std;

const double OreilleDecorator::DIST_MIN = ICreature::LIMITE_VUE;
const double OreilleDecorator::DIST_MAX = ICreature::LIMITE_VUE * 2.0;

const double OreilleDecorator::DETECTION_MIN = 0;
const double OreilleDecorator::DETECTION_MAX = 1;

OreilleDecorator::OreilleDecorator(ICreature* ic) : CapteurDecorator(ic){

    std::default_random_engine re;
    std::uniform_real_distribution<double> distance_range(DIST_MIN,DIST_MAX);
    std::uniform_real_distribution<double> detection_range(DETECTION_MIN,DETECTION_MAX);

    distance = distance_range(re);
    detection = detection_range(re);
}

ICreature* OreilleDecorator::clone(){
    cout << "clonage Oreille decorator" << endl;
    OreilleDecorator* creature_clone = new OreilleDecorator(*this);
    creature_clone->creature = this->creature->clone();
    return creature_clone;
}

bool OreilleDecorator::jeTeVois(const ICreature & ic) const{
    if(CreatureDecorator::jeTeVois(ic)){
        return true;
    }
    else{
        double         dist;
        dist = std::sqrt( (x-ic.getX())*(x-ic.getX()) + (y-ic.getY())*(y-ic.getY()));
        return dist <= distance && detection > ic.getCamouflage();
    }
}


void OreilleDecorator::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{

   creature->draw(support,monMilieu,creatureToDraw);

   T black[] = {(T) 0, (T) 0, (T) 0};

   vector<double> vit = creatureToDraw.getComportementVitesseMultiple(monMilieu);

   double orientation = -atan(vit.at(1)/vit.at(0));

   int x = creatureToDraw.getX();
   int y = creatureToDraw.getY();

   double nx = sin(orientation)*AFF_SIZE/2;
   double ny = cos(orientation)*AFF_SIZE/2;
   
   double         xo1 = x - nx;
   double         yo1 = y - ny;
   
   double         xo2 = x + nx;
   double         yo2 = y + ny;


   support.draw_circle(xo1,yo1,AFF_SIZE/4,black);
   support.draw_circle(xo2,yo2,AFF_SIZE/4,black);

}
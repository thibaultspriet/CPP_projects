#include "YeuxDecorator.h"

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const double YeuxDecorator::ALPHA_MIN = M_PI / 6.0;
const double YeuxDecorator::ALPHA_MAX = M_PI;

const double YeuxDecorator::DIST_MIN = ICreature::LIMITE_VUE;
const double YeuxDecorator::DIST_MAX = ICreature::LIMITE_VUE * 2.0;

const double YeuxDecorator::DETECTION_MIN = 0.0;
const double YeuxDecorator::DETECTION_MAX = 1.0;


YeuxDecorator::YeuxDecorator(ICreature* ic) : CapteurDecorator(ic) {

    // cout << "const Yeux decorator" << endl ;

    std::default_random_engine re;
    
    std::uniform_real_distribution<double> alpha_range(ALPHA_MIN,ALPHA_MAX);
    std::uniform_real_distribution<double> dist_range(DIST_MIN,DIST_MAX);
    std::uniform_real_distribution<double> detection_range(DETECTION_MIN,DETECTION_MAX);
    
    champVision = alpha_range(re);
    distance = dist_range(re);
    detection = detection_range(re);

    /* cout << "====== BEGIN YEUX DECORATOR CONST ======= " << endl;
    cout << "champ de vision : " << champVision << endl << "distance de détection : " << distance << endl << "coéfficient de détection : " << detection << endl;
    cout << "====== END YEUX DECORATOR CONST ======= " << endl; */
}

ICreature* YeuxDecorator::clone(){
    // cout << "clonage Yeux decorator" << endl;
    YeuxDecorator* creature_clone = new YeuxDecorator(*this);
    creature_clone->creature = this->creature->clone();
    return creature_clone;
}

bool YeuxDecorator::jeTeVois(const ICreature& ic) const{
    if(CreatureDecorator::jeTeVois(ic)){
        return true;
    }
    else{
        double         dist;
        double angle;
        angle = acos( ( x*(ic.getX() - x) + y*(ic.getY() - y) ) / (std::sqrt((x*x + y*y) * (ic.getX()*ic.getX() + ic.getY()*ic.getY()))) );
        dist = std::sqrt( (x-ic.getX())*(x-ic.getX()) + (y-ic.getY())*(y-ic.getY()));
        return angle <= champVision/2 && dist <= distance && detection > ic.getCamouflage();
    }
}


void YeuxDecorator::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{
   creature->draw(support,monMilieu,creatureToDraw);

   T black[] = {(T) 0, (T) 0, (T) 0};

   vector<double> vit = creatureToDraw.getComportementVitesseMultiple(monMilieu);

   double orientation = -atan(vit.at(1)/vit.at(0));

   double dx = cos( orientation )*AFF_SIZE/2.1;
   double dy = -sin( orientation )*AFF_SIZE/2.1;

   int x = creatureToDraw.getX();
   int y = creatureToDraw.getY();
   
   double         xy = vit.at(0) > 0 ? x + dx*2 : x - dx*2;
   double         yy = vit.at(0) > 0 ? y + dy*2 : y - dy*2;

   support.draw_circle(xy,yy,AFF_SIZE/3.5, black);



}

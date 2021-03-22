#include "YeuxDecorator.h"

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const double YeuxDecorator::ALPHA_MIN = M_PI / 6;
const double YeuxDecorator::ALPHA_MAX = M_PI;

const double YeuxDecorator::DIST_MIN = ICreature::LIMITE_VUE;
const double YeuxDecorator::DIST_MAX = ICreature::LIMITE_VUE * 2;

const double YeuxDecorator::DETECTION_MIN = 0;
const double YeuxDecorator::DETECTION_MAX = 1;


YeuxDecorator::YeuxDecorator(ICreature* ic) : CapteurDecorator(ic) {

    std::default_random_engine re;
    
    std::uniform_real_distribution<double> alpha_range(ALPHA_MIN,ALPHA_MAX);
    std::uniform_real_distribution<double> dist_range(DIST_MIN,DIST_MAX);
    std::uniform_real_distribution<double> detection_range(DETECTION_MIN,DETECTION_MAX);
    
    champVision = alpha_range(re);
    distance = dist_range(re);
    detection = detection_range(re);
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


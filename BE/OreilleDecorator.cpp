#include "OreilleDecorator.h"

#include <iostream>
#include <random>

using namespace std;

const double OreilleDecorator::DIST_MIN = ICreature::LIMITE_VUE;
const double OreilleDecorator::DIST_MAX = ICreature::LIMITE_VUE * 2;

const double OreilleDecorator::DETECTION_MIN = 0;
const double OreilleDecorator::DETECTION_MAX = 1;

OreilleDecorator::OreilleDecorator(ICreature* ic) : CapteurDecorator(ic){

    std::default_random_engine re;
    std::uniform_real_distribution<double> distance_range(DIST_MIN,DIST_MAX);
    std::uniform_real_distribution<double> detection_range(DETECTION_MIN,DETECTION_MAX);

    distance = distance_range(re);
    detection = detection_range(re);
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

// void OreilleDecorator::draw(UImg & support){

//     std::vector<double> vitesse = CreatureDecorator::getVitesse();
//     double orientation = -atan(vitesse.at(1)/vitesse.at(0));

//     double dx_t = cos( orientation )*AFF_SIZE/2.1;
//     double dy_t = -sin( orientation )*AFF_SIZE/2.1;

//     double         xt_t = vitesse.at(0) > 0 ? x + dx_t : x - dx_t;
//     double         yt_t = vitesse.at(0) > 0 ? y + dy_t : y - dy_t;
    
//     double         xt_y = vitesse.at(0) > 0 ? x + dx_t*2 : x - dx_t*1.5;
//     double         yt_y = vitesse.at(0) > 0 ? y + dy_t*2 : y - dy_t*1.5;
    
    

//     T    white[] = { (T)255, (T)255, (T)255 };
//     T    black[] = { (T)0, (T)0, (T)0 };

//     support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
//     support.draw_circle( xt_t, yt_t, AFF_SIZE/2., couleur );
//     support.draw_circle( xt_y, yt_y, AFF_SIZE/4., black, 1 );
//     support.draw_circle( xt_y, yt_y, AFF_SIZE/16., white, 1 );
// }
#include "YeuxDecorator.h"

#include <iostream>
#include <cmath>

using namespace std;
YeuxDecorator::YeuxDecorator(ICreature* ic) : CapteurDecorator(ic) {
    
    champVision = M_PI / 3;
    distance = 400;
    detection = 0.7;
    probDeath = 0;
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

/* void YeuxDecorator::draw(UImg & support){

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
// }*/


#include "YeuxDecorator.h"

#include <iostream>

using namespace std;
YeuxDecorator::YeuxDecorator(ICreature* ic) : CapteurDecorator(ic) {
    
    champVision = 1.;
    distance = 2.;
    detection = 0.7;
    probDeath = 0;
}

bool YeuxDecorator::jeTeVois(const ICreature& ic) const{
    return true;
}

void YeuxDecorator::draw(UImg & support){

    double orientation = -atan(vitesse.at(1)/vitesse.at(0));

    double dx_t = cos( orientation )*AFF_SIZE/2.1;
    double dy_t = -sin( orientation )*AFF_SIZE/2.1;

    double         xt_t = vitesse.at(0) > 0 ? x + dx_t : x - dx_t;
    double         yt_t = vitesse.at(0) > 0 ? y + dy_t : y - dy_t;
    
    double         xt_y = vitesse.at(0) > 0 ? x + dx_t*2 : x - dx_t*1.5;
    double         yt_y = vitesse.at(0) > 0 ? y + dy_t*2 : y - dy_t*1.5;
    
    

    T    white[] = { (T)255, (T)255, (T)255 };
    T    black[] = { (T)0, (T)0, (T)0 };

    support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
    support.draw_circle( xt_t, yt_t, AFF_SIZE/2., couleur );
    support.draw_circle( xt_y, yt_y, AFF_SIZE/4., black, 1 );
    support.draw_circle( xt_y, yt_y, AFF_SIZE/16., white, 1 );
}


#include "CarapaceDecorator.h"
#include <random>

const double CarapaceDecorator::PROTEC_DEATH_MAX = 5.0;
const double CarapaceDecorator::DECREASE_VITESSE_MAX = 4.0;

CarapaceDecorator::CarapaceDecorator(ICreature* ic) : AccessoireDecorator(ic) {

    std::default_random_engine re;
    std::uniform_real_distribution<double> protection_range(1,PROTEC_DEATH_MAX);
    std::uniform_real_distribution<double> vitesse_range(1,DECREASE_VITESSE_MAX);

    protection_death = protection_range(re);
    decrease_vitesse = vitesse_range(re);
};

ICreature* CarapaceDecorator::clone(){
    //cout << "clonage Carapace decorator" << endl;
    CarapaceDecorator* creature_clone = new CarapaceDecorator(*this);
    creature_clone->creature = this->creature->clone();
    return creature_clone;
};

std::vector<double> CarapaceDecorator::getVitesse(){
    std::vector<double> vitesse = CreatureDecorator::getVitesse();
    std::transform(
        vitesse.begin(),
        vitesse.end(),
        vitesse.begin(),
        [this](double v){return v / decrease_vitesse;}
    );
    return vitesse;
}

void CarapaceDecorator::setVitesse(double vx, double vy){
    AccessoireDecorator::setVitesse(vx*decrease_vitesse,vy*decrease_vitesse);
}

double CarapaceDecorator::getProbDeath() const {
    //cout << "J'ai une chance de mourir initiale de : " << AccessoireDecorator::getProbDeath() << " et avec ma protection : " << AccessoireDecorator::getProbDeath() / protection_death << endl;
    return AccessoireDecorator::getProbDeath() / protection_death;
}

void CarapaceDecorator::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{
   
   creature->draw(support,monMilieu,creatureToDraw);

   const T    black[] = { (T)0, (T)0, (T)0 };

   int x = creatureToDraw.getX();
   int y = creatureToDraw.getY();

   support.draw_circle(x,y,AFF_SIZE/3, black);

}
#include "CarapaceDecorator.h"
#include <random>

const double CarapaceDecorator::PROTEC_DEATH_MAX = 5;
const double CarapaceDecorator::DECREASE_VITESSE_MAX = 4;

CarapaceDecorator::CarapaceDecorator(ICreature* ic) : AccessoireDecorator(ic) {

    std::default_random_engine re;
    std::uniform_real_distribution<double> protection_range(1,PROTEC_DEATH_MAX);
    std::uniform_real_distribution<double> vitesse_range(1,DECREASE_VITESSE_MAX);

    protection_death = protection_range(re);
    decrease_vitesse = vitesse_range(re);
};

std::vector<double> CarapaceDecorator::getVitesse(){
    //cout << "========== BEGIN Carapace Decorator =========" << endl;
    std::vector<double> vitesse = CreatureDecorator::getVitesse();
    //cout << "Vitesse wrapped creature : " << vitesse.at(0) << " " << vitesse.at(1) << endl;
    std::transform(
        vitesse.begin(),
        vitesse.end(),
        vitesse.begin(),
        [this](double v){return v / decrease_vitesse;}
    );
    //cout << "Viteese multiplied : " << vitesse.at(0) << " " << vitesse.at(1) << endl;
    //cout << "========== END Carapace Decorator =========" << endl;
    return vitesse;
}

void CarapaceDecorator::setVitesse(double vx, double vy){
    AccessoireDecorator::setVitesse(vx*decrease_vitesse,vy*decrease_vitesse);
}

double CarapaceDecorator::getProbDeath() const {
    cout << "J'ai une chance de mourir initiale de : " << AccessoireDecorator::getProbDeath() << " et avec ma protection : " << AccessoireDecorator::getProbDeath() / protection_death << endl;
    return AccessoireDecorator::getProbDeath() / protection_death;
}
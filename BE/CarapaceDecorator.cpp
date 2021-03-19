#include "CarapaceDecorator.h"

CarapaceDecorator::CarapaceDecorator(ICreature* ic) : AccessoireDecorator(ic) {
    protection_death = 2.9;
    decrease_vitesse = 2.;
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
#include "NageoireDecorator.h"

#include <iostream>
#include <vector>
using namespace std;

NageoireDecorator::NageoireDecorator(ICreature* ic) : AccessoireDecorator(ic){
    multiple_vitesse = 4.;
    probDeath = 0;
};

std::vector<double> NageoireDecorator::getVitesse() {
    //cout << "========== BEGIN Nageoire Decorator =========" << endl;
    std::vector<double> vitesse = AccessoireDecorator::getVitesse();
    //cout << "Vitesse wrapped creature : " << vitesse.at(0) << " " << vitesse.at(1) << endl;
    std::transform(
        vitesse.begin(),
        vitesse.end(),
        vitesse.begin(),
        [this](double v){return multiple_vitesse*v;}
    );
    //cout << "Viteese multiplied : " << vitesse.at(0) << " " << vitesse.at(1) << endl;
    //cout << "========== END Nageoire Decorator =========" << endl;
    return vitesse;
}

void NageoireDecorator::setVitesse(double vx, double vy){
    AccessoireDecorator::setVitesse(vx / multiple_vitesse,vy / multiple_vitesse);
}

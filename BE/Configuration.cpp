#include "Configuration.h"

Configuration::Configuration(){
   // Configuration par défaut
   std::map<ComportType,int> conf;
   conf[KAMIK] = 25;
   conf[GREG] = 25;
   conf[PEUR] = 25;
   conf[PREV] = 25;

   int nbCreature = 20;

   this->config = conf;
   this->nb_creature = nbCreature;
};

int Configuration::getGreg(){
    return config.find(GREG) == config.end() ?  0 : floor(config[GREG]  * nb_creature / 100);
};

int Configuration::getKamik(){
    return config.find(KAMIK) == config.end() ?  0 : floor(config[KAMIK]  * nb_creature / 100);
};

int Configuration::getPeur(){
    return config.find(PEUR) == config.end() ?  0 : floor(config[PEUR]  * nb_creature / 100);

};

int Configuration::getPrev(){
    return config.find(PREV) == config.end() ?  0 : floor(config[PREV]  * nb_creature / 100);
};
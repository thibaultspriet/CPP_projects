#include "Configuration.h"

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
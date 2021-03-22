#include "Configuration.h"

int Configuration::getGreg(){
    auto it = find_if(
        config.begin(),
        config.end(),
        [this](const pair<unsigned,ComportType>& element){return element.second == GREG;}
    );
    if(it != config.end()){
        return floor((*it).first  * nb_creature / 100);
    }
    else{
        return 0;
    }
};

int Configuration::getKamik(){
    auto it = find_if(
        config.begin(),
        config.end(),
        [this](const pair<unsigned,ComportType>& element){return element.second == KAMIK;}
    );
    if(it != config.end()){
        return floor((*it).first  * nb_creature / 100);
    }
    else{
        return 0;
    }
};

int Configuration::getPeur(){
    auto it = find_if(
        config.begin(),
        config.end(),
        [this](const pair<unsigned,ComportType>& element){return element.second == PEUR;}
    );
    if(it != config.end()){
        return floor((*it).first  * nb_creature / 100);
    }
    else{
        return 0;
    }
};

int Configuration::getPrev(){
    auto it = find_if(
        config.begin(),
        config.end(),
        [this](const pair<unsigned,ComportType>& element){return element.second == PREV;}
    );
    if(it != config.end()){
        return floor((*it).first  * nb_creature / 100);
    }
    else{
        return 0;
    }
};
#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <iostream>
#include <vector>

#include "IComportement.h"

using namespace std;


/**
 * @brief Classe configuration
 * 
 * Stocke les pourcentages de chaque comportement présent dans la simulation
 * 
 */
class Configuration{
    private:
        int nb_creature; /*!< nombre de créatures que le client souhaite */
        vector<pair<int,ComportType> > config; /*!< pourcentage et comportement */
    public:

        /**
         * @brief Constructeur de Configuration
         * 
         * @param nb_creature nombre de créatures que le client souhaite
         * @param config  pourcentage et comportement
         */
        Configuration(int nb_creature, vector<pair<int,ComportType> > config) : nb_creature(nb_creature),config(config){};
        
        /**
         * @brief Destructeur de Configuration
         * 
         */
        ~Configuration(){};

        /**
         * @brief Retourne le nombre de créatures de la simulation
         * 
         * @return int 
         */
        int getNbCreature(void){return nb_creature;};

        /**
         * @brief Retourne le vecteur de configuration
         * 
         * @return vector<pair<int,ComportType> > 
         */
        vector<pair<int,ComportType> > getConfig(void){return config;};

        /**
         * @brief Retourne le nombre de gregaires
         * 
         * @return int 
         */
        int getGreg(void);

        /**
         * @brief Retourne le nombre de kamikazes
         * 
         * @return int 
         */
        int getKamik(void);

        /**
         * @brief Retourne le nombre de peureuses
         * 
         * @return int 
         */
        int getPeur(void);

        /**
         * @brief Retourne le nombre de prevoyantes
         * 
         * @return int 
         */
        int getPrev(void);
};

#endif
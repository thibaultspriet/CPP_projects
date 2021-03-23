#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <iostream>
#include <vector>
#include <map>

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
        map<ComportType,int> config; /*!< pourcentage et comportement */
    public:

        
        /**
         * @brief Constructeur par défaut de configuration
         * 
         * Retourne une configuration avec 20 bestioles, et avec 25% de chaque comportement qu'on a implémenté (pas multiple)
         * 
         */
        Configuration();

        /**
         * @brief Constructeur de Configuration
         * 
         * @param nb_creature nombre de créatures que le client souhaite
         * @param config  pourcentage et comportement
         */
        Configuration(int nb_creature, map<ComportType,int> config) : nb_creature(nb_creature),config(config){};
        
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
        map<ComportType,int> getConfig(void){return config;};

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


        // ===================== BEGIN Fonctions de  DEBUG =====================
        void printConfiguration(void){
            cout << "===== BEGIN Configuration =====" << endl;
            cout << "Créatures totales : " << nb_creature << endl;
            cout << "Kamikazes : " << getKamik() << endl;
            cout << "Gregaires : " << getGreg() << endl;
            cout << "Peureuses : " << getPeur() << endl;
            cout << "Prevoyantes : " << getPrev() << endl;
            cout << "===== END Configuration =====" << endl;

        }
        // ===================== END Fonctions de  DEBUG =====================
};

#endif
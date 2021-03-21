#ifndef DEF_ICOMPORTEMENT
#define DEF_ICOMPORTEMENT

#include <vector>
#include <iostream>
#include <string>
#include "ICreature.h"
using namespace std;


class ICreature;

// diff�rents types de comportements possibles
enum ComportType
{
	GREG,
	KAMIK,
	MULTI,
	PEUR,
	PREV,
};


/**
 * @brief Class IComportement
 * 
 * classe abstraite qui définit les méthodes que doivent implémenter les différents comportements.
 * 
 */
class IComportement {
	public :
		/**
		 * @brief fonction virtuelle permettant de r�cup�rer le vecteur directeur de vitesse et le coefficient multiplicateur de la valeur de la vitesse
		 * 
		 * @param voisins 
		 * @param creatureAssociee 
		 * @return std::pair<std::vector<double>, double> 
		 */
		virtual std::pair<std::vector<double>, double> calculDirection(std::vector<ICreature*> voisins, ICreature& creatureAssociee) {return make_pair(std::vector<double> (2),0.0);};
		
		/**
		 * @brief Constructeur IComportement
		 * 
		 */
		IComportement() {};

		/**
		 * @brief Destructeur IComportement
		 * 
		 */
		virtual ~IComportement() {};
		
		/**
		 * @brief  fonction virtuelle permettant de r�cup�rer le type de comportement de l'�num�ration ci-dessus
		 * 
		 * @return ComportType 
		 */
		virtual ComportType getComportementType() {return KAMIK;};
};


#endif
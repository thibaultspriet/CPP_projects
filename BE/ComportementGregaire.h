#ifndef DEF_COMPORTEMENTGREGAIRE
#define DEF_COMPORTEMENTGREGAIRE

#include <vector>
#include <iostream>
#include "IComportement.h"

/**
 * @brief Implémentation du comportement grégaire des créatures
 * 
 * Une créature avec ce comportement ajuste sa direction comme la moyenne des directions des bestioles voisines.
 * 
 */
class ComportementGregaire : public IComportement {
	public :
	/**
	 * @brief Constructeur de ComportementGregaire
	 * 
	 */
	ComportementGregaire();

	/**
	 * @brief Réimplémentation de la méthode clone
	 * 
	 * Renvoie la copie d'un objet comportement gregaire
	 * 
	 * @return IComportement* 
	 */
	IComportement* clone() override {cout << "clonnage gregaire" << endl; return new ComportementGregaire(*this);};

	/**
	 * @brief Destructeur de ComportementGregaire
	 * 
	 */
	~ComportementGregaire();

	/**
	 * @brief calcule la direction de la créature
	 * 
	 * @param voisins les créatures voisines que la créature associée peut détecter
	 * @param creatureAssociee la créature emballée
	 * @return pair<vector<double>, double> vecteur directeur de la vitesse, multiplicateur de la norme de la vitesse 
	 */
	pair<vector<double>, double> calculDirection(vector<ICreature*> voisins, ICreature& creatureAssociee) override;

	/**
	 * @brief Retourne le comportement
	 * 
	 * @return ComportType 
	 */
	ComportType getComportementType() override { return GREG; };
};

#endif
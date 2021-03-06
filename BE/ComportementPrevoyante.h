#ifndef DEF_COMPORTEMENTPREVOYANTE
#define DEF_COMPORTEMENTPREVOYANTE

#include <vector>
#include <iostream>
#include "IComportement.h"

/**
 * @brief Implémentation du comportement prévoyant des créatures
 * 
 */
class ComportementPrevoyante : public IComportement {
	public:
		/**
		 * @brief Constructeur de ComportementPRevoyante
		 * 
		 */
		ComportementPrevoyante();

		/**
		 * @brief Réimplémentation de la méthode clone
		 * 
		 * Renvoie la copie d'un objet comportement prevoyante
		 * 
		 * @return IComportement* 
		 */
		IComportement* clone() override {/* cout << "clonnage prevoyante" << endl; */return new ComportementPrevoyante(*this);};


		/**
		 * @brief Destructeur de ComportementPrevoyante
		 * 
		 */
		~ComportementPrevoyante();

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
		ComportType getComportementType() override { return PREV; };
};

#endif

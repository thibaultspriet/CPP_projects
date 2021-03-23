#ifndef DEF_COMPORTEMENTKAMIKAZE
#define DEF_COMPORTEMENTKAMIKAZE

#include <iostream>
#include "IComportement.h"
#include <vector>

/**
 * @brief Implémentation du comportement Kamikaze
 * 
 * Une créature dotée de ce comportement, essaye d'attaquer la créature la plus proche d'elle.
 * 
 */
class ComportementKamikaze : public IComportement {
	private :		
		static const int m_coefAttaque; /*!< coefficient multiplicateur de la vitesse */

	public:
		/**
		 * @brief Constructeur de ComportementKamikaze
		 * 
		 */
		ComportementKamikaze();

		/**
		 * @brief Réimplémentation de la méthode clone
		 * 
		 * Renvoie la copie d'un objet comportement kamikaze
		 * 
		 * @return IComportement* 
		 */
		IComportement* clone() override {cout << "clonnage kamikaze" << endl;return new ComportementKamikaze(*this);};


		/**
		 * @brief Destructeur de ComportementKamikaze
		 * 
		 */
		~ComportementKamikaze();

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
		ComportType getComportementType() override { return KAMIK; };
};

// ajout d'une fonction pour calculer la distance entre deux points
/**
 * @brief foncion outil qui permet de calculer la distance entre deux points.
 * 
 * @param xA 
 * @param yA 
 * @param xB 
 * @param yB 
 * @return double 
 */
double calculDistance(int xA, int yA, int xB, int yB);

// ajout d'une fonction pour calculer le vecteur entre deux points
/**
 * @brief foncion outil qui permet de calculer un vecteur entre deux points.
 *
 * @param xA
 * @param yA
 * @param xB
 * @param yB
 * @return vector<double>
 */
vector<double> vecteurEntreDeuxPoints(int xA, int yA, int xB, int yB);

#endif

#ifndef DEF_COMPORTEMENTPEUREUSE
#define DEF_COMPORTEMENTPEUREUSE

#include <iostream>
#include "IComportement.h"
#include <vector>

/**
 * @brief Implémentation du comportement peureux des créatures
 * 
 * Une créature peureuse fuit lorsqu'il y a trop de créatures autour d'elle
 * 
 */
class ComportementPeureuse : public IComportement {
	private:
		int m_seuil; /*!< nombre de créature à partir duquel la créature décide de fuir */

public:

	/**
	 * @brief Constructeur de ComportementPeureuse avec un seuil précis
	 * 
	 * @param seuil 
	 */
	ComportementPeureuse(int seuil);

	/**
	 * @brief Réimplémentation de la méthode clone
	 * 
	 * Renvoie la copie d'un objet comportement peureuse
	 * 
	 * @return IComportement* 
	 */
	IComportement* clone() override {cout << "clonnage peureuse" << endl;return new ComportementPeureuse(*this);};


	/**
	 * @brief Constructeur de ComportementPeureuse par défaut
	 * 
	 */
	ComportementPeureuse();

	/**
	 * @brief Destructeur de ComportementPeureuse
	 * 
	 */
	~ComportementPeureuse();

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
	ComportType getComportementType() override { return PEUR; };
	int getSeuil();
};

#endif

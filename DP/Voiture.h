#include <string>
using namespace std;

/*!
Interface Voiture. Caractérisée par une couleur et un numéro d'identification.
Cette classe implémente les getter et setter de ses attributs.
Deux méthodes virtuelles pures sont déclarées et doivent être implémentées dans les classes fille.
Ces méthodes correspondent aux "actions" que tout type de voiture ; quelle soit à essence ou diesel ; doit pouvoir faire.
*/

class Voiture{

    string color; //!< couleur du véhicule (string)
    int number; //!< numéro d'identification du véhicule (int)

    public:
        /*!
        getter pour la couleur
        \return string couleur
        */
        string getColor();

        /*!
        getter pour le numéro
        \return int numéro
        */
        int getNumber();

        /*!
        setter pour la couleur
        \param color un string
        */
        void setColor(string color);

        /*!
        setter pour le numéro
        \param number un entier
        */
        void setNumber(int number);

        /*!
        Méthode virtuelle pure, doit être implémentée par chaque classe fille.
        Simule une voiture qui fait le plein de carburant
        */
        virtual void fillUp() = 0;

        /*!
        Méthode virtuelle pure, doit être implémentée par chaque classe fille.
        Print les informations relatives à la voiure
        */
        virtual void toString() = 0;

        /*!
        Destructeur par défaut.
        */
        virtual ~Voiture();
};
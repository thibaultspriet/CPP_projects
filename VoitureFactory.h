#ifndef VOITURE
#define VOITURE
#include "Voiture.h"
#endif

/*!
Interface qui permet au "client" de créer des objets abstraits de type Voiture.
Cette interface délègue la création d'un certain type de voiture à ses classes filles.
Cette interface met à disposition les méthodes qu'on peut appeler sur un objet de type voiture.
*/

class VoitureFactory
{
    string  color; //!< couleur de la voiture (string)
    int number; //!< numéro d'identification de la voiture (int)

    public:
        /*!
        Méthode virtuelle pure. Méthode qui permet de créer un objet voiture
        */
        virtual Voiture* getVoiture() = 0;

        /*!
        Destructeur par défaut.
        */
        virtual ~VoitureFactory();

        /*!
        getter pour la couleur
        \return string couleur
        */
        string getColor();

        /*!
        setter pour la couleur
        \param color string
        */
        void setColor(string color);

        /*!
        getter pour le numéro
        \return int numéro
        */
        int getNumber();

        /*!
        setter pour le numéro
        \param number int
        */
        void setNumber(int number);

        /*!
        Méthode qui invoque la méthode fillUp des objets Voiture
        */
        void fillUp();

        /*!
        Méthode qui invoque la méthode toString des objets Voiture
        */
        void getInfo();

};

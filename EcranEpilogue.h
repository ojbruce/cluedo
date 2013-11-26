#ifndef DEF_ECRANEPILOGUE
#define DEF_ECRANEPILOGUE

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"

class ManagerEcran;

/**
 * EcranEpilogue est la classe représentant l'ecran de fin.
 *
 * Il est caractérisé par les informations suivantes :
 * deux boutons
 * une image
 * un manager permettant de changer d'ecran
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class EcranEpilogue : public Ecran
{
	public:

        EcranEpilogue (ManagerEcran *manager);

        void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);                 // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

        sf::Texture image;  // Texture de l'ecran final
        sf::Sprite ecran;   // Sprite de l'ecran final

        Bouton fermer;

        ManagerEcran *manager;  //Le manager d'ecran qui se charge des ecrans

};
#endif

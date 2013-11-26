#ifndef DEF_ECRANREGLES
#define DEF_ECRANREGLES

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"

class ManagerEcran;

/**
 * EcranRegles est la classe représentant l'ecran des regles du jeu.
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
class EcranRegles : public Ecran
{
	public:

        EcranRegles(ManagerEcran *manager);

        void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);                 // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

      sf::Texture image;                // Texture de l'ecran d'accueil
      sf::Sprite ecran;                 // Sprite de l'ecran d'accueil

      Bouton fermer;

      ManagerEcran *manager;

};
#endif

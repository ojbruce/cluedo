#ifndef DEF_ECRANACCUEIL
#define DEF_ECRANACCUEIL

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "Ecran.h"
#include "Bouton.h"

class ManagerEcran;

/**
 * EcranAccueil est la classe représentant l'ecran d'accueil du jeu.
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
class EcranAccueil : public Ecran
{
	public:

      EcranAccueil(ManagerEcran* manager);

      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event);                // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

      sf::Texture image;        // Texture de l'ecran d'accueil
      sf::Sprite accueil;       // Sprite de l'ecran d'accueil

      Bouton jouer;             //Le bouton jouer pour aller vers l'ecran de configuration
      Bouton regles;            //Le bouton pour aller vers l'ecran des regles

      ManagerEcran* manager;    //Un pointeur ver le manager d'ecran

};
#endif

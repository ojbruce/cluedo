#ifndef DEF_ECRANACCUEIL
#define DEF_ECRANACCUEIL

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "ManagerEcran.h"
#include "Bouton.h"


class EcranAccueil : public Ecran
{
	public:

      EcranAccueil(ManagerEcran *manager);
      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event);                // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

      sf::Texture image;        // Texture de l'ecran d'accueil
      sf::Sprite accueil;       // Sprite de l'ecran d'accueil

      Bouton jouer;             //Le bouton jouer pour aller vers l'ecran de config
      Bouton regles;            //Le bouton pour aller vers l'ecran des regles

      ManagerEcran *manager;    //Un pointeur ver le manager d'ecran

};
#endif

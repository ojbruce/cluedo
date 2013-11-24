#ifndef DEF_FENETREINFO
#define DEF_FENETREINFO

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "ManagerFenetre.h"
#include "Bouton.h"


class FenetreInfo : public Fenetre
{
	public:

      FenetreInfo(ManagerFenetre *manager);
      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event, sf::RenderWindow &fenetre);                // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

      sf::Texture image;                // Texture de l'ecran d'accueil
      sf::Sprite fond;               // Sprite de l'ecran d'accueil

      Bouton ok;

      ManagerFenetre *manager;

};
#endif

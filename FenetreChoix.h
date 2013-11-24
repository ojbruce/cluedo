#ifndef DEF_FENETRECHOIX
#define DEF_FENETRECHOIX

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "ManagerFenetre.h"
#include "Bouton.h"


class FenetreChoix : public Fenetre
{
	public:

      FenetreChoix(ManagerFenetre *manager);
      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event, sf::RenderWindow &fenetre);                // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

      sf::Texture image;
      sf::Sprite fond;

      Bouton valider;

      ManagerFenetre *manager;

};
#endif

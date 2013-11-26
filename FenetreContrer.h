#ifndef DEF_FENETRECONTRER
#define DEF_FENETRECONTRER

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "ManagerFenetre.h"
#include "Bouton.h"


class FenetreContrer : public Fenetre
{
	public:

      FenetreContrer(ManagerFenetre *manager);
      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event, sf::RenderWindow &fenetre);                // Cette fonction permet le changement d'ecran en fonction des evenements
      void setACliqueFalse();

      void mettreTextureContrer();
      void mettreTexturePasContrer();

   private :

      sf::Texture contrerPossible;
      sf::Texture contrerImpossible;
      sf::Sprite fond;

      Bouton ok;

      ManagerFenetre *manager;

      bool aClique;

};
#endif

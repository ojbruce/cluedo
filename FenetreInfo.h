#ifndef DEF_FENETREINFO
#define DEF_FENETREINFO

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "ManagerFenetre.h"
#include "Bouton.h"

/**
 * FenetreContrer est la classe représentant l'ecran montrant le contre.
 *
 * Il est observer par patie et le notifie lorsque les boutons sont selectionné
 *
 * Il est caractérisé par les informations suivantes :
 * des boutons
 * des observateurs
 * un manager permettant de changer d'ecran
 *
 *Herite de fenetre
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class FenetreInfo : public Fenetre
{
	public:

      FenetreInfo(ManagerFenetre *manager);
      void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
      void update(sf::Event event, sf::RenderWindow &fenetre);                // Cette fonction permet le changement d'ecran en fonction des evenements
      void setACliqueFalse();

   private :

      sf::Texture image;                // Texture de l'ecran d'accueil
      sf::Sprite fond;               // Sprite de l'ecran d'accueil

      Bouton ok;

      ManagerFenetre *manager;

      bool aClique;

};
#endif

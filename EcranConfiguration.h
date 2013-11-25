#ifndef DEF_ECRANCONFIGURATION
#define DEF_ECRANCONFIGURATION

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"

class ManagerEcran;

class EcranConfiguration : public Ecran
{
	public:

      EcranConfiguration(ManagerEcran *manager);
      virtual void creerPartie(){};
      void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
      void update(sf::Event event);                 // Cette fonction permet le changement d'ecran en fonction des evenements
      bool selectionValide();

   private :

      sf::Texture image;                // Texture de l'ecran d'accueil
      sf::Sprite ecran;                 // Sprite de l'ecran d'accueil

      Bouton jouer;
      Bouton nb2;
      Bouton nb3;
      Bouton nb4;
      Bouton nb5;
      Bouton nb6;
      Bouton nb7;
      Bouton nb8;

      ManagerEcran *manager;

      void changement(Bouton &b1,Bouton &b2,Bouton &b3,Bouton &b4, Bouton &b5, Bouton &b6,Bouton &b7, int nombre);


};
#endif

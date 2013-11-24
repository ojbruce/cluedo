#include "FenetreInfo.h"
#include "ManagerFenetre.h"


#include <iostream>
using namespace std;

   /** _____________________________________________________
    * Constructeur
    * Role : initialise les attribut de l'ecran d'accueil
    */

   FenetreInfo::FenetreInfo(ManagerFenetre *man) :
      ok(Bouton("Images/okDepart.png", "Images/okClique.png")),
      manager(man)
   {
      // On charge l'image d'accueil dans la texture "image"
      image.loadFromFile("Images/info.png");

      // On met la texture dans le sprite accueil
      fond.setTexture(image);
   }


   /** _____________________________________________________
    * Fonction afficher
    */

   void FenetreInfo::afficher(sf::RenderWindow &fenetre)
   {
      // Affichage des elements

      fenetre.draw(fond);

      sf::Sprite sp;

      sp = ok.getSprite();
      sp.move(sf::Vector2f(400, 400));
      fenetre.draw(sp);
   }


   /** _____________________________________________________
    * Fonction update
    * Role :
    */

   void FenetreInfo::update(sf::Event event, sf::RenderWindow &fenetre)
   {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;

      if(200<=x && x<=370 && 400<=y && y<=470)
      {
         ok.clique();
         fenetre.close();
      }

   }



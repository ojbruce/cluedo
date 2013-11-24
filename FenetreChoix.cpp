#include "FenetreChoix.h"
#include "ManagerFenetre.h"


#include <iostream>
using namespace std;

   /** _____________________________________________________
    * Constructeur
    * Role :
    */

   FenetreChoix::FenetreChoix(ManagerFenetre *man) :
      valider(Bouton("Images/validerDepart.png", "Images/validerClique.png")),
      manager(man)
   {
      // On charge l'image d'accueil dans la texture "image"
      image.loadFromFile("Images/accuser.png");

      // On met la texture dans le sprite accueil
      fond.setTexture(image);
   }


   /** _____________________________________________________
    * Fonction afficher
    */

   void FenetreChoix::afficher(sf::RenderWindow &fenetre)
   {

      // Affichage des elements

      fenetre.draw(fond);

      sf::Sprite sp;

      sp = valider.getSprite();
      sp.move(sf::Vector2f(400, 400));
      fenetre.draw(sp);

      cerr << "afficher faite" << endl;
   }


   /** _____________________________________________________
    * Fonction update
    * Role :
    */

   void FenetreChoix::update(sf::Event event, sf::RenderWindow &fenetre)
   {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;

      if(400<=x && x<=500 && 400<=y && y<=470)
      {
         valider.clique();
         //manager->setFenetreCourante(manager->getFenetreChoix());
         fenetre.close();

      }

      cerr << "update" << endl;
   }



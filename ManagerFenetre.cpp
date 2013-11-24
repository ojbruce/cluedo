#include "ManagerFenetre.h"
#include "FenetreChoix.h"
#include "FenetreInfo.h"

   /** _____________________________________________________
    * Constructeur
    */

   ManagerFenetre::ManagerFenetre()
   {
      fenetreInfo = new FenetreInfo(this);
      fenetreChoix = new FenetreChoix(this);

   }


   /** _____________________________________________________
    *  Destructeur
    */

   ManagerFenetre::~ManagerFenetre()
   {
      //dtor
   }


   /** _____________________________________________________
    * Fonction ouvrirFenetreChoix
    */

   void ManagerFenetre::ouvrirFenetreChoix()
   {

      // creation de la fenetre
      sf::RenderWindow window(sf::VideoMode(900, 550), "...");

      while (window.isOpen())
      {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // gestion des cliques
            if (event.type == sf::Event::MouseButtonPressed)
            {
               if (event.mouseButton.button == sf::Mouse::Left)
               {
                  fenetreChoix->update(event,window);
               }
            }
        }

        // affichage de la fenetre
        window.clear();
        fenetreChoix->afficher(window);

        window.display();
      }
   }


   /** _____________________________________________________
    * Fonction ouvrirFenetreInfo
    */

   void ManagerFenetre::ouvrirFenetreInfo()
   {

      // creation de la fenetre
      sf::RenderWindow window(sf::VideoMode(900, 550), "...");

      while (window.isOpen())
      {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // gestion des cliques
            if (event.type == sf::Event::MouseButtonPressed)
            {
               if (event.mouseButton.button == sf::Mouse::Left)
               {
                  fenetreInfo->update(event,window);
               }
            }
        }


        // affichage de la fenetre
        window.clear();
        fenetreInfo->afficher(window);

        window.display();
      }
   }



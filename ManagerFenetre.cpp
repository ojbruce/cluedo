#include "ManagerFenetre.h"
#include "FenetreChoix.h"
#include "FenetreInfo.h"


/**
* Constructeur
*/

ManagerFenetre::ManagerFenetre()
{
    fenetreInfo = new FenetreInfo(this);
    fenetreChoix = new FenetreChoix(this);
}


/*
*  Destructeur
*/
ManagerFenetre::~ManagerFenetre()
{
    //dtor
}


/*
* Fonction ouvrirFenetreChoix
*/
void ManagerFenetre::ouvrirFenetreChoix()
{
	fenetreChoix->setACliqueFalse();
	
    // creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(900, 570), "...");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // gestion des cliques
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    fenetreChoix->update(event,window);
            }
        }

        // affichage de la fenetre
        window.clear();
        fenetreChoix->afficher(window);

        window.display();
      }
   }


/*
* Fonction ouvrirFenetreInfo
*/
void ManagerFenetre::ouvrirFenetreInfo()
{
	fenetreInfo->setACliqueFalse();

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
                  fenetreInfo->update(event,window);
            }
        }

        // affichage de la fenetre
        window.clear();
        fenetreInfo->afficher(window);

        window.display();
    }
}


/*
* Fonction observerChoix
*/
void ManagerFenetre::observerChoix(Observer* observer)
{
    fenetreChoix->ajouterObs(observer);                    
}


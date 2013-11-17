#include "Jeu.h"

Jeu::Jeu()
{
    //ctor
}

Jeu::~Jeu()
{
    //dtor
}

void Jeu::lancerJeu(){

    //Creation d'une fenetre
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Jeu du cluedo", sf::Style::Titlebar|sf::Style::Close);

    //charger les donnees


   	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
     	   	//Gere la fermeture de la fenetre
            if (event.type == sf::Event::Closed)
                window.close();

       	}


      	window.clear();

        //on update l'ecran acec l'evenement
        manEcran.update(window, event);

        //On affiche les changements
        window.display();
    }

}


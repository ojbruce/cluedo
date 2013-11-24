#include "Jeu.h"

Jeu::Jeu():donneesJeu(&donnees), manEcran(&donneesJeu){}

Jeu::~Jeu()
{
    //dtor
}

void Jeu::lancerJeu(){

    //Creation d'une fenetre
    sf::RenderWindow window(sf::VideoMode(1296, 720), "Jeu du cluedo", sf::Style::Titlebar|sf::Style::Close);

   	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
     	   	//Gere la fermeture de la fenetre
            if (event.type == sf::Event::Closed)
                window.close();
            // Si il y a eu un clique
            if (event.type == sf::Event::MouseButtonPressed){

                if (event.mouseButton.button == sf::Mouse::Left)
                    manEcran.update(event);
            }
       	}


      	window.clear();

        //on update l'ecran acec l'evenement
        manEcran.afficher(window);

        //On affiche les changements
        window.display();
    }

}


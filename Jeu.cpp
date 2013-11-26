#include "Jeu.h"

Jeu* Jeu::jeu = NULL;
std::mutex Jeu::mu;

Jeu::Jeu():donneesJeu(&donnees), manEcran(&donneesJeu){}


/**
 * Methode qui va retourner une instance de jeu
 * @return une instance de jeu
 */
Jeu* Jeu::getInstance(){
    if(jeu==NULL){
        mu.lock();

        jeu = new Jeu();

        mu.unlock();

    }

    return jeu;

}

/**
* Methode qui lance le jeu.
*/
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

        //on update l'ecran avec l'evenement
        manEcran.afficher(window);

        //on affiche les changements
        window.display();
    }

}


#include "EcranAccueil.h"
#include "ManagerEcran.h"

#include <iostream>

using namespace std;


/**
* Constructeur
*/
EcranAccueil::EcranAccueil(ManagerEcran *man) : jouer(Bouton("Images/jouerDepart.png", "Images/jouerClique.png")), regles(Bouton("Images/reglesDepart.png", "Images/reglesClique.png")) , manager(man)
{
    // on charge l'image d'accueil dans la texture "image"
    image.loadFromFile("Images/accueil.png");

    // on met la texture dans le sprite accueil
    accueil.setTexture(image);
}


/**
* Fonction afficher
*/
void EcranAccueil::afficher(sf::RenderWindow &fenetre)
{
    sf::Event event;
    while (fenetre.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            fenetre.close();
    }

    // affichage des elements
    fenetre.draw(accueil);

    sf::Sprite sp1 = jouer.getSprite();
    sp1.move(sf::Vector2f(405, 570));
    fenetre.draw(sp1);

    sf::Sprite sp2 = regles.getSprite();
    sp2.move(sf::Vector2f(780, 570));
    fenetre.draw(sp2);

    // affichage des changements
    fenetre.display();
}


/**
* Fonction update
*/
void EcranAccueil::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if(405 <= x && x<= 570 && 570<=y && y<=663)
    {
        jouer.clique();
        manager->setEcranCourant(manager->getEcranConfiguration());
    }

    if(780<=x && x<=890 && 570<=y && y<=663)
    {
        regles.clique();
        manager->setEcranCourant(manager->getEcranRegles());
    }

}

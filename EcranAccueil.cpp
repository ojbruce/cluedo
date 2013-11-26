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
    if(!image.loadFromFile("Images/accueil.png")){};

    // on met la texture dans le sprite accueil
    accueil.setTexture(image);
}


/**
 * Methode qui va afficher l'ecran tel qu'il est
 * @param fenetre la fenetre sur laquelle on va appliquer les changementd
 */
void EcranAccueil::afficher(sf::RenderWindow &fenetre)
{
    sf::Sprite sp1 = jouer.getSprite();
    sp1.move(sf::Vector2f(405, 570));

    sf::Sprite sp2 = regles.getSprite();
    sp2.move(sf::Vector2f(780, 570));

    // affichage des elements
    fenetre.draw(accueil);
    fenetre.draw(sp1);
    fenetre.draw(sp2);
}


/**
 * Methode qui permet le changement d'ecran en fonction des evenements
 * @param event un evenement envoyé par les classes superieurs
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

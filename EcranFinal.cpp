#include "EcranFinal.h"
#include "ManagerEcran.h"

#include <iostream>

using namespace std;


/**
* Constructeur
*/
EcranFinal::EcranFinal(ManagerEcran *man, DonneesJeu* don) :
    ok(Bouton("Images/okDepart.png", "Images/okClique.png")),
    manager(man),
    donnees(don)
{
    // On charge l'image de fond dans la texture "image"
    image.loadFromFile("Images/final.png");

    // On met la texture dans le sprite ecran
    ecran.setTexture(image);
}


/**
* Fonction afficher
*/
void EcranFinal::afficher(sf::RenderWindow &fenetre)
{

    if(ok.getClique()==true)
    {
        // on passe a l'écran Epilogue
        manager->setEcranCourant(manager->getEcranEpilogue());
    }

    // Affichage des elements
    fenetre.draw(ecran);

    sf::Sprite sp = ok.getSprite();
    sp.move(sf::Vector2f(588, 610));
    fenetre.draw(sp);

    //on affiche le joueur gagnant
    sf::Texture texture;
    texture= donnees->getGagnant()->getTexture();

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(610,350);

    fenetre.draw(sprite);
}


/**
* Fonction update
*/
void EcranFinal::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    // si l'utilisateur clique sur le bouton ok
    if(588<=x && x<=708 && 610<=y && y<=690)
    {
        // on enfonce le bouton
        ok.clique();
    }
}


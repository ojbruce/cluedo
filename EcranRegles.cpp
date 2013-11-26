#include "EcranRegles.h"
#include "ManagerEcran.h"

#include <iostream>
using namespace std;


/**
* Constructeur
*/
EcranRegles::EcranRegles(ManagerEcran *man) : fermer(Bouton("Images/fermerDepart.png", "Images/fermerClique.png")), manager(man)
{
   // On charge l'image dans la texture "image"
   image.loadFromFile("Images/regles.png");

   // On met la texture dans le sprite ecran
   ecran.setTexture(image);
}


/**
* Fonction afficher
* @param window la fenetre
*/
void EcranRegles::afficher(sf::RenderWindow &fenetre)
{
    // Affichage des elements
    fenetre.draw(ecran);

    sf::Sprite sp = fermer.getSprite();
    sp.move(sf::Vector2f(600, 640));
    fenetre.draw(sp);
}


/**
* Cette fonction permet le changement d'ecran en fonction des evenements
* @param event un evenement envoyé par les classes superieurs
*/
void EcranRegles::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if(600<= x && x<= 700 && 640<=y && y<=696)
    {
        fermer.clique();
        manager->setEcranCourant(manager->getEcranConfiguration());
    }
}



#include "EcranEpilogue.h"
#include "ManagerEcran.h"

#include <iostream>

using namespace std;


/**
* Constructeur
*/
EcranEpilogue::EcranEpilogue(ManagerEcran *man) :
    fermer(Bouton("Images/fermerDepart.png", "Images/fermerClique.png")),
    manager(man)
{
    // On charge l'image de fond dans la texture "image"
    image.loadFromFile("Images/epilogue.png");

    // On met la texture dans le sprite ecran
    ecran.setTexture(image);
}


/**
 * Fonction afficher
 * @param window la fenetre
 */
void EcranEpilogue::afficher(sf::RenderWindow &fenetre)
{

    if (fermer.getClique()==true)
        fenetre.close();

    // Affichage des elements
    fenetre.draw(ecran);

    sf::Sprite sp = fermer.getSprite();
    sp.move(sf::Vector2f(588, 630));
    fenetre.draw(sp);
}


/**
 * Cette fonction permet le changement d'ecran en fonction des evenements
 * @param event un evenement envoyé par les classes superieurs
 */
void EcranEpilogue::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    // si l'utilisateur clique sur le bouton fermer
    if(588<=x && x<=708 && 630<=y && y<=700)
    {
        // on enfonce le bouton
        fermer.clique();
    }
}


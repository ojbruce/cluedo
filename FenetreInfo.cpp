#include "FenetreInfo.h"
#include "ManagerFenetre.h"

#include <iostream>

using namespace std;

/**
* Constructeur
* Role : initialise les attribut de l'ecran d'accueil
*/
FenetreInfo::FenetreInfo(ManagerFenetre *man) :
    ok(Bouton("Images/okDepart.png", "Images/okClique.png")),
    manager(man),
    aClique(false)
{
    // On charge l'image d'accueil dans la texture "image"
    image.loadFromFile("Images/info.png");

    // On met la texture dans le sprite accueil
    fond.setTexture(image);
}


/**
 * Cette fonction lance l'affichage de la fênetre
 * @param window la fenetre
 */
void FenetreInfo::afficher(sf::RenderWindow &fenetre)
{
	if(aClique==false)
	{
		ok.deselection();
	}

    // Affichage des elements
    fenetre.draw(fond);

    sf::Sprite sp;

    sp = ok.getSprite();
    sp.move(sf::Vector2f(400, 400));
    fenetre.draw(sp);
}


/**
 * Cette fonction maj les elements de l'ecran jeu
 * @param event un evenement envoyé par les classes superieurs
 */
void FenetreInfo::update(sf::Event event, RenderWindow &fenetre)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    aClique = true;

    if(400<=x && x<=470 && 400<=y && y<=470)
    {
        ok.clique();
        fenetre.close();
    }
}


/**
* Fonction setAClique
*/
void FenetreInfo::setACliqueFalse()
{
	aClique = false;
}


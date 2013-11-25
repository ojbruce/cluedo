#include "Bouton.h"


/**
* Constructeur
*
*/
Bouton::Bouton(string depart, string clique)
{
        imageDepart.loadFromFile(depart);
        imageClique.loadFromFile(clique);
        cadreDepart.setTexture(imageDepart);
        cadreClique.setTexture(imageClique);
        enfonce = false;
}


/**
*  Fonction getSprite
*
*/
sf::Sprite Bouton::getSprite()
{
    if(enfonce == true)
        return cadreClique;
    else
        return cadreDepart;
}


/**
*  Fonction getClique
*/
bool Bouton::getClique()
{
    return enfonce;
}


/**
*  Fonction clique
*/
void Bouton::clique()
{
    if(enfonce == true)
        enfonce = false;
    else
        enfonce = true;
}


/**
*  Fonction deselection
*/
void Bouton::deselection()
{
    if(enfonce == true)
        enfonce = false;
}

/**
*  Fonction selection
*/
void Bouton::selection()
{
    if(enfonce == false)
        enfonce = true;
}


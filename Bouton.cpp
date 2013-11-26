#include "Bouton.h"


/**
 * Constructeur
 * @param depart le chemin de l'image de depart
 * @param clique le chemin de l'image cliquee
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
 * Methode qui va cliquer le bouton
 */
void Bouton::clique()
{
    if(enfonce == true)
        enfonce = false;
    else
        enfonce = true;
}

/**
 * Methode qui va deselectionner le bouton
 */
void Bouton::deselection()
{
    if(enfonce == true)
        enfonce = false;
}

/**
 * Methode qui va selectionner le bouton
 */
void Bouton::selection()
{
    if(enfonce == false)
        enfonce = true;
}




//Getter-Setter

/**
* Methode qui va recupere le sprite de l'image du bouton à afficher
* @return un sprite représentant soit l'image de depart soit l'image cliquee
*/
sf::Sprite Bouton::getSprite()
{
    if(enfonce == true)
        return cadreClique;
    else
        return cadreDepart;
}


/**
* Methode qui recupere le bouton clique
* @param enfonce un booleen representant si le bouton est clique
*/
bool Bouton::getClique()
{
    return enfonce;
}

#include "CartePersonnage.h"

/**
* Constructeur
*/
CartePersonnage::CartePersonnage(string n, string ch){
    nom = n;
    chemin = ch;

     if(!texture.loadFromFile(chemin)){}
}


/**
* Destructeur
*/
CartePersonnage::~CartePersonnage(){}

/**
 * Recupere le nom de la carte
 * @return nom le nom de la carte
 */
string CartePersonnage::getNom(){
    return nom;
}

/**
 * Recupere la texture de la carte
 * @return nom le nom de la carte
 */
sf::Texture& CartePersonnage::getTexture(){
    return texture;
}

/**
* Recupere le chemin vers la carte
* @return chemin le chemin absolu vers la carte
*/
string CartePersonnage::getChemin(){
    return chemin;
}

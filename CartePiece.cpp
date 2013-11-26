#include "CartePiece.h"

/**
* Constructeur
*/
CartePiece::CartePiece(string n, string ch){
    nom = n;
    chemin = ch;

     if(!texture.loadFromFile(chemin)){}
}



/**
 * Recupere le nom de la carte
 * @return nom le nom de la carte
 */
string CartePiece::getNom(){
    return nom;
}


/**
 * Recupere la texture de la carte
 * @return nom le nom de la carte
 */
sf::Texture& CartePiece::getTexture(){
    return texture;
}


/**
* Recupere le chemin vers la carte
* @return chemin le chemin absolu vers la carte
*/
string CartePiece::getChemin(){
    return chemin;
}

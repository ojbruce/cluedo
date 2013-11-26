#include "CarteArme.h"


using namespace std;

/**
* Constructeur
*/
CarteArme::CarteArme(string n, string ch){
    nom = n;
    chemin = ch;

     if(!texture.loadFromFile(chemin)){}
}


/**
 * Recupere le nom de la carte
 * @return nom le nom de la carte
 */
string CarteArme::getNom(){
    return nom;
}

/**
 * Recupere la texture de la carte
 * @return nom le nom de la carte
 */
sf::Texture& CarteArme::getTexture(){
    return texture;
}

/**
* Recupere le chemin vers la carte
* @return chemin le chemin absolu vers la carte
*/
string CarteArme::getChemin(){
    return chemin;
}

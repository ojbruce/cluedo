#include "Carte.h"

/**
* Constructeur
*/
Carte::Carte(string n, string ch){
    nom = n;
    chemin = ch;

     if(!texture.loadFromFile(chemin)){}
}

Carte::~Carte(){}

/**
 * Recupere le nom de la carte
 * @return nom le nom de la carte
 */
string Carte::getNom(){
    return nom;
}

/**
 * Recupere la texture de la carte
 * @return nom le nom de la carte
 */
sf::Texture& Carte::getTexture(){
    return texture;
}

/**
* Recupere le chemin vers la carte
* @return chemin le chemin absolu vers la carte
*/
string Carte::getChemin(){
    return chemin;
}

/**
 * Operateur d'egalite
 * @param c2 le seconde carte
 **/
bool Carte::operator== (Carte const &c2)
{
  if(nom==c2.nom && chemin==c2.chemin){
    return true;
  }else{
    return false;
  }
}

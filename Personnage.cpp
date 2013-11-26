#include "Personnage.h"

using namespace std;

/**
 * Constructeur
 * @param n un nom
 * @param c la couleur
 * @param pio le chemin du pion
 */
Personnage::Personnage(string n, string c, string pio): nom(n), couleur(c),pion(pio), posDepart(NULL){}

/**
 * Rentre la position de dep
 * @param cas la case de depart
 */
void Personnage::setPositionDepart(Case* cas){
    posDepart = cas;
}

/**
 * Recupere la position de dep
 * @return cas la case de depart
 */
Case* Personnage::getPositionDepart(){
    return posDepart;
}

/**
 * Recupere le nom du personnage
 * @return nom
 */
string Personnage::getNom(){
    return nom;
}

/**
 * Recupere le chemin menant a l'image du pion
 * @return nom
 */
string Personnage::getPion(){
    return pion;
}

/**
 * Recupere la couleur
 * @return couleur
 */
string Personnage::getCouleur(){
    return couleur;
}

/**operateur d'egalite**/
bool Personnage::operator== (Personnage const &p2)
{
  if(nom == p2.nom){
    return true;
  }else{
    return false;
  }
}

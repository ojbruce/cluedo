#include "Joueur.h"


using namespace std;

Joueur::Joueur():  perso_ (NULL), position_(NULL),tabCarteDepart(12),tabCarteVu(24),pion_(NULL){}

Joueur::Joueur(Personnage* perso): perso_(perso), pion_(NULL){
    position_= perso_->getPositionDepart();
}


Joueur::~Joueur()
{

}

/**
 * Ajoute des cartes au tableau de depart du joueur
 * @param c la carte a ajouter
 **/
void Joueur::ajouterCarteDepart(Carte* c){
    tabCarteDepart.push_back(c);

}

/**
 * Ajoute des cartes au tableau de depart du joueur
 * @param c la carte a ajouter
 **/
void Joueur::ajouterCarteVu(Carte* c){
    tabCarteVu.push_back(c);

}

/**
 * Afficher le joueur
 * @param x, y determinant la position
 **/
void Joueur::afficher(int x, int y){

    pion_ = new sf::CircleShape(7);
    pion_->setFillColor(sf::Color::Blue);
    pion_->setPosition(x, y);
}


/**
 * Getter de la position
 * @retrun position_ la posion du joueur
 **/
Personnage* Joueur::getPerso(){
    return perso_;
}

/**
 * Getter de la position
 * @retrun position_ la posion du joueur
 **/
Case* Joueur::getPosition(){
    return position_;
}

/**
 * Getter de la position
 * @param c la posion du joueur
 **/
void Joueur::setPosition(Case* c){
    position_=c;
}

/**
 * Operateur d'egalite
 * @param p2 le second joueur
 **/
bool Joueur::operator== (Joueur const &p2)
{
  if(perso_ == p2.perso_){
    return true;
  }else{
    return false;
  }
}

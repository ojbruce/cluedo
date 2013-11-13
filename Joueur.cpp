#include "Joueur.h"

Joueur::Joueur():  perso_ (NULL), position_(NULL),pion_(NULL){}

Joueur::Joueur(Personnage* perso): perso_(perso), pion_(NULL){
    position_= perso_->getPositionDepart();
}


Joueur::~Joueur()
{

}


Case* Joueur::getPosition(){
    return position_;
}

void Joueur::setPosition(Case* c){
    position_=c;
}

void Joueur::afficher(int x, int y){

    pion_ = new sf::CircleShape(7);
    pion_->setFillColor(sf::Color::Blue);
    pion_->setPosition(x, y);
}

#include "Joueur.h"

Joueur::Joueur(): position_(NULL), pion_(NULL)
{   nom_= "Joueur";}

Joueur::Joueur(Case* pos, string nom): nom_(nom), position_(pos), pion_(NULL)  {}


Joueur::~Joueur()
{
    //dtor
}

void Joueur::setPosition(Case* c){
    position_=c;
}

void Joueur::afficher(int x, int y){

    pion_ = new sf::CircleShape(7);
    pion_->setFillColor(sf::Color::Blue);
    pion_->setPosition(x, y);
}

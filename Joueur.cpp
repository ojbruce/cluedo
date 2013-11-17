#include "Joueur.h"


using namespace std;

Joueur::Joueur():  perso_ (NULL), position_(NULL),tabCarteDepart(12),tabCarteVu(24){}

Joueur::Joueur(Personnage* perso): perso_(perso){
    //La position du joueur
    position_= perso_->getPositionDepart();

    //Les images
	if(!im.loadFromFile(perso_->getPion())){}
    //if(!im.loadFromFile("Images/blanc.png")){}

	im.setSmooth(true);
	joueur.setTexture(im);
}


Joueur::~Joueur()
{

}

void Joueur::update(sf::RenderWindow &window){
    joueur.setPosition(position_->getX()*20+21,position_->getY()*20+21);

    sf::CircleShape shape(7);
    shape.setPosition(position_->getX()*20+21,position_->getY()*20+21);
	window.draw(shape);
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

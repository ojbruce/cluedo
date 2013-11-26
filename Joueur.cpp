#include "Joueur.h"


using namespace std;

Joueur::Joueur():  perso_ (NULL), position_(NULL), dernierePiece_(NULL),tabCarteDepart(12),tabCarteVu(24)
{
    for(int i=1; i<25 ; i++)
    {
        checklist.push_back(false);
    }
}

Joueur::Joueur(Personnage* perso): perso_(perso)
{
    //La position du joueur
    position_= perso_->getPositionDepart();

    //Les images
	if(!im.loadFromFile(perso_->getPion())){}

    for(int i=1; i<25 ; i++)
    {
        checklist.push_back(false);
    }
}


Joueur::~Joueur()
{

}

/**
 * Methode qui update le joueur
 */
void Joueur::update(sf::RenderWindow &window){

	sf::Sprite joueur1;

	joueur1.setTexture(im);
	joueur1.setPosition(position_->getX()*20+21,position_->getY()*20+21);

    window.draw(joueur1);
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
 * Getter des cartes vus
 * @return le tableau de carte
**/
vector<Carte*> Joueur::getCarteDepart(){
    return tabCarteDepart;
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

std::string Joueur::getNom(){
    return perso_->getNom();
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

sf::Texture Joueur::getTexture(){
    return im;
}

/**
 * Fonction setChecklist
 **/
void Joueur::setChecklist(vector<bool> vecteur)
{
    checklist = vecteur;
}

/**
 * Fonction setChecklist
 **/
void Joueur::setChecklistAtTrue(unsigned int i)
{
    checklist[i] = true;
}

/**
 * Fonction getChecklist
 **/
vector<bool> Joueur::getChecklist()
{
    return checklist;
}

/**
*Retourne la dernière pièce
*/
Case* Joueur::getDernierePiece(){
    return dernierePiece_;
}

/**
* Met à jour la derniere piece visite
*/
void Joueur::setDernierePiece(Case* c){
    dernierePiece_=c;
}





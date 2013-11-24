#include "Case.h"
#include "Plateau.h"

using namespace std;

/**
 *Constructeur par defaut
 */
Case::Case() {
    rectangle = new sf::RectangleShape(sf::Vector2f(20, 20));
    estVide = true;
}

/**
 *Constructeur
 */
Case::Case(int a, int b) : x_(b),y_(a){

    rectangle = new sf::RectangleShape(sf::Vector2f(20, 20));
    estVide = true;
}

/**
 *Constructeur de recopie
 */
Case::Case(const Case& c){
	x_= c.x_;   //on peut appeler les attributs des memes classes
	y_ = c.y_;
    estVide = c.estVide;

	rectangle = c.rectangle;
}


/**
 * Destructeur
 */
Case::~Case(){
   delete rectangle;
}

/**
 * Methode qui va réaliser l'action selon la case
 */
std::string Case::action(){
    //on renvoie false c'est qu'il n'a pas gagne
    return "";
}

/**
 * Methode qui trouve tous les chemins possibles
 * @param de le nombre a parcourir
 * @param res le vetor des chemins
 * @param p le plateau
 */
void Case::trouverChemin(int de, vector<Case*> &res, Plateau* p){

    //on verifie si la case est vide
    if(estVide){
        //on insere l'element courant si il n'est pas deja present
        if(std::find(res.begin(), res.end(), this) == res.end())
            res.push_back(this);


        //On va parcourir les cases tant que les des sont supérieurs a zero
        if(de!=0){

            /*
             * Algorithme qui va chercher recursivement les endroits sur lequels le joueur peut se deplacer
             * Passage dans chaque case (haut, bas, gauche droite) en verifiant la presence dans le tableau de valeur
             *
             * Pas de deplacement diagonal.
             */

            /*
             * p->caseValide(x,y) retourne si la position de la case est bien dans le plateau
             */

            // La case du haut
            if(p->caseValide(x_,y_-1)){
                Case* cHaut = p->getCase(x_,y_-1);
                cHaut->trouverChemin(de-1, res,p);

            }

            // La case à gauche
            if(p->caseValide(x_-1,y_)){
                Case* cGauche = p->getCase(x_-1,y_);
                cGauche->trouverChemin(de-1, res,p);
            }

            // La case du bas
            if(p->caseValide(x_,y_+1)){
                Case* cBas = p->getCase(x_,y_+1);
                cBas->trouverChemin(de-1, res,p);
            }

            // La case à droite
            if(p->caseValide(x_+1,y_)){
                Case* cDroite = p->getCase(x_+1,y_);
                cDroite->trouverChemin(de-1, res,p);
            }
        }
    }
}

/**
 * Methode qui affiche la case
 *
 */
void Case::update(sf::RenderWindow &window){
   rectangle->setFillColor(sf::Color(0, 90, 240,150));
   rectangle->setPosition(x_*20+20,y_*20+20);

   window.draw(*rectangle);
}



/**
 * Méthode qui retrourne une string repésentant la case du type: [x][y]
 * @return res l'emplacement de la case
 */
std::string Case::toString(){

	std::string res;

	std::ostringstream oss;
    oss<<".";
	res = oss.str();

	return res;
}

pair<int,int> Case::pointHG(int tailleCase, int ecartX, int ecartY){

    pair<int,int> u;
    u.first = x_*tailleCase+ecartX;
    u.second = y_*tailleCase+ecartY;

    return u;
}

pair<int,int> Case::milieu(int tailleCase, pair<int,int> a){

    pair<int,int> u;
    u.first = a.first+(tailleCase/4);
    u.second = a.second+(tailleCase/4);

    return u;

}



	/********************************************************/
	/**********************Getters***************************/

/**
 * Assesseur de x_
 * @return x_ l'absisse de la case
 */
int Case::getX(){
	return x_;
}

/**
 * Assesseur de y_
 *	@return y_ l'ordonnee de la case
 */
int Case::getY(){
	return y_;
}

/**
 * Assesseur de estVide
 *	@return estVide si la case estvide ou non
 */
int Case::getEstVide(){
    return estVide;
}

/**
 * Modificateur de estVide
 */
void Case::setEstVide(bool b){
    estVide =b;
}

/**
 * Operateur d'egalite
 * @param c2 la seconde case
 **/
bool Case::operator== (Case const &c2)
{
  if(x_==c2.x_ && y_==c2.y_){
    return true;
  }else{
    return false;
  }
}


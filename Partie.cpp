#include "Partie.h"

Partie::Partie(): partieFini_(false){}

Partie::Partie(int nbJ,  Plateau* plat):  partieFini_(false),nbJoueur_(nbJ),p(plat) {
    //initialise le tableau de joueur

    //initialise le tableau des cartes mysteres
}

Partie::~Partie()
{
    //dtor
}

/**
 * Methoque qui prend un nombre aleatoire entre 2 et 12
 * @return rand un random entre 2 et 12
 **/
int Partie::lancerDe(){
	srand(time(NULL)); // place le rand à un endroit diferent selon le time
    return rand() % 11+2;
}

void Partie::lancerTour(Joueur j){

    int de = lancerDe();

    vector<Case*> cheminPosssible; // notre tableau des chemins possibles pour le tour
    Case* posCourante = j.getPosition();    //la position du joueur avant le debut du tour

    //on cherche les positions possibles
    posCourante->trouverChemin(de,cheminPosssible,p);

    //tant que la case n'est pas bonne on recupere la case cliqué
    //si la case est dans cheminPossible on continue sinon on recommence
    //

    //On bouge le joueur
    posCourante->setEstVide(true);
    //pas fini



}


#include "Partie.h"

Partie::Partie(): partieFini_(false){}

Partie::Partie(int nbJ):  partieFini_(false),nbJoueur_(nbJ) {
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


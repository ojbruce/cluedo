#include "DonneesJeu.h"

DonneesJeu::DonneesJeu(Donnees* d ): donnees(d), partieFini_(false), joueurCourant(0), de(0)
{
    //ctor

}

DonneesJeu::~DonneesJeu()
{
    //dtor
}


void DonneesJeu::preparerPartie(Plateau* plateau){

    //Set la position de depart du personnage
    donnees->positionnerPerso(plateau);

    //initialise le tableau de joueur
    tabJoueur_= donnees->initJoueur(nbJoueur_);

    //initialise le tableau des cartes mysteres
    tabMystere_ = donnees->initCarteMystere();

    //distribution des cartes aux joueurs
    donnees->distribuerCarte(tabJoueur_);
}

/**
 * Methoque qui prend un nombre aleatoire entre 2 et 12
 * @return rand un random entre 2 et 12
 **/
int DonneesJeu::lancerDe(){
	srand(time(NULL)); // place le rand à un endroit diferent selon le time
    return rand() % 11+2;
}

bool DonneesJeu::getPartieFini(){
    return partieFini_;
}

void DonneesJeu::setPartieFini(bool parti){
    partieFini_=parti;
}

bool DonneesJeu::getJoueurCourant(){
    return joueurCourant;
}

void DonneesJeu::setJoueurCourant(unsigned int j){
    joueurCourant=j;
}

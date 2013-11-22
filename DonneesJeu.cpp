#include "DonneesJeu.h"

DonneesJeu::DonneesJeu(Donnees* d ): donnees(d), partieFini_(false), gagnant(NULL), joueurCourant(0), de(0), nbJoueur_(2)
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
    cerr<<"DonneesJoueur::initJoueur"<<endl;

    //distribution des cartes aux joueurs
    tabMystere_ =donnees->distribuerCarte(tabJoueur_);
    cerr<<"DonneesJoueur::distribution des cartes"<<endl;
}

void DonneesJeu::accuser(std::string arme, std::string perso,std::string lieu){

    bool bonneCarte;

    for(unsigned int i; i<tabMystere_.size(); i++){
        if(tabMystere_[i]->getNom()!=arme || tabMystere_[i]->getNom()!=perso || tabMystere_[i]->getNom()!=lieu){
            bonneCarte = false;
        }

    }

    if(!bonneCarte){
         tabJoueur_.erase(tabJoueur_.begin() +joueurCourant);
         nbJoueur_--;
    }else{
        gagnant=&tabJoueur_[joueurCourant];
    }
}

void DonneesJeu::soupconner(std::string arme, std::string perso,std::string lieu){

}





/**
 * Methoque qui prend un nombre aleatoire entre 2 et 12
 * @return rand un random entre 2 et 12
 **/
int DonneesJeu::lancerDe(){
	srand(time(NULL)); // place le rand à un endroit diferent selon le time
	de = rand() % 5+2;
    return de;
}

/**
 * Methode qui retourne le de
 * @return le dé
 **/
int DonneesJeu::getDe(){
    return de;
}


/**
 * Methode qui retourne si la partie est finie
 * @return partieFini_ true si fini et false si non fini
 */
bool DonneesJeu::getPartieFini(){
    return partieFini_;
}

/**
 * Methode qui met a jour l'etat de la partie
 * @param parti qui est un boolean true si fini et false si non fini
 */
void DonneesJeu::setPartieFini(bool parti){
    partieFini_=parti;
}

/**
 * Methode qui retourne le joueur courant
 * @return joueurCourant
 */
Joueur* DonneesJeu::getJoueurCourant(){
    return &tabJoueur_[joueurCourant];
}

/**
 * Methode qui retourne le joueur à la position
 * @return joueurCourant
 */
Joueur* DonneesJeu::getJoueurAt(int i){
    return &tabJoueur_[i];
}

/**
 * Methode qui met a jour le joueur Courant
 * @param joueurCourant le joueur corant dans le tabJoueur_
 */
void DonneesJeu::changerJoueur(){
    //on passe au joueur suivant
    if(joueurCourant< tabJoueur_.size()-1)
        joueurCourant++;
    else
        joueurCourant =0;
}

/**
 * Methode qui retourne le joueur gagnant
 * @return gagnant
 */
Joueur* DonneesJeu::getGagnant(){
    return gagnant;
}

/**
 * Methode qui met a jour le joueur gagnant
 * @param joueurCourant le joueur corant dans le tabJoueur_
 */
void DonneesJeu::setGagnant(Joueur* j){
    gagnant=j;
}


/**
 * Methode qui met a jour le nombre de joueur
 * @param joueurCourant le joueur corant dans le tabJoueur_
 */
void DonneesJeu::setNbJoueur(int nb){
    nbJoueur_=nb;
}

/**
 * Methode qui met a jour le joueur gagnant
 * @param joueurCourant le joueur corant dans le tabJoueur_
 */
int DonneesJeu::getNbJoueur(){
    return nbJoueur_;
}

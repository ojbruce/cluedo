#include "Donnees.h"

using namespace std;




Donnees::Donnees()
{
    Lecteur lecteur;
    tabCartes = lecteur.getCartes();
    tabPersonnages = lecteur.getPersonnages();
}


Donnees::~Donnees()
{
    //dtor
}


/**
 *Retourne les cartes mysteres
 *
 */
vector<Carte*> Donnees::initCarteMystere(){
    vector<Carte*> res(3);
    srand(time(NULL)); // place le rand à un endroit diferent selon le time
    //0-8 piece
    int indice = rand() % 9;
    res.push_back(&tabCartes[indice]);

    //9-16 persos
    indice = rand() % 8+9;
    res.push_back(&tabCartes[indice]);

    //17-23 armes
    indice = rand() % 7+17;
    res.push_back(&tabCartes[indice]);

    return res;
}

/**
 * Va renvoyer un n nombre de joueur avec des persos aléatoires
 *
 **/
vector<Carte*> Donnees::initJoueur(int n){

    for(int i=0; i<n; i++){

    }
}


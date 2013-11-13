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
    cerr << "cartepiece" << indice << endl;
    res.push_back(&tabCartes[indice]);

    //9-16 persos
    indice = rand() % 8+9;
    cerr << "carteperso" << indice << endl;
    res.push_back(&tabCartes[indice]);

    //17-23 armes
    indice = rand() % 7+17;
    cerr << "cartearme" << indice << endl;
    res.push_back(&tabCartes[indice]);

    return res;
}

/**
 * Va renvoyer un n nombre de joueur avec des persos aléatoires
 *
 **/
vector<Joueur> Donnees::initJoueur(int n){
    //tableau de joueur à retourner
    vector<Joueur> tabJoueur;
    int i =1;

    srand(time(NULL));




   do{
       //8 perso max
        int indice = rand() % 8;
        Joueur joueur(&tabPersonnages[indice]);

        if(std::find(tabJoueur.begin(), tabJoueur.end(), joueur) != tabJoueur.end()){
            //tabJoueur contient joueur
        }else{
            tabJoueur.push_back(joueur);
            i++;
        }

    } while(i<n);
    return tabJoueur;
}


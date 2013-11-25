#include "Donnees.h"

using namespace std;


Donnees::Donnees(){

    // Ouverture du fichier contenant les donnees du jeu
    ifstream fichier("Donnees/donnees.txt", ios::in);

    if(fichier)
    {
        string ch1, ch2, ch3, ch4, ligne;
        int i;

        // On passe les premieres lignes de commentaires
        getline(fichier, ligne);
        getline(fichier, ligne);
        getline(fichier, ligne);

        // On initialise le tableau contenant les Cartes du jeu
        for(i=1 ; i<25 ; ++i)
        {
            fichier >> ch1 >> ch2;
            Carte carte(ch1,ch2);
            tabCartes.push_back(carte);
         }

         // On passe les lignes de commentaires
         getline(fichier, ligne);
         getline(fichier, ligne);
         getline(fichier, ligne);
         getline(fichier, ligne);

         // On initialise le tableau de Personnages
         for(i=25 ; i<33 ; ++i)
         {
            fichier >> ch1 >> ch2 >> ch3>>ch4;
            Personnage personnage(ch1+" "+ch2,ch3,ch4);
            tabPersonnages.push_back(personnage);
         }


         // On ferme le fichier
        fichier.close();

         cerr << "Donnees:: fin creation" << endl;
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier de donnees." << endl;
    }

}


Donnees::~Donnees()
{
    //dtor
    cerr<<"Donnee::destruction des Donnees"<< endl;
}


Carte* Donnees::getCarte(int ind){
    return &tabCartes[ind];
}

/**
 *Retourne les cartes mysteres
 *
 */
vector<Carte*> Donnees::initCarteMystere(vector<int>& temoin){
    vector<Carte*> res;
    srand(time(NULL)); // place le rand à un endroit diferent selon le time

    //0-8 piece
    int indice = rand() % 9;
    int carte = temoin[indice];
    res.push_back(&tabCartes[carte]);
    temoin.erase(temoin.begin() +indice);

    //9-16 persos
    indice = rand() % 8+9 -1;
    carte = temoin[indice];
    res.push_back(&tabCartes[carte]);
    temoin.erase(temoin.begin() +indice);

    //17-23 armes
    indice = rand() % 7+17 -2;
    carte = temoin[indice];
    res.push_back(&tabCartes[carte]);
    temoin.erase(temoin.begin() +indice);

    return res;
}

/**
 * Va renvoyer un n nombre de joueur avec des persos aléatoires
 *
 **/
vector<Joueur> Donnees::initJoueur(int n){
    //tableau de joueur à retourner
    vector<Joueur> tabJoueur;
    int i =0;


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

void Donnees::positionnerPerso(Plateau* p){

    tabPersonnages[0].setPositionDepart(p->getCase(14,0));
    tabPersonnages[1].setPositionDepart(p->getCase(16,24));
    tabPersonnages[2].setPositionDepart(p->getCase(0,17));
    tabPersonnages[3].setPositionDepart(p->getCase(23,6));
    tabPersonnages[4].setPositionDepart(p->getCase(23,19));
    tabPersonnages[5].setPositionDepart(p->getCase(0,7));
    tabPersonnages[6].setPositionDepart(p->getCase(7,24));
    tabPersonnages[7].setPositionDepart(p->getCase(9,0));

}


/**
 * Methodes qui va distribuer les cartes aux joueurs
 *
 **/
vector<Carte*> Donnees::distribuerCarte(vector<Joueur> &lesJoueurs){

    srand(time(NULL));

    vector<int> temoin; //tableau d'int

    for(int i =0; i<24; i++){
        temoin.push_back(i);
    }

    vector<Carte*> res;
    res=initCarteMystere(temoin);

    cerr<<"Donnees::init CarteMystere"<<endl;

    //On initialise une taille et un indice
    int taille = 21;
    int indice;
    int carte;
    unsigned int j =0;

    //Tant qu'il y a des cartes on ajoute
    do{
        indice= rand() % taille;
        carte = temoin[indice];

        Joueur& joueur =lesJoueurs.at(j);

        joueur.ajouterCarteDepart(&tabCartes.at(carte));
        joueur.ajouterCarteVu(&tabCartes.at(carte));

        temoin.erase(temoin.begin() +indice);

        j++;
        taille--;

        if(j == lesJoueurs.size())
            j = 0;

    }while(!temoin.empty());

    return res;
}


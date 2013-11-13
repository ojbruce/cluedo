#include "Donnees.h"

using namespace std;


Donnees::Donnees(Plateau* p){

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

        //position des persos
        tabPersonnages[0].setPositionDepart(p->getCase(14,0));
        tabPersonnages[1].setPositionDepart(p->getCase(16,24));
        tabPersonnages[2].setPositionDepart(p->getCase(0,17));
        tabPersonnages[3].setPositionDepart(p->getCase(23,6));
        tabPersonnages[4].setPositionDepart(p->getCase(23,19));
        tabPersonnages[5].setPositionDepart(p->getCase(0,7));
        tabPersonnages[6].setPositionDepart(p->getCase(7,24));
        tabPersonnages[7].setPositionDepart(p->getCase(9,0));


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
vector<Joueur> Donnees::initJoueur(int n){
    //tableau de joueur à retourner
    vector<Joueur> tabJoueur;
    int i =0;

    cerr << "Donnees::initJoueur" << endl;
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

/**
 * Methodes qui va distribuer les cartes aux joueurs
 *
 **/
void Donnees::distribuerCarte(vector<Joueur> lesJoueurs){

    srand(time(NULL));

    //tableau d'int
    vector<int> temoin;

    for(int i =0; i<24; i++){
        temoin.push_back(i);
    }

    //On initialise une taille et un indice
    int taille = 24;
    int indice;
    unsigned int j =0;

    //Tant qu'il y a des cartes on ajoute
    do{
        indice= rand() % taille;
        lesJoueurs.at(j).ajouterCarteDepart(&tabCartes.at(indice));
        lesJoueurs.at(j).ajouterCarteVu(&tabCartes.at(indice));

        temoin.erase(temoin.begin() +indice);
        j++;
        taille--;

        if(j == lesJoueurs.size())
            j = 0;

    }while(!temoin.empty());


}

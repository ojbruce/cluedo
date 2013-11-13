#include "Donnees.h"

using namespace std;


Donnees::Donnees(Plateau* p)
{
    /*Lecteur lecteur;
    tabCartes = lecteur.getCartes();
    tabPersonnages = lecteur.getPersonnages(p);*/

    // Ouverture du fichier contenant les donnees du jeu
    ifstream fichier("donnees.txt", ios::in);

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


    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier de donnees." << endl;
    }

    //position des persos
    tabPersonnages[0]=


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


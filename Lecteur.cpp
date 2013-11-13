#include "Lecteur.h"

using namespace std;

Lecteur::Lecteur()
{
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
}

Lecteur::~Lecteur()
{
    //dtor
}

std::vector<Carte> Lecteur::getCartes()
{
    return tabCartes;
}

std::vector<Personnage> Lecteur::getPersonnages()
{
    return tabPersonnages;
}

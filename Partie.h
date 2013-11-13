#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"
#include "Donnees.h"


class Partie
{
    public:
        //Partie();
        Partie(int nbJ, Plateau* plat);
        ~Partie();

        void lancerTour(Joueur j); // Va lancer le tour dans une partie
        void lancerPartie(); // Va lancer le tour dans une partie


    private:
        //Attributs
        Donnees donnees;                //la classe contenant les donnees

        bool partieFini_;               //Determine si la partie est finie
        int nbJoueur_;                  //Le nombre de joueur
        vector<Carte*> tabMystere_;     //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;     //Le tableau contenant les joueurs

        Plateau* p;         //Le plateau de jeu

        //Methodes
        int lancerDe();     //lancer De
        void positionnerJoueur();
};

#endif // PARTIE_H

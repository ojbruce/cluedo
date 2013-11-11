#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Joueur.h"
#include "Carte.h"


class Partie
{
    public:
        Partie();
        Partie(int nbJ);
        ~Partie();

        int lancerDe();
        void lancerTour(Joueur j){
        }


    private:
        bool partieFini_;    //Determine si la partie est finie
        int nbJoueur_;       //Le nombre de joueur
        Carte* tabMystere_[3];   //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;


};

#endif // PARTIE_H

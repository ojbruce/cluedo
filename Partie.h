#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"


class Partie
{
    public:
        Partie();
        Partie(int nbJ, Plateau* plat);
        ~Partie();

        int lancerDe();
        void lancerTour(Joueur j);


    private:
        bool partieFini_;    //Determine si la partie est finie
        int nbJoueur_;       //Le nombre de joueur
        vector<Carte*> tabMystere_;   //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;

        Plateau* p;


};

#endif // PARTIE_H

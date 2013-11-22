#ifndef DONNEESJEU_H
#define DONNEESJEU_H

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"
#include "Donnees.h"

class DonneesJeu
{
    public:
        DonneesJeu(Donnees* d);
        virtual ~DonneesJeu();

        int lancerDe();     //lancer le De

        void preparerPartie(Plateau* plateau);


    private:
        //Attributs
        Donnees* donnees;                //la classe contenant les donnees

        bool partieFini_;               //Determine si la partie est finie
        //A rajouter gagnant
        unsigned int joueurCourant;     //Le joueur courant
        int de;                         // ?

        unsigned int nbJoueur_;         //Le nombre de joueur
        vector<Carte*> tabMystere_;     //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;     //Le tableau contenant les joueurs


};

#endif // DONNEESJEU_H
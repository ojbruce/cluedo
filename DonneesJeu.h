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
        void changerJoueur();


        void accuser(std::string arme, std::string perso,std::string lieu);
        void soupconner(std::string arme, std::string perso,std::string lieu);




        //Getter- Setter
        bool getPartieFini();
        void setPartieFini(bool parti);
        Joueur* getJoueurCourant();
        Joueur* getJoueurAt(int i);

        int getDe();

        Joueur* getGagnant();
        void setGagnant(Joueur* j);

        void setNbJoueur(int nb);
        int getNbJoueur();


    private:
        //Attributs
        Donnees* donnees;                //la classe contenant les donnees

        bool partieFini_;               //Determine si la partie est finie
        Joueur* gagnant;                //Le joueur gagnant

        unsigned int joueurCourant;     //Le joueur courant
        int de;                         // ?

        unsigned int nbJoueur_;         //Le nombre de joueur
        vector<Carte*> tabMystere_;     //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;     //Le tableau contenant les joueurs


};

#endif // DONNEESJEU_H

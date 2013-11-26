#ifndef DONNEESJEU_H
#define DONNEESJEU_H

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"
#include "Donnees.h"


/**
 * DonneesJeu est la classe représentant les donnees avant le debut du jeu.
 *
 * Une DonneesJeu est caractérisé par les informations suivantes :
 * des donnees
 * un pointeur vers joueur gagnant nul au depart
 * un tableau de carte* mysteres
 * un booleen disant si la partie est fini
 * un joueurCourant
 * un nombre de joueur
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class DonneesJeu
{
    public:
        DonneesJeu(Donnees* d);
        virtual ~DonneesJeu();

        int lancerDe();                         //Methode qui retourne le de
        void preparerPartie(Plateau* plateau);  //Methode qui va preparer la partie
        void changerJoueur();                   //Methode qui met a jour le joueur Courant


        void accuser(std::string arme, std::string perso,std::string lieu);
        std::string soupconner(std::string arme, std::string perso,std::string lieu);

        //Getter- Setter
        bool getPartieFini();           //Methode qui retourne si la partie est finie
        void setPartieFini(bool parti); //Methode qui met a jour l'etat de la partie
        Joueur* getJoueurCourant();     //Methode qui retourne le joueur courant
        Joueur* getJoueurAt(int i);     //Methode qui retourne le joueur à la position

        int getDe();

        Joueur* getGagnant();           //Methode qui retourne le joueur gagnant
        void setGagnant(Joueur* j);     //Methode qui met a jour le joueur gagnant

        void setNbJoueur(int nb);       //Methode qui met a jour le nombre de joueur
        int getNbJoueur();              //Methode qui get le nombre de joueur


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

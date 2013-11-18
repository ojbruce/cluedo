#ifndef DONNEES_H
#define DONNEES_H


#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Carte.h"
#include "Personnage.h"
#include "Joueur.h"
#include "Plateau.h"

class Donnees
{
	public:

        // Initialiser les donnees
         Donnees(Plateau* p);
        ~Donnees();

        Carte* getCarte(int indice); // Getter d'une carte du tableau de Carte
        //Personnage getPersonnage(std::string nom);   // Getter d'un personnage du tableau de Personnage

        vector<Carte*> initCarteMystere();                  //va renvoyer les 3 cartes
        vector<Joueur> initJoueur(int n);                   //va renvoyer un n nombre de joueur avec des persos aléatoires
        void distribuerCarte(vector<Joueur> lesJoueurs);    //va distribuer les cartes aux joueurs


    private:

        //Attributs
        std::vector<Carte> tabCartes;           // Vecteur contenant les 24 cartes du jeu
        std::vector<Personnage> tabPersonnages; // Vecteur contenant les 8 personnages

};

#endif

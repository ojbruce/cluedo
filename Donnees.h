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
#include "FactoryCarte.h"

/**
 * Donnees est la classe représentant les donnees avant le debut du jeu.
 *
 * Une Donnees est caractérisé par les informations suivantes :
 * un tableau de cartes distribuer
 * un tableau de personnage preexistant
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Donnees
{
	public:


         Donnees(); // Constructeur
        ~Donnees(); //  Destructeur

        unsigned int trouverIndiceCarte(std::string carte);

        vector<Carte*> initCarteMystere(vector<int> &vec);              // va renvoyer les 3 cartes
        vector<Joueur> initJoueur(int n);                               // va renvoyer un n nombre de joueur avec des persos aléatoires
        void positionnerPerso(Plateau* p);                              // va positionner des persos
        vector<Carte*> distribuerCarte(vector<Joueur> &lesJoueurs);     // va distribuer les cartes aux joueurs


    private:

        //Attributs
        std::vector<Carte*> tabCartes;              // Vecteur contenant les 24 cartes du jeu
        std::vector<Personnage> tabPersonnages;     // Vecteur contenant les 8 personnages

};

#endif

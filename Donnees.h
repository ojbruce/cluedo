#ifndef DONNEES_H
#define DONNEES_H

#include<string>
#include<vector>

#include "Lecteur.h"
#include "Carte.h"
#include "Personnage.h"

class Donnees
{
	public:

        // Initialiser les donnees
         Donnees();
        ~Donnees();

        //Carte getCarte(int indice); // Getter d'une carte du tableau de Carte
        //Personnage getPersonnage(std::string nom);   // Getter d'un personnage du tableau de Personnage

        vector<Carte*> initCarteMystere();      //va renvoyer les 3 cartes
        vector<Carte*> initJoueur(int n);      //va renvoyer un n nombre de joueur avec des persos aléatoires

    private:

        //Attributs
        std::vector<Carte> tabCartes;   // Vecteur contenant les 24 cartes du jeu
        std::vector<Personnage> tabPersonnages; // Vecteur contenant les 8 personnages





};

#endif

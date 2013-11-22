#ifndef PARTIE_H
#define PARTIE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"
#include "Donnees.h"
#include "DonneesJeu.h"
#include "ZoneAffichageTexte.h"
#include "ZoneCarte.h"


class Partie
{
    public:
        //Partie();
        Partie( Plateau* plat, ZoneAffichageTexte* zoneT, ZoneCarte* zoneC, DonneesJeu* d);
        ~Partie();


        void update(sf::RenderWindow &window);
        void afficher(sf::RenderWindow &window);



    private:
        //Attributs
        DonneesJeu* donnees;

        bool deClique_;                 // Determine si le joueur a lancer le de ou pas

        int de;
        vector<Case*> chemin;           //Le tableau de chemin

        Plateau* p;                     //Le plateau de jeu
        ZoneAffichageTexte* zoneText;   //La zone de texte
        ZoneCarte* zoneCarte;           //La zone des cartes

        sf::Text* texte;
        sf::Font font;


};

#endif // PARTIE_H

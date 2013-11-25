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
#include "ZoneChecklist.h"
#include "Observer.h"
#include "ManagerFenetre.h"


class Partie: public Observer
{
    public:
        //Partie();
        Partie( Plateau* plat, ZoneAffichageTexte* zoneT, ZoneCarte* zoneC,ZoneChecklist* z, DonneesJeu* d);
        ~Partie();

        void preparer();
        void update(sf::Event event);
        void afficher(sf::RenderWindow &window);

        virtual void estNotifie(std::string choix1, std::string choix2, std::string act);



    private:
        //Attributs
        DonneesJeu* donnees;

        bool deClique_;                 // Determine si le joueur a lancer le de ou pas

        int de;
        vector<Case*> chemin;           //Le tableau de chemin

        Plateau* p;                     //Le plateau de jeu
        ZoneAffichageTexte* zoneText;   //La zone de texte
        ZoneCarte* zoneCarte;           //La zone des cartes
        ZoneChecklist* zoneChecklist;   //Le zone de la checklist

        sf::Font font;

        std::string armeCrime;
        std::string persoCrime;
		std::string action;

		ManagerFenetre manFen;


};

#endif // PARTIE_H

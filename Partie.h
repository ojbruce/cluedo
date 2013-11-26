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

/**
 * Partie est la classe représentant les cases d'une piece.
 *
 * Une Piece est caractérisé par les informations suivantes :
 * un accès au données
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Partie: public Observer
{
    public:
        //Partie();
        Partie( Plateau* plat, ZoneAffichageTexte* zoneT, ZoneCarte* zoneC,ZoneChecklist* z, DonneesJeu* d);
        ~Partie();

        void preparer(); //prepare la partie en fonction des donnees
        void update(sf::Event event);//Fonction d'update
        void afficher(sf::RenderWindow &window);//Fonction d'affichage

        virtual void estNotifie(std::string choix1, std::string choix2, std::string act);



    private:
        //Attributs
        DonneesJeu* donnees;            //Les donnees du jeu

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

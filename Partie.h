#ifndef PARTIE_H
#define PARTIE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <cstdlib> //pour le random
#include "time.h"

#include "Joueur.h"
#include "Carte.h"
#include "Plateau.h"
#include "Donnees.h"
#include "ZoneAffichageTexte.h"


class Partie
{
    public:
        //Partie();
        Partie(int nbJ, Plateau* plat, ZoneAffichageTexte* zone1);
        ~Partie();

        void update(sf::RenderWindow &window);
        void afficher(sf::RenderWindow &window);


    private:
        //Attributs
        Donnees donnees;                //la classe contenant les donnees

        bool partieFini_;               //Determine si la partie est finie
        bool deClique_;                 // Determine si le joueur a lancer le de ou pas
        int joueurCourant;              //Le joueur courant

        unsigned int nbJoueur_;         //Le nombre de joueur
        vector<Carte*> tabMystere_;     //Les 3 cartes désignant le lieu, le crimier, l'arme
        vector <Joueur> tabJoueur_;     //Le tableau contenant les joueurs
        vector<Case*> chemin;           //Le tableau de chemin

        Plateau* p;                     //Le plateau de jeu
        ZoneAffichageTexte* zoneText;   //La zone de texte

        sf::Text* texte;
        sf::Font font;

        //Methodes
        int lancerDe();     //lancer De

};

#endif // PARTIE_H

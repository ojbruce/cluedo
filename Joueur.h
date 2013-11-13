#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include"Case.h"
#include"Carte.h"
#include"Personnage.h"

using namespace sf;
using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(Personnage* p);
        bool operator== (Joueur const &p2);

        Case* getPosition();  // Retourne la positon du joueur
        void setPosition(Case* c);  //met la position du joueur à jour

        //A voir ajouter la dernier piece visitee

        void afficher(int x, int y);
        virtual ~Joueur();

    private:

        Personnage* perso_;  // Le personnage qu'incarne le joueur
        Case* position_;    //La position du joueur

        vector<Carte*> tabCarteDepart[12];  //tab des cartes de depart max 12
        vector<Carte*> tabCarteVu[24];      //tab des cartes vus pendant le jeu max 24


        //Le pion du joueur
        static const int taillePion_=8;
        sf::CircleShape *pion_;


};

#endif // JOUEUR_H

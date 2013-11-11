#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include"Case.h"
#include"Carte.h"

using namespace sf;
using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(Case* c, string nom);

        void setPosition(Case* c);  //met la position du joueur à jour

        //A voir ajouter la dernier piece visitee

        void afficher(int x, int y);
        virtual ~Joueur();

    private:
        string nom_;
        Case* position_; //La position du joueur

        Carte* tabCarteDepart[12]; //tab des cartes de depart max 12


        //Le pion du joueur
        static const int taillePion_=8;
        sf::CircleShape *pion_;


};

#endif // JOUEUR_H

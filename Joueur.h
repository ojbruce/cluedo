#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include"Case.h"


using namespace sf;
using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(Case* c, string nom);

        void setPosition(Case* c);

        void afficher(int x, int y);

        virtual ~Joueur();

    private:
        string nom_;
        Case* position_;

        //Le pion du joueur
        static const int taillePion_=8;
        sf::CircleShape *pion_;


};

#endif // JOUEUR_H

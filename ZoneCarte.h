#ifndef ZONECARTE_H
#define ZONECARTE_H

#include <SFML/Graphics.hpp>
#include <vector>


#include "Joueur.h"


class ZoneCarte
{
    public:
        ZoneCarte();
        virtual ~ZoneCarte();

        void afficherCarte(Joueur j, sf::RenderWindow &window);

    private:
        int limY_; //La limite vers le bas en y

        sf::Texture texture;

};

#endif // ZONECARTE_H

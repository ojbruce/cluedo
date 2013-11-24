#ifndef ECRAN_H
#define ECRAN_H

#include <SFML/Graphics.hpp>

class Ecran
{
    public:
        virtual void update(sf::RenderWindow &window, sf::Event event)=0;
        //virtual void afficher(sf::RenderWindow &fenetre)=0;
};

#endif // ECRAN_H

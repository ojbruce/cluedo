#ifndef ECRAN_H
#define ECRAN_H

#include <SFML/Graphics.hpp>

class Ecran
{
    public:

        virtual void afficher(sf::RenderWindow &fenetre)=0;
        virtual void update(sf::Event event)=0;
};

#endif // ECRAN_H

#ifndef ECRAN_H
#define ECRAN_H

#include <SFML/Graphics.hpp>

class Ecran
{
    public:
        virtual void update(sf::RenderWindow &window)=0;
};

#endif // ECRAN_H

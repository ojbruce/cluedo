#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>

class Fenetre
{
    public:

      virtual void update(sf::Event event, sf::RenderWindow &fenetre)=0;
      virtual void afficher(sf::RenderWindow &fenetre)=0;
};

#endif

#ifndef ECRAN_H
#define ECRAN_H

#include <SFML/Graphics.hpp>

/**
 * Ecran est la classe abstraite représentant les ecrans.
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Ecran
{
    public:

        virtual void afficher(sf::RenderWindow &fenetre)=0;
        virtual void update(sf::Event event)=0;
};

#endif // ECRAN_H

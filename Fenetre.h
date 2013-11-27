#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>

/**
 * Fenetre est la classe abstraite représentant les cases du plateau.
 *
 * Elle est caractérisé par les informations suivantes :
 * une methode qui update la fenetre
 * une methode qui affiche la fenetre
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Fenetre
{
    public:

      virtual void update(sf::Event event, sf::RenderWindow &fenetre)=0;
      virtual void afficher(sf::RenderWindow &fenetre)=0;
};

#endif

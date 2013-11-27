#ifndef ZONEAFFICHAGETEXTE_H
#define ZONEAFFICHAGETEXTE_H

#include <SFML/Graphics.hpp>
#include <iostream>


/**
 * ZoneAffichageTexte est la classe représentant la partie affichant le deroulement du jeu
 *
 * Classe non fonctionnel : probleme sfml sf::text
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class ZoneAffichageTexte
{
    public:
        ZoneAffichageTexte();
        virtual ~ZoneAffichageTexte();

        void afficher(sf::RenderWindow &window);

    private:
        int limY_; //La limitemax vers le bas en y
        int debX;   //Le debut de la zone en820
        int finX;   //La fin de la zone en x 1296
        int posCouranteX;

        sf::Font font;

        sf::Texture texture;
        sf::Sprite sp;
};

#endif // ZONEAFFICHAGETEXTE_H

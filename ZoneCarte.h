#ifndef ZONECARTE_H
#define ZONECARTE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Joueur.h"

/**
 * ZoneCarte est la classe représentant la partie affichant les cartes en dessous du plateau.
 *
 * Une zoneCarte est caractérisé par les informations suivantes :
 * la texture par défaut.
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class ZoneCarte
{
    public:
        ZoneCarte();    //Constructeur

        void afficherCarte(Joueur j, sf::RenderWindow &window); //Methode qui affiche les cartes d'un joueur

    private:
        int limY_;              //La limite vers le bas en y

        sf::Texture texture;    //La texture de la carte par defaut

};

#endif // ZONECARTE_H

#ifndef DEF_CARTEPIECE
#define DEF_CARTEPIECE

#include <SFML/Graphics.hpp>
#include<string>

#include "Carte.h"

using namespace std;

/**
 * Carte est la classe représentant les cartes pieces.
 *
 * Une Carte est caractérisé par les informations suivantes :
 * un nom
 * un chemin
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class CartePiece : public Carte
{
    public:
        CartePiece(string nom, string chemin);   // Constructeur

        // Getter
        string getNom();        //retourne le nom
        string getChemin();     //retourne le chemin

        sf::Texture& getTexture();

    private:

        string nom;
        string chemin;
        sf::Texture texture;
};

#endif

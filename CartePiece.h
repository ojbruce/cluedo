#ifndef DEF_CARTEPIECE
#define DEF_CARTEPIECE

#include <SFML/Graphics.hpp>
#include<string>

#include "Carte.h"

using namespace std;


class CartePiece : public Carte
{
    public:
        CartePiece(string nom, string chemin);   // Constructeur
        ~CartePiece();                  //Destructeur

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

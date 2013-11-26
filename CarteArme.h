#ifndef DEF_CARTEARME
#define DEF_CARTEARME

#include <SFML/Graphics.hpp>
#include<string>
#include "Carte.h"

using namespace std;

class CarteArme : public Carte
{
    public:
        CarteArme(string nom, string chemin);   // Constructeur
        ~CarteArme();                  //Destructeur

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

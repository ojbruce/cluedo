#ifndef DEF_CARTEARME
#define DEF_CARTEARME

#include <SFML/Graphics.hpp>
#include<string>
#include "Carte.h"


class CarteArme : public Carte
{
    public:
        CarteArme(string nom, string chemin);   // Constructeur

        // Getter
        std::string getNom();           //Methode qui retourne le nom
        std::string getChemin();        //Methode qui retourne le chemin

        sf::Texture& getTexture();      //Methode qui retourne la texture

    private:

        std::string nom;                 //le nom
        std::string chemin;              //le chemin
        sf::Texture texture;             //la texture
};

#endif

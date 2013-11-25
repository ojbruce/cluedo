#ifndef DEF_BOUTON
#define DEF_BOUTON

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Bouton
{
    public:

        Bouton(std::string imageDep, std::string imageClique);
        sf::Sprite getSprite();
        bool getClique();
        void clique();
        void deselection();
        void selection();

    private :

        sf::Texture imageDepart;    // Chemin de l'image du bouton initial
        sf::Texture imageClique;    // Chemin de l'image du bouton clique
        sf::Sprite cadreDepart;
        sf::Sprite cadreClique;
        bool enfonce;           // Booleen indiquant si le bouton est enfonce

};

#endif

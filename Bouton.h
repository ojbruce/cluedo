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

        Bouton(std::string imageDep, std::string imageClique);  //Constructeur par defaut de bouton

        void clique();                  //Methode qui va cliquer le bouton
        void deselection();             //Methode qui va deselectionner le bouton
        void selection();               //Methode qui va selectionner le bouton

        //Getter-Setter
        sf::Sprite getSprite();         //Methode qui recupere le sprite du bouton
        bool getClique();               //Methode qui recupere le bouton clique


    private :

        sf::Texture imageDepart;        // La texture de l'image du bouton initial
        sf::Texture imageClique;        // La texture de l'image du bouton clique
        sf::Sprite cadreDepart;         // Le sprite de l'image de depart
        sf::Sprite cadreClique;         // Le sprite de l'image clique
        bool enfonce;                   // Booleen indiquant si le bouton est enfonce

};

#endif

#ifndef DEF_CARTEARME
#define DEF_CARTEARME

#include <SFML/Graphics.hpp>
#include<string>
#include "Carte.h"


/**
 * Carte est la classe représentant les cartes armes.
 *
 * Une Carte est caractérisé par les informations suivantes :
 * un nom
 * un chemin
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
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

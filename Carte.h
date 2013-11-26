#ifndef DEF_CARTE
#define DEF_CARTE

#include <SFML/Graphics.hpp>
#include<string>

using namespace std;

/**
 * Carte est la classe représentant les cartes.
 *
 * Une Carte est caractérisé par les informations suivantes :
 * un nom
 * un chemin
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Carte
{
    public:

        // Getter
        virtual string getNom()=0;        //retourne le nom
        virtual string getChemin()=0;     //retourne le chemin

        virtual sf::Texture& getTexture()=0;

};

#endif

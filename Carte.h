#ifndef DEF_CARTE
#define DEF_CARTE

#include <SFML/Graphics.hpp>
#include<string>

using namespace std;

class Carte
{
    public:

        // Getter
        virtual string getNom()=0;        //retourne le nom
        virtual string getChemin()=0;     //retourne le chemin

        virtual sf::Texture& getTexture()=0;

};

#endif

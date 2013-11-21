#ifndef DEF_CARTE
#define DEF_CARTE

#include <SFML/Graphics.hpp>
#include<string>

using namespace std;

class Carte
{
    public:
        Carte(string nom, string chemin);   // Constructeur
        virtual ~Carte();                  //Destructeur

        bool operator== (Carte const &c2); // Operateur d'egalite
        //bool operator== (std::string const &c2); // Operateur d'egalite


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

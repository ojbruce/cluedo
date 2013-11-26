#include "ZoneCarte.h"

/**
 * Constructeur
 *
 */
ZoneCarte::ZoneCarte(): limY_(550)
{
    //ctor
    if(!texture.loadFromFile("Images/carteVide.png")){}
}

/**
 * Methode qui affiche les cartes d'un joueur
 *@param window la fenetre de rendu
 */
void ZoneCarte::afficherCarte(Joueur j, sf::RenderWindow &window){

    vector<Carte*> vec = j.getCarteDepart();
    int posx=0;

    sf::Sprite sp;

    for(unsigned int j=0; j < vec.size(); j++){


        sp.setTexture(vec.at(j)->getTexture());
        sp.setPosition(posx,limY_);

        window.draw(sp);

        posx+=108;

    }

    if(posx < 1296){
    	//on met la texture par defaut carte vide
        sp.setTexture(texture);

        for(unsigned int j=0; j < 12-vec.size(); j++){

            sp.setPosition(posx,limY_);
            window.draw(sp);

            posx+=108;

        }
    }

}

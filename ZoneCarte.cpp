#include "ZoneCarte.h"

ZoneCarte::ZoneCarte(): limY_(550)
{
    //ctor
    if(!texture.loadFromFile("Images/carteVide.png")){}
}

ZoneCarte::~ZoneCarte()
{
    //dtor
}

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

    if(posx != 1296){

        for(unsigned int j=0; j < vec.size(); j++){

            sp.setTexture(texture);
            sp.setPosition(posx,limY_);

            window.draw(sp);

            posx+=108;

        }
    }

}

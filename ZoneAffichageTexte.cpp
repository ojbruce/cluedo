#include "ZoneAffichageTexte.h"

ZoneAffichageTexte::ZoneAffichageTexte(): limY_(550),debX(820),finX(1296),posCouranteX(0){}

ZoneAffichageTexte::~ZoneAffichageTexte()
{
    if (!font.loadFromFile("arial.ttf")){ }
}


void ZoneAffichageTexte::afficher(sf::RenderWindow &window){
    std::string msg = "Lol";

    sf::Text* text = new sf::Text(msg, font);
    text->setPosition(debX,220);
    text->setCharacterSize(11);

    window.draw(*text);

    posCouranteX+=12;

}

#include "ZoneAffichageTexte.h"


using namespace std;

ZoneAffichageTexte::ZoneAffichageTexte(): limY_(550),debX(820),finX(1296),posCouranteX(0){}

ZoneAffichageTexte::~ZoneAffichageTexte()
{
    if (!font.loadFromFile("arial.ttf")){ }
}


void ZoneAffichageTexte::afficher(sf::RenderWindow &window){

    sf::Text* texto = new sf::Text("MMMMM", font);

    texto->setCharacterSize(11);
    texto->setPosition(debX,posCouranteX);

    window.draw(*texto);

    //posCouranteX+=12;

}

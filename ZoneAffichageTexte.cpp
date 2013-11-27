#include "ZoneAffichageTexte.h"


using namespace std;

ZoneAffichageTexte::ZoneAffichageTexte(): limY_(550),debX(820),finX(1296),posCouranteX(0){}

ZoneAffichageTexte::~ZoneAffichageTexte()
{
    if (!font.loadFromFile("arial.ttf")){ }
    if (!texture.loadFromFile("Images/lancerDe.png")){ }

}


/**
 * Methode qui affiche le texte
 * @param fenetre la fenetre de rendu
 */
void ZoneAffichageTexte::afficher(sf::RenderWindow &window){
    sp.setTexture(texture);
    sp.setPosition(820,0);

    window.draw(sp);
}

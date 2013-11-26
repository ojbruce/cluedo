#include "ZoneAffichageTexte.h"


using namespace std;

ZoneAffichageTexte::ZoneAffichageTexte(): limY_(550),debX(820),finX(1296),posCouranteX(0),texto("MMMMM", font){}

ZoneAffichageTexte::~ZoneAffichageTexte()
{
    if (!font.loadFromFile("arial.ttf")){ }


}


/**
 * Methode qui affiche le texte
 * @param fenetre la fenetre de rendu
 */
void ZoneAffichageTexte::afficher(sf::RenderWindow &window){

}

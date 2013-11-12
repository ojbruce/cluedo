#include "EcranAccueil.h"

EcranAccueil::EcranAccueil()
{
    //ctor
    imFond.loadFromFile("accueil.png");
	imFond.setSmooth(true);

	butJouer.loadFromFile("jouerBut.png");

	accueil.setTexture(imFond);

}

EcranAccueil::~EcranAccueil()
{
    //dtor
}

void EcranAccueil::update(sf::RenderWindow &window,sf::Event event){
    window.draw(accueil);

}

#include "EcranAccueil.h"

EcranAccueil::EcranAccueil()
{
    //ctor
    imFond.loadFromFile("Images/accueil.png");
	imFond.setSmooth(true);


	accueil.setTexture(imFond);

}

EcranAccueil::~EcranAccueil()
{
    //dtor
}

void EcranAccueil::update(sf::RenderWindow &window,sf::Event event){
    window.draw(accueil);
}

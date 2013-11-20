#include "ManagerEcran.h"

ManagerEcran::ManagerEcran()
{
    //ctor
    ecranJeu = new EcranJeu();
    ecranAccueil = new EcranAccueil();

    ecranCourant = ecranJeu;
}

ManagerEcran::~ManagerEcran()
{
    //dtor

}
void ManagerEcran::update(sf::RenderWindow &window, sf::Event event){
    ecranCourant->update(window, event);
}

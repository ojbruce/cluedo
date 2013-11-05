#include "ManagerEcran.h"

ManagerEcran::ManagerEcran()
{
    //ctor
    ecranJeu = new EcranJeu();
    ecranAccueil = new EcranAccueil();

    ecranCourant = ecranAccueil;
}

ManagerEcran::~ManagerEcran()
{
    //dtor

}
void ManagerEcran::update(sf::RenderWindow &window){
    ecranCourant->update(window);
}

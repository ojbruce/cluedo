#include "ManagerEcran.h"

ManagerEcran::ManagerEcran(Donnees &d)
{
    //ctor
    ecranJeu = new EcranJeu(d);
    ecranAccueil = new EcranAccueil();

    ecranCourant = ecranJeu;
    cerr<<"ManEcran::Crea "<<endl;
}

ManagerEcran::~ManagerEcran()
{
    //dtor

}
void ManagerEcran::update(sf::RenderWindow &window, sf::Event event){
    ecranCourant->update(window, event);
}

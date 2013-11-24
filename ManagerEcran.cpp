#include "ManagerEcran.h"



ManagerEcran::ManagerEcran(DonneesJeu* d)
{
      ecranAccueil = new EcranAccueil(this);
      ecranRegles = new EcranRegles(this);
      ecranConfiguration = new EcranConfiguration(this);
      ecranJeu = new EcranJeu(this, d);

      ecranCourant = ecranAccueil;
   }

ManagerEcran::~ManagerEcran()
{
    //dtor

}
void ManagerEcran::update(sf::RenderWindow &window, sf::Event event){
    //ecranCourant->update(window, event);
    ecranCourant->afficher(window);
    ecranCourant->update( event);
}

/**
* Fonction afficher
*/

void ManagerEcran::afficher(sf::RenderWindow &fenetre)
{
    ecranCourant->afficher(fenetre);
}

/**
*  getEcranConfiguration
*/

Ecran* ManagerEcran::getEcranConfiguration()
{
    return ecranConfiguration;
}


/**
*  getEcranRegles
*/

Ecran* ManagerEcran::getEcranRegles()
{
    return ecranRegles;
}


/**
*  getEcranJeu
*/

Ecran* ManagerEcran::getEcranJeu()
{
    return ecranJeu;
}


/**
*  setEcranConfiguration
*/

void ManagerEcran::setEcranCourant(Ecran *ecran)
{
    ecranCourant = ecran;
}


/**
*  setNombreJoueur
*/

void ManagerEcran::setNombreJoueur(int nb)
{
    nombreJoueur = nb;
    cerr << nb << endl;
}

#include "ManagerEcran.h"


/**
* Constructeur
*/
ManagerEcran::ManagerEcran(DonneesJeu* d):donnees(d)
{
    ecranAccueil = new EcranAccueil(this);
    ecranRegles = new EcranRegles(this);
    ecranConfiguration = new EcranConfiguration(this);
    ecranFinal = new EcranFinal(this, d);
    ecranEpilogue = new EcranEpilogue(this);
    ecranJeu = new EcranJeu(this, d);

    ecranCourant = ecranAccueil;
}


/**
* Destructeur
*/
ManagerEcran::~ManagerEcran()
{
    //dtor
}


/**
* Fonction update
*/
void ManagerEcran::update(sf::Event event)
{
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
*  getEcranFinal
*/
Ecran* ManagerEcran::getEcranFinal()
{
    return ecranFinal;
}


/**
*  getEcranEpilogue
*/
Ecran* ManagerEcran::getEcranEpilogue()
{
    return ecranEpilogue;
}


/**
*  setEcranCourant
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
    donnees->setNbJoueur(nb);

    cerr << nb << endl;
    cerr << "setdansdonnee" << endl;
}

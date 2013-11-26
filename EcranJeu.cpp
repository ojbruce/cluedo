#include "EcranJeu.h"
#include "ManagerEcran.h"
/**
 * Constructeur
 */
EcranJeu::EcranJeu(ManagerEcran *man,DonneesJeu* d1): d(d1),part(&p, &zoneText, &zoneCarte, &zoneCheck, d), partLancer(false),manager(man)
{
    //ctor

    cerr<<"EcranJeu::Crea "<<endl;
}


/**
 * Cette fonction lance l'affichage de la fênetre
 * @param window la fenetre
 */
void EcranJeu::afficher(sf::RenderWindow &window){

    if(!partLancer)
    {
        part.preparer();
        partLancer=true;
    }
    else
    {
        p.afficher(window);
        part.afficher(window);
    }
}


/**
 * Cette fonction maj les elements de l'ecran jeu
 * @param event un evenement envoyé par les classes superieurs
 */
void EcranJeu::update(sf::Event event)
{
    part.update(event);

    if(d->getGagnant()!=NULL)
        manager->setEcranCourant(manager->getEcranFinal());
}




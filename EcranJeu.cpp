#include "EcranJeu.h"
#include "ManagerEcran.h"

EcranJeu::EcranJeu(ManagerEcran *man,DonneesJeu* d1): d(d1),part(&p, &zoneText, &zoneCarte, &zoneCheck, d), partLancer(false),manager(man)
{
    //ctor

    cerr<<"EcranJeu::Crea "<<endl;
}


EcranJeu::~EcranJeu()
{
    //dtor

}


/**
 * Fonction afficher
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
 * Fonction update
 */
void EcranJeu::update(sf::Event event)
{
    part.update(event);

    if(d->getGagnant()!=NULL)
        manager->setEcranCourant(manager->getEcranFinal());
}


/**
 *  Fonction update
 */
void EcranJeu::update(sf::RenderWindow &window, sf::Event event){

    while (window.pollEvent(event))
    {
        //Gere la fermeture de la fenetre
        if (event.type == sf::Event::Closed)
            window.close();
        //si on recoit un evenement souris pressee
        if (event.type == sf::Event::MouseButtonPressed){
            //on retroune la position de la souris et on affiche un pion à la position
            //part.update(window);
            part.update(event);

        }
    }

    //on maj l'affichage du plateau
    //p.afficher(window);
    //part.afficher(window);

}

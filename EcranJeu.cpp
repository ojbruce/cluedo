#include "EcranJeu.h"

EcranJeu::EcranJeu(): part(2,&p, &zoneText)
{
    //ctor
}

EcranJeu::~EcranJeu()
{
    //dtor
}


/**
 *
 *
 */
void EcranJeu::update(sf::RenderWindow &window, sf::Event event){
   // plateau.afficher();

    while (window.pollEvent(event))
    {
        //Gere la fermeture de la fenetre
        if (event.type == sf::Event::Closed)
            window.close();
        //si on recoit un evenement souris pressee
        if (event.type == sf::Event::MouseButtonPressed){
            //on retroune la position de la souris et on affiche un pion à la position
            part.update(window);
        }
    }

    //on maj l'affichage du plateau
    p.afficher(window);
    part.afficher(window);



}

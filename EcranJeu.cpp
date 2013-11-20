#include "EcranJeu.h"

EcranJeu::EcranJeu(Donnees &d): part(3,&p, &zoneText, &zoneCarte, d)
{
    //ctor
    cerr<<"EcranJeu::Crea "<<endl;
}

EcranJeu::~EcranJeu()
{
    //dtor
}


/**
 *  Methode qui update l'ecran et l'affiche
 *
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
            part.update(window);

        }
    }

    //on maj l'affichage du plateau
    p.afficher(window);
    part.afficher(window);



}

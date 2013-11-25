#include "EcranConfiguration.h"
#include "ManagerEcran.h"

#include <iostream>

using namespace std;


/**
* Constructeur
*/
EcranConfiguration::EcranConfiguration(ManagerEcran *man) :
    jouer(Bouton("Images/jouerDepart.png", "Images/jouerClique.png")),
    nb2(Bouton("Images/2Depart.png", "Images/2Clique.png")),
    nb3(Bouton("Images/3Depart.png", "Images/3Clique.png")),
    nb4(Bouton("Images/4Depart.png", "Images/4Clique.png")),
    nb5(Bouton("Images/5Depart.png", "Images/5Clique.png")),
    nb6(Bouton("Images/6Depart.png", "Images/6Clique.png")),
    nb7(Bouton("Images/7Depart.png", "Images/7Clique.png")),
    nb8(Bouton("Images/8Depart.png", "Images/8Clique.png")),
    manager(man)
{
    // On charge l'image dans la texture "image"
    image.loadFromFile("Images/configuration.png");

    // On met la texture dans le sprite ecran
    ecran.setTexture(image);
}


/**
* Fonction afficher
*/

void EcranConfiguration::afficher(sf::RenderWindow &fenetre)
{

    sf::Event event;
    while (fenetre.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            fenetre.close();

    }

    // Affichage des elements
    fenetre.draw(ecran);

    sf::Sprite sp;

    sp = jouer.getSprite();
    sp.move(sf::Vector2f(595, 550));
    fenetre.draw(sp);

    sp = nb2.getSprite();
    sp.move(sf::Vector2f(200, 360));
    fenetre.draw(sp);

    sp = nb3.getSprite();
    sp.move(sf::Vector2f(340, 360));
    fenetre.draw(sp);

    sp = nb4.getSprite();
    sp.move(sf::Vector2f(480, 360));
    fenetre.draw(sp);

    sp = nb5.getSprite();
    sp.move(sf::Vector2f(620, 360));
    fenetre.draw(sp);

    sp = nb6.getSprite();
    sp.move(sf::Vector2f(760, 360));
    fenetre.draw(sp);

    sp = nb7.getSprite();
    sp.move(sf::Vector2f(900, 360));
    fenetre.draw(sp);

    sp = nb8.getSprite();
    sp.move(sf::Vector2f(1040, 360));
    fenetre.draw(sp);

    //Affichage des changements
    fenetre.display();

}

/** 
* Fonction update
*/
void EcranConfiguration::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if(595<=x && x<=673 && 550<=y && y<=630)
    {
        if( selectionValide()==true )
        {
            jouer.clique();
            manager->setEcranCourant(manager->getEcranJeu());
        }
    }

    if(200<=x && x<=256 && 360<=y && y<=423)
    {
        changement(nb2,nb8,nb3,nb4,nb5,nb6,nb7,2);
    }

    if(340<=x && x<=403 && 360<=y && y<=423)
    {
        changement(nb3,nb2,nb8,nb4,nb5,nb6,nb7,3);
    }

    if(480<=x && x<=543 && 360<=y && y<=423)
    {
        changement(nb4,nb2,nb3,nb8,nb5,nb6,nb7,4);
    }

    if(620<=x && x<=683 && 360<=y && y<=423)
    {
        changement(nb5,nb2,nb3,nb4,nb8,nb6,nb7,5);
    }

    if(760<=x && x<=823 && 360<=y && y<=423)
    {
        changement(nb6,nb2,nb3,nb4,nb5,nb8,nb7,6);
    }

    if(900<=x && x<=963 && 360<=y && y<=423)
    {
        changement(nb7,nb2,nb3,nb4,nb5,nb6,nb8,7);
    }

    if(1040<=x && x<=1103 && 360<=y && y<=423)
    {
        changement(nb8,nb2,nb3,nb4,nb5,nb6,nb7,8);
    }

}

/** 
* Fonction changement
*/
void EcranConfiguration::changement(Bouton &b1,Bouton &b2,Bouton &b3,Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7, int nombre){

    b1.clique();
    b2.deselection();
    b3.deselection();
    b4.deselection();
    b5.deselection();
    b6.deselection();
    b7.deselection();
    manager->setNombreJoueur(nombre);
}


/**
* Fonction selectionValide
* Role : cette fonction renvoie vrai si un seul bouton selectionant le nombre de joueurs est clique
*/

bool EcranConfiguration::selectionValide()
{
    bool res;

    if(nb2.getClique()==true || nb3.getClique()==true || nb4.getClique()==true ||
        nb5.getClique()==true || nb6.getClique()==true || nb7.getClique()==true ||
        nb8.getClique()==true ){
        res = true;
    }else{
        res = false;
    }

    return res;
}

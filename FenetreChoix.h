#ifndef DEF_FENETRECHOIX
#define DEF_FENETRECHOIX

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include "Ecran.h"
#include "ManagerFenetre.h"
#include "Bouton.h"
#include "Observer.h"
#include "Observable.h"


/**
 * FenetreContrer est la classe représentant l'ecran montrant le contre.
 *
 * Il est observer par patie et le notifie lorsque les boutons sont selectionné
 *
 * Il est caractérisé par les informations suivantes :
 * des boutons
 * des observateurs
 * un manager permettant de changer d'ecran
 *
 *Herite de observable et de fenetre
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class FenetreChoix : public Observable, public Fenetre
{
    public:

        FenetreChoix(ManagerFenetre *manager);

        void afficher(sf::RenderWindow &fenetre);                   // Cette fonction lance l'affichage de la fenetre
        void update(sf::Event event, sf::RenderWindow &fenetre);    // Cette fonction permet le changement d'ecran en fonction des evenements
        void cliqueConditionnel1(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7, Bouton &b8);
        void cliqueConditionnel2(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7);
        void actualiserChoix();         //Actualise le choix
        void deselectionnerTout();      //Deselectionne tous les boutons
        void setACliqueFalse();         //Met a cliquer à false

        void ajouterObs(Observer* obs); //ajouter un observateu
        void enleverObs(Observer* obs); //enlever un observateur
        void notifyObs();               //notifier observateur



    private :
        //Les images
        sf::Texture image;
        sf::Sprite fond;

        //Les boutons
        Bouton accuser;
        Bouton soupcon;

        Bouton c1;
        Bouton c2;
        Bouton c3;
        Bouton c4;
        Bouton c5;
        Bouton c6;
        Bouton c7;
        Bouton c8;
        Bouton c9;
        Bouton c10;
        Bouton c11;
        Bouton c12;
        Bouton c13;
        Bouton c14;
        Bouton c15;

        ManagerFenetre *manager;            //les manager

        vector <Observer*> observateurs;    //Les observateurs

        std::string carte1;                 //La carte choisie 1
        std::string carte2;                 //La carte choisie 2
        std::string action;                 //La carte l'action choisi

        bool aClique;                       //Le bouton clique ou pas
};
#endif

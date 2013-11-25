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


class FenetreChoix : public Observable, public Fenetre
{
    public:

        FenetreChoix(ManagerFenetre *manager);

        void afficher(sf::RenderWindow &fenetre);    // Cette fonction lance l'affichage de la fenetre
        void update(sf::Event event, sf::RenderWindow &fenetre);                // Cette fonction permet le changement d'ecran en fonction des evenements
        void cliqueConditionnel1(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7, Bouton &b8);
        void cliqueConditionnel2(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7);
        void actualiserChoix();
        void deselectionnerTout();
        void setACliqueFalse();

        void ajouterObs(Observer* obs);
        void enleverObs(Observer* obs);
        void notifyObs();



    private :

        sf::Texture image;
        sf::Sprite fond;

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

        ManagerFenetre *manager;
        
        vector <Observer*> observateurs;
        
        std::string carte1;
        std::string carte2;
        std::string action;
        
        bool aClique;
};
#endif

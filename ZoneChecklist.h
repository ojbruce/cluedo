#ifndef ZONECHECKLIST_H
#define ZONECHECKLIST_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Bouton.h"
#include "Joueur.h"


class ZoneChecklist
{
    public:

        ZoneChecklist();
        virtual ~ZoneChecklist();

        void afficherChecklist(Joueur* j, sf::RenderWindow &window);
        void update(Joueur* j, sf::Event event);
        void placerCaseCocher(Bouton b,int y, sf::RenderWindow &fenetre);
        void actualiserChecklist(Joueur* j);
        void cliqueConditionnel(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton & b);
        void importation(Bouton& b, int i, vector<bool> vec);

    private:

        sf::Texture imageCheck;               
        sf::Sprite zoneCheck; 

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
        Bouton c16;
        Bouton c17;
        Bouton c18;
        Bouton c19;
        Bouton c20;
        Bouton c21;
        Bouton c22;
        Bouton c23;
        Bouton c24;

};

#endif // ZONECHECKLIST_H

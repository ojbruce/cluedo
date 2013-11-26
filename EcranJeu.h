#ifndef ECRANJEU_H
#define ECRANJEU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ecran.h"
#include "Plateau.h"
#include "Partie.h"
#include "ZoneAffichageTexte.h"

class ManagerEcran;

class EcranJeu : public Ecran
{
    public:
        EcranJeu(ManagerEcran *manager,DonneesJeu* d);

        void afficher(sf::RenderWindow &fenetre);   // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);               //Cette fonction maj les elements de l'ecran jeu

    private:
        DonneesJeu* d;
        Plateau p;                      //Le plateau

        ZoneAffichageTexte zoneText;    //La zone des textes
        ZoneCarte zoneCarte;            //La zone des cartes
        ZoneChecklist zoneCheck;		//La zone de la checklist

        Partie part;                    //La partie
        bool partLancer;

        ManagerEcran* manager;

};

#endif // ECRANJEU_H

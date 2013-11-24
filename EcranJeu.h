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
        virtual ~EcranJeu();
        void creerPartie();

        void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);

        void update(sf::RenderWindow &window, sf::Event event);

    protected:
    private:
        DonneesJeu* d;
        Plateau p;                      //Le plateau
        ZoneAffichageTexte zoneText;    //La zone des textes
        ZoneCarte zoneCarte;            //La zone des cartes

        Partie part;                    //La partie
        bool partLancer;


};

#endif // ECRANJEU_H

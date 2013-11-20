#ifndef ECRANJEU_H
#define ECRANJEU_H

#include <SFML/Graphics.hpp>
#include "Ecran.h"
#include "Plateau.h"
#include "Partie.h"
#include "ZoneAffichageTexte.h"

class EcranJeu : public Ecran
{
    public:
        EcranJeu(Donnees &d);
        virtual ~EcranJeu();

        void update(sf::RenderWindow &window, sf::Event event);

    protected:
    private:
        Plateau p;                      //Le plateau
        ZoneAffichageTexte zoneText;    //La zone des textes
        ZoneCarte zoneCarte;            //La zone des cartes

        Partie part;                    //La partie

};

#endif // ECRANJEU_H

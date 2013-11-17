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
        EcranJeu();
        virtual ~EcranJeu();

        void update(sf::RenderWindow &window, sf::Event event);

    protected:
    private:
        Plateau p;
        ZoneAffichageTexte zoneText;
        Partie part;

};

#endif // ECRANJEU_H

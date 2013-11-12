#ifndef ECRANJEU_H
#define ECRANJEU_H

#include <SFML/Graphics.hpp>
#include "Ecran.h"
#include "Plateau.h"

class EcranJeu : public Ecran
{
    public:
        EcranJeu();
        virtual ~EcranJeu();

        void update(sf::RenderWindow &window, sf::Event event);

    protected:
    private:
        Plateau p;
};

#endif // ECRANJEU_H

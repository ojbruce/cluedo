#ifndef ECRANACCUEIL_H
#define ECRANACCUEIL_H

#include "Ecran.h"


class EcranAccueil : public Ecran
{
    public:
        EcranAccueil();
        void update(sf::RenderWindow &window, sf::Event event);
        virtual ~EcranAccueil();

    protected:
    private:

        //Image du plateau
		sf::Texture imFond;
		sf::Texture butJouer;
		sf::Sprite accueil;

};

#endif // ECRANACCUEIL_H

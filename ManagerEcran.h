#ifndef MANAGERECRAN_H
#define MANAGERECRAN_H

#include "Ecran.h"
#include "EcranJeu.h"
#include "EcranAccueil.h"

class ManagerEcran
{
    public:
        ManagerEcran(Donnees d);
        virtual ~ManagerEcran();

        void update(sf::RenderWindow &window, sf::Event event);

    protected:
    private:

        Ecran* ecranCourant;
        EcranJeu* ecranJeu;
        EcranAccueil* ecranAccueil;


};

#endif // MANAGERECRAN_H

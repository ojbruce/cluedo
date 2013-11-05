#ifndef MANAGERECRAN_H
#define MANAGERECRAN_H

#include "Ecran.h"
#include "EcranJeu.h"
#include "EcranAccueil.h"

class ManagerEcran
{
    public:
        ManagerEcran();
        virtual ~ManagerEcran();

        void update(sf::RenderWindow &window);

    protected:
    private:

        Ecran* ecranCourant;
        EcranJeu* ecranJeu;
        EcranAccueil* ecranAccueil;


};

#endif // MANAGERECRAN_H

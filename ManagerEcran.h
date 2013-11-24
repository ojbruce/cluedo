#ifndef MANAGERECRAN_H
#define MANAGERECRAN_H


#include "Ecran.h"

#include "EcranAccueil.h"
#include "EcranJeu.h"
#include "EcranRegles.h"
#include "EcranConfiguration.h"


class ManagerEcran
{
    public:
        ManagerEcran(DonneesJeu* d);
        virtual ~ManagerEcran();

        void update(sf::RenderWindow &window, sf::Event event);

        void update(sf::Event event);
        void afficher(sf::RenderWindow &fenetre);

        //Getter-Setter
        Ecran* getEcranConfiguration();
        Ecran* getEcranRegles();
        Ecran* getEcranJeu();
        void setEcranCourant(Ecran *ecran);
        void setNombreJoueur(int nb);


    private:

        Ecran* ecranCourant;

        Ecran* ecranAccueil;
        Ecran* ecranRegles;
        Ecran* ecranConfiguration;
        Ecran* ecranJeu;

        int nombreJoueur;


};

#endif // MANAGERECRAN_H

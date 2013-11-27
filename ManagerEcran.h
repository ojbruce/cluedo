#ifndef MANAGERECRAN_H
#define MANAGERECRAN_H


#include "Ecran.h"

#include "EcranAccueil.h"
#include "EcranJeu.h"
#include "EcranRegles.h"
#include "EcranConfiguration.h"
#include "EcranFinal.h"
#include "EcranEpilogue.h"


/**
 * ManagerEcran est la classe représentant les transitions entre les fenetres.
 *
 * Elle est caractérisé par les informations suivantes :
 * elles instancie toutes ces ecrans concrets heritant de fenetre
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class ManagerEcran
{
    public:

        ManagerEcran(DonneesJeu* d);
        virtual ~ManagerEcran();

        //void update(sf::RenderWindow &window, sf::Event event);

        void update(sf::Event event);
        void afficher(sf::RenderWindow &fenetre);

        //Getter-Setter
        Ecran* getEcranConfiguration();
        Ecran* getEcranRegles();
        Ecran* getEcranJeu();
        Ecran* getEcranFinal();
        Ecran* getEcranEpilogue();

        void setEcranCourant(Ecran *ecran);
        void setNombreJoueur(int nb);


    private:

        DonneesJeu* donnees;

        Ecran* ecranCourant;        //l'ecran courant
        Ecran* ecranAccueil;        //l'ecran d'accueil du jeu
        Ecran* ecranRegles;         //l'ecran de regles
        Ecran* ecranConfiguration;  //l'ecran de configuration pour creer avec un nombre de joueur
        Ecran* ecranJeu;            //l'ecran de jeu avec la partie
        Ecran* ecranFinal;          //l'ecran final
        Ecran* ecranEpilogue;       //l'ecran d'epilogue

        int nombreJoueur;           //le nombre de joueur


};

#endif // MANAGERECRAN_H

#ifndef DEF_ECRANFINAL
#define DEF_ECRANFINAL

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"
#include "DonneesJeu.h"

class ManagerEcran;

/**
 * EcranFinal est la classe représentant l'ecran qui s'affiche lorsqu'un joueur à gagner.
 *
 * Il est caractérisé par les informations suivantes :
 * deux boutons
 * une image
 * un manager permettant de changer d'ecran
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class EcranFinal : public Ecran
{
	public:

        EcranFinal(ManagerEcran *manager, DonneesJeu* d);

        void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);                 // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

        sf::Texture image;  // Texture de l'ecran final
        sf::Sprite ecran;   // Sprite de l'ecran final
        Bouton ok;

        ManagerEcran *manager;  //Le manager qui cree l'ecran
        DonneesJeu* donnees;    //Les donnees du jeu

};
#endif

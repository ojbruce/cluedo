#ifndef DEF_ECRANFINAL
#define DEF_ECRANFINAL

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"
#include "DonneesJeu.h"

class ManagerEcran;

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

        ManagerEcran *manager;
        DonneesJeu* donnees;

};
#endif

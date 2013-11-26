#ifndef DEF_ECRANEPILOGUE
#define DEF_ECRANEPILOGUE

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "Ecran.h"
#include "Bouton.h"

class ManagerEcran;

class EcranEpilogue : public Ecran
{
	public:

        EcranEpilogue (ManagerEcran *manager);

        void afficher(sf::RenderWindow &fenetre);     // Cette fonction lance l'affichage de la fênetre
        void update(sf::Event event);                 // Cette fonction permet le changement d'ecran en fonction des evenements

   private :

        sf::Texture image;  // Texture de l'ecran final
        sf::Sprite ecran;   // Sprite de l'ecran final

        Bouton fermer;

        ManagerEcran *manager;

};
#endif

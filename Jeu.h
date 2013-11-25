#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>

#include "ManagerEcran.h"
#include "Donnees.h"
#include "DonneesJeu.h"

using namespace std;


class Jeu
{
    public:

        Jeu();
        virtual ~Jeu();

        void lancerJeu();


    private:
        Donnees donnees;            //Les donnees du jeu
        DonneesJeu donneesJeu;      //Les donnees de la partie
        ManagerEcran manEcran;      //Le manager d'ecran

};

#endif // JEU_H

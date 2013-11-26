#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>

#include "ManagerEcran.h"
#include "Donnees.h"
#include "DonneesJeu.h"
#include <mutex>

using namespace std;


class Jeu
{
    public:

        void lancerJeu();
        static Jeu* getInstance();


    private:
        Donnees donnees;            //Les donnees du jeu
        DonneesJeu donneesJeu;      //Les donnees de la partie
        ManagerEcran manEcran;      //Le manager d'ecran

        static Jeu* jeu;
        Jeu();
        static mutex mu;
};

#endif // JEU_H

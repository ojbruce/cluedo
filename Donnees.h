#ifndef DONNEES_H
#define DONNEES_H

#include<string>
#include "Carte.h"
#include "Personnage.h"

using namespace std;

class Donnees
{
	public:

        // Initialiser les donnees
        Donnees();

        Carte getCarte(int indice); // Getter d'une carte du tableau de Carte
        Personnage getPersonnage(string nom);   // Getter d'un personnage du tableau de Personnage

    private:

        //Attributs
        Carte tableauCartes[24];
        Personnage tableauPersonnages[8];

        //Methodes
        initT


};

#endif

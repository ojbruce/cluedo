#ifndef DONNEES_H
#define DONNEES_H

#include<string>
#include<vector>

#include "Carte.h"
#include "Personnage.h"

using namespace std;

class Donnees
{
	public:

        // Initialiser les donnees
        Donnees();
        ~Donnees();

        Carte getCarte(int indice); // Getter d'une carte du tableau de Carte
        Personnage getPersonnage(string nom);   // Getter d'un personnage du tableau de Personnage

        //vector<Carte*> initCarteMystere();      //va renvoyer les 3 cartes

    private:

        //Attributs
        //Carte tabCartes[24];
        //Personnage tabPerso[8];




        //Methodes
        //void initTabCarte();
        //void initTabPerso();


};

#endif

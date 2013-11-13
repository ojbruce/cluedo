#ifndef LECTEUR_H
#define LECTEUR_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Personnage.h"
#include "Carte.h"

class Lecteur
{
    public:
        Lecteur();    // Initialise les vecteurs tabCartes et tabPersonnages a partir du fichier de donnees
        virtual ~Lecteur();

        std::vector<Carte> getCartes(); // Methode qui retourne le vecteur de Cartes
        std::vector<Personnage> getPersonnages();   // Methode qui retourne le vecteur de Personnage

    protected:
    private:
        std::vector<Carte> tabCartes;
        std::vector<Personnage> tabPersonnages;
};

#endif // LECTEUR_H

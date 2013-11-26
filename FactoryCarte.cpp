#include "FactoryCarte.h"


/**
* Fonction creer
*/
Carte* FactoryCarte::creer(string type, string nom, string chemin)
{
    Carte* carte=NULL;

    if(type=="piece")
    {
        carte = new CartePiece(nom,chemin);
    }
    else if(type=="personnage")
    {
        carte = new CartePersonnage(nom,chemin);
    }
    else if(type=="arme")
    {
        carte = new CarteArme(nom,chemin);
    }

    return carte;
}


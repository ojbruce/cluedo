#include "FactoryCarte.h"


/**
 * Methode qui va creer les cartes selon leur le type
 * @return retourne une carte
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


#include "Personnage.h"


Personnage::Personnage(){}

Personnage::Personnage(string n, string c): nom(n), couleur(c), posDepart(NULL){}

Personnage::~Personnage()
{
    delete posDepart;
}

Case* Personnage::getPositionDepart(){
    return posDepart;
}

string Personnage::getNom(){
    return nom;
}
string Personnage::getCouleur(){
    return couleur;
}

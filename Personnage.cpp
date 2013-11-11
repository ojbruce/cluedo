#include "Personnage.h"


Personnage::Personnage(){}

Personnage::Personnage(string n, string c, Case* pos): nom(n), couleur(c), posDepart(pos){}

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


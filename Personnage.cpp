#include "Personnage.h"


Personnage::Personnage(){}

Personnage::Personnage(string n, string c, string pio): nom(n), couleur(c),pion(pio), posDepart(NULL){}

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

bool Personnage::operator== (Personnage const &p2)
{
  if(nom == p2.nom){
    return true;
  }else{
    return false;
  }
}

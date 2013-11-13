#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include<string>

#include "Case.h"

using namespace std;

class Personnage
{
    public:
        Personnage();
        Personnage(string nom, string couleur,string pion); //Constructeur
        bool operator== (Personnage const &p2);
        virtual ~Personnage();  //destructeur

        //Getters
        Case* getPositionDepart();  //Recupere la position de depart
        string getNom();            //Recupere le nom
        string getCouleur();        //Recupere la couleur
        string getPion();


    private:
        string nom;     // le nom du personnage
        string couleur; // la couleur du personnage
        string pion;         // Chemin menant a l'image du pion du personnage

        Case* posDepart;    //la position de depart
};



#endif // PERSONNAGE_H

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include<string>

#include "Case.h"




/**
 * Personnage est la classe représentant les cases d'une piece.
 *
 * Un Personnage est caractérisé par les informations suivantes :
 * un nom
 * un chemin vers l'image
 * une position de depart case*
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Personnage
{
    public:

        Personnage(std::string nom, std::string couleur,std::string pion); //Constructeur
        bool operator== (Personnage const &p2);             //Operateur egalite

        //Setters
        void setPositionDepart(Case* cas);

        //Getters
        Case* getPositionDepart();  //Recupere la position de depart
        std::string getNom();            //Recupere le nom
        std::string getCouleur();        //Recupere la couleur
        std::string getPion();           //Recupere le chemin vers le pion


    private:
        std::string nom;     // le nom du personnage
        std::string couleur; // la couleur du personnage
        std::string pion;    // Chemin menant a l'image du pion du personnage

        Case* posDepart;    //la position de depart
};



#endif // PERSONNAGE_H

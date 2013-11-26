#ifndef PIECE_H
#define PIECE_H

#include <iostream>

//Pour l'heritage
#include "Case.h"

class Porte;

using namespace std;

/**
 * Piece est la classe représentant les cases d'une piece.
 *
 * Une Piece est caractérisé par les informations suivantes :
 * un nom
 * un pointeur vers la porte de la case (pas pris en charge)
 *
 * Herite de Case.
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Piece : public Case{

	public:
		Piece(std::string n); //Constructeur de porte par defaut: appel case
		Piece(int a, int b, std::string n); //Constructeur de piece avec coordonnee : appel case

        virtual std::string action();   //Methode qui renvoie un nom par polymorphisme
        virtual string toString();      //Affichage pour les erreurs
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p); // methode qui trouve tous les chemins possibles

        void setPorte(Porte* p); //set de la porte

   protected:
        string nom_;                //Le nom de la piece
        Porte* porte;               //Un pointeur vers une porte
};

#endif // PIECE_H

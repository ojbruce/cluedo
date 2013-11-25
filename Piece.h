#ifndef PIECE_H
#define PIECE_H

#include <iostream>

//Pour l'heritage
#include "Case.h"

using namespace std;

class Piece : public Case{

	public:
		Piece(std::string n);
		Piece(int a, int b, std::string n);

        virtual std::string action();
        virtual string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);

   protected:
        string nom_;                //Le nom de la piece
        //Porte* p;
};

#endif // PIECE_H

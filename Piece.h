#ifndef PIECE_H
#define PIECE_H

#include <iostream>

//Pour l'heritage
#include "Case.h"

using namespace std;

class Piece : public Case{

	public:
		Piece();
		Piece(int a, int b);

        virtual std::string action();
        virtual string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);

   private:

};

#endif // PIECE_H

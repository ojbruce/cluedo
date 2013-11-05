#ifndef PORTE_H
#define PORTE_H

#include <vector>

//Pour l'heritage
#include "Case.h"
#include "Piece.h"

using namespace std;

class Porte : public Piece
{
    public:
        Porte(string nom);                //Constructeur de porte par defaut: appel case
        Porte(string nom, int a, int b);    //Constructeur de porte avec coordonnee : appel case

        Porte(const Porte& p, int a, int b); //Construction d'une porte avec une autre porte=meme piece

        void ajouterPiece(Piece* p);

        virtual string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);

        string getNom() const;
        virtual ~Porte();

    protected:
    private:
        //Un ensemble de case pièce
        vector <Piece*> tabPiece_;
        string nom_;
};

#endif // PORTE_H

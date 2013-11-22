#ifndef PORTE_H
#define PORTE_H

#include <vector>
#include <iostream>
#include <cstdlib>

//Pour l'heritage
#include "Case.h"
#include "Piece.h"



class Porte : public Piece
{
    public:
        Porte(string nom, Case* c=NULL);                //Constructeur de porte par defaut: appel case
        Porte(string nom, int a, int b, Case* c=NULL);    //Constructeur de porte avec coordonnee : appel case

        Porte(const Porte& p, int a, int b, Case* c=NULL); //Construction d'une porte avec une autre porte=meme piece

        void ajouterPiece(Piece* p);
        void setCheminSecret(Case* c);


        virtual string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);
        virtual string action();

        string getNom() const;
        virtual ~Porte();

    protected:
    private:

        vector <Piece*> tabPiece_;  //Un ensemble de case pièce
        string nom_;                //Le nom de la piece

        //Certaines pieces ont un passage secret
        Case* cheminSecret;
        sf::Text porte;
};

#endif // PORTE_H

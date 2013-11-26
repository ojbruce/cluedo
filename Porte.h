#ifndef PORTE_H
#define PORTE_H

#include <vector>
#include <iostream>
#include <cstdlib>

//Pour l'heritage
#include "Case.h"
#include "Piece.h"

/**
 * Porte est la classe représentant l'entree d'une piece et donne accès à toute les cases pièces.
 *
 * Une Porte est caractérisé par les informations suivantes :
 * un tableau de piece
 * un pointeur vers case pour un chemin secret
 *
 * Herite de Piece.
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Porte : public Piece
{
    public:
        Porte(string nom, Case* c=NULL);                    //Constructeur de porte par defaut: appel case
        Porte(string nom, int a, int b, Case* c=NULL);      //Constructeur de porte avec coordonnee : appel case

        Porte(const Porte& p, int a, int b);                //Construction d'une porte avec une autre porte=meme piece
        virtual ~Porte();

        void ajouterPiece(Piece* p);                        //Ajoute une piece au tableau de piece
        void setCheminSecret(Case* c);                      //Entre un chemin secret


        virtual string toString();                          //Affichage d'erreur
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p); // methode qui trouve tous les chemins possibles
        virtual string action();                           //Methode qui renvoie un nom par polymorphisme

        string getNom() const;       //Retourne le nom de la porte


    private:

        vector <Piece*> tabPiece_;  //Un ensemble de case pièce
        Case* cheminSecret;         //Certaines pieces ont un passage secret
};

#endif // PORTE_H

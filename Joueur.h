#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include"Case.h"
#include"Carte.h"
#include"Personnage.h"



class Joueur
{
    public:
        Joueur();                           //Constructeur par defaut
        Joueur(Personnage* p);              //Constructeur avec un personnage prédéfini
        bool operator== (Joueur const &p2); // Operateur d'egalite

        Case* getPosition();                // Retourne la positon du joueur
        void setPosition(Case* c);          //met la position du joueur à jour

        /*A voir ajouter la dernier piece visitee*/

        void ajouterCarteDepart(Carte* c);  //Ajoute les cartes de depart du joueur
        void ajouterCarteVu(Carte* c);      //Ajoute les cartes vu par le joueur

        void afficher(int x, int y);
        virtual ~Joueur();

    private:

        Personnage* perso_; // Le personnage qu'incarne le joueur
        Case* position_;    //La position du joueur

        vector<Carte*> tabCarteDepart;  //tab des cartes de depart max 12
        vector<Carte*> tabCarteVu;      //tab des cartes vus pendant le jeu max 24


        //Le pion du joueur
        static const int taillePion_=8;
        sf::CircleShape *pion_;


};

#endif // JOUEUR_H

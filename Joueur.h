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
        virtual ~Joueur();

        void ajouterCarteDepart(Carte* c);  //Ajoute les cartes de depart du joueur
        void ajouterCarteVu(Carte* c);      //Ajoute les cartes vu par le joueur

        //Affiche le joueur
        void update(sf::RenderWindow &App);

        //Getter- Setter
        vector<Carte*> getCarteVu();        //Retourne le tableau de carte
        Personnage* getPerso();             //Retourne le perso
        Case* getPosition();                // Retourne la positon du joueur
        void setPosition(Case* c);          //met la position du joueur à jour


    private:

        Personnage* perso_;             // Le personnage qu'incarne le joueur
        Case* position_;                //La position du joueur

        vector<Carte*> tabCarteDepart;  //tab des cartes de depart max 12
        vector<Carte*> tabCarteVu;      //tab des cartes vus pendant le jeu max 24

        sf::Texture im;




};

#endif // JOUEUR_H

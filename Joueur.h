#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include"Case.h"
#include"Carte.h"
#include"Personnage.h"


/**
 * Joueur est la classe représentant le joueur
 *
 * Une Joueur est caractérisé par les informations suivantes :
 * un perso
 * une position
 * une dernierPiece visitee
 * un tableau des cartes vu/ un tableau des cartes de depart
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
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
        vector<Carte*> getCarteDepart();    //Retourne le tableau de carte

        Personnage* getPerso();             //Retourne le perso
        std::string getNom();               //Retourne le nom du personnage qu'incarne le joueur

        sf::Texture getTexture();

        void setPosition(Case* c);          //Met la position du joueur à jour
        Case* getPosition();                //Retourne la positon du joueur

        Case* getDernierePiece();           //Retourne la dernière pièce
        void setDernierePiece(Case* c);     //Met à jour la derniere piece visite

        void setChecklist(vector<bool> vecteur);
        void setChecklistAtTrue(unsigned int i);
        vector<bool> getChecklist();


    private:

        Personnage* perso_;             // Le personnage qu'incarne le joueur
        Case* position_;                //La position du joueur
        Case* dernierePiece_;            //La derniere piece visité

        vector<Carte*> tabCarteDepart;  //tab des cartes de depart max 12
        vector<Carte*> tabCarteVu;      //tab des cartes vus pendant le jeu max 24
        vector<bool> checklist;         // checklist du joueur

        sf::Texture im;


};

#endif // JOUEUR_H

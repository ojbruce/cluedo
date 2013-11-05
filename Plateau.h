#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Case.h"
#include "Piece.h"
#include "Mur.h"
#include "Porte.h"
#include "Joueur.h"

using namespace sf;
using namespace std;

class Plateau{

	public:
		Plateau();	        //Constructeur par defaut
		virtual ~Plateau(); //Destructeur du plateau
		//operateur affectation

		void afficher();    /*affichage pour eventuel erreur*/
		void afficher(sf::RenderWindow &window);		//méthode qui va afficher le plateau

		void positionSouris(sf::RenderWindow &window);  // Retrouve la position de la souris sur le plateau
		bool positionValide(int x, int y); //Retourne si la position actuelle de la souris est bien sur le plateau

		Case* trouverCase(int x, int y); // trouve la case à la position x et y

        void trouverChemin(sf::RenderWindow &window); //permet d'indiquer tous les chemins à partir d'un jet de de

		//void trouverChemin(Case* depart, int de, vector<Case*> &res); //permet d'indiquer tous les chemins à partir d'un jet de de


		bool caseValide(int x, int y);  // Renvoie si la case est valide dans le plateau

        //accesseur
        Case* getCase(int x, int y);


    protected:
    private:
        //Initier les cases
        void initCases();
        void creerMur(int a, int b);


		//Constantes du plateau
		const static int largPlateau_ = 24; 	//largeur de plateau
		const static int hautPlateau_ = 25;		//hauteur de plateau
		const static int tailleCase_ =26;

		const static int ecartX_=41;
		const static int ecartY_=30;

		//Image du plateau
		Texture im;
		Sprite plateau;

		//Joueur j1
		Joueur j1;

		//Image du pion bleu
		sf::CircleShape *shape;

		//Tableau a deux dimensions de case
		Case* tab[hautPlateau_][largPlateau_];

		//vector<Case> lesCases;

};

#endif // PLATEAU_H

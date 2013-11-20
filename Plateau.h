#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Case.h"
#include "Piece.h"
#include "Mur.h"
#include "Porte.h"
#include "Joueur.h"
#include "Donnees.h"

class Plateau{

	public:
		Plateau();	        //Constructeur par defaut
		virtual ~Plateau(); //Destructeur du plateau

		void afficher();                                /*affichage pour eventuel erreur*/
		void afficher(sf::RenderWindow &window);		//méthode qui va afficher le plateau


		bool positionValide(int x, int y);              //Retourne si la position actuelle de la souris est bien sur le plateau
        bool caseValide(int x, int y);                  // Renvoie si la case est valide dans le plateau

		Case* trouverCase(int x, int y);                // trouve la case à la position x et y en fonction de l'ecran

        //accesseur
        Case* getCase(int x, int y);


    private:
        //Initier les cases
        void initCases();
        void creerMur(int a, int b);

		//Constantes du plateau
		const static int largPlateau_ = 24; 	//largeur de plateau
		const static int hautPlateau_ = 25;		//hauteur de plateau
		const static int tailleCase_ =20;       //taille de case

		const static int ecartX_=20;
		const static int ecartY_=20;

		//Image du plateau
		sf::Texture im;
		sf::Sprite plateau;

		//Tableau a deux dimensions de case
		Case* tab[hautPlateau_][largPlateau_];

};

#endif // PLATEAU_H

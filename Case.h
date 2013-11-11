#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>


class Plateau;

class Case{

	public:
		Case();                          //Constructeur par defaut
		Case(int a, int b);              //Constructeur avec x et y


		virtual ~Case();                //Destructeur du plateau

		void afficher();
		virtual std::string toString();

        virtual void trouverChemin(int de, std::vector<Case*> &res, Plateau* p ); // methode qui trouve tous les chemins possibles



        //renvoie le point en haut à gauche de la case en fonction de l'affichage
		std::pair<int,int> pointHG(int tailleCase, int ecartX, int ecartY);
        std::pair<int,int> milieu(int tailleCase, std::pair<int,int> a);

        //virtual void action();

        //coloration de la case
        void colorerCase();

		//Getter Setter
		virtual int getX();
		virtual int getY();
		virtual int getEstVide();
		virtual void setEstVide(bool b);



   protected:
        //Coordonnee
        int x_;	//largeur du point en haut
        int y_;	//hauteur du point en bas

        //Etat plein/vide
        bool estVide;

        const static int taille_ =26;   //taille de case

        sf::RectangleShape* rectangle;  //La forme s'affichant sur la case


    private:
        //On empeche l'appel du constructeur de copie et de operator
        Case(const Case& c);            //Constructeur de recopie
        Case& operator=(Case const&);   // opérateur d'affectation


};

#endif // CASE_H

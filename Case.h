#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>


class Plateau;

/**
 * Case est la classe représentant les cases du plateau.
 *
 * Une CAse est caractérisé par les informations suivantes :
 * un x
 * un y
 * un bool estvide
 *
 * Herite de Case.
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Case{

	public:
		Case();                             //Constructeur par defaut
		Case(int a, int b);                 //Constructeur avec x et y

        bool operator== (Case const &c2);   //Operateur d'egalite

		virtual ~Case();                    //Destructeur du plateau

		void afficher();
		virtual std::string toString();

        virtual void trouverChemin(int de, std::vector<Case*> &res, Plateau* p ); // methode qui trouve tous les chemins possibles
        virtual std::string action();   //Methode qui renvoie un nom par polymorphisme

        //renvoie le point en haut à gauche de la case en fonction de l'affichage
		std::pair<int,int> pointHG(int tailleCase, int ecartX, int ecartY);
        std::pair<int,int> milieu(int tailleCase, std::pair<int,int> a);


        void colorier(sf::RenderWindow &window);       //coloration de la case

		//Getter Setter
		virtual int getX();                         //retroune le x
		virtual int getY();                         //Retourne le y
		virtual int getEstVide();                   //Retroune si la case est vide
		virtual void setEstVide(bool b);            //Modifie lsi la case est vide



   protected:
        //Coordonnee
        int x_;	    //largeur du point en haut
        int y_;	    //hauteur du point en bas

        //Etat plein/vide
        bool estVide;

        const static int taille_ =20;   //taille de case

        sf::RectangleShape* rectangle;  //La forme s'affichant sur la case


    private:
        //On empeche l'appel du constructeur de copie et de operator
        Case(const Case& c);            //Constructeur de recopie
        Case& operator=(Case const&);   // opérateur d'affectation


};

#endif // CASE_H

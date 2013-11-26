#include "Piece.h"
#include "Porte.h"

Piece::Piece(std::string n) :Case(),nom_(n){}

Piece::Piece(int a, int b, std::string n) :Case(a,b),nom_(n){}


/**
 * Affichage d'erreur
 */
std::string Piece::toString(){

	std::string res;

	std::ostringstream oss;
	//oss << "["<< x_ << "]" << "["<< y_ << "]p";
    oss<<"p";
	res = oss.str();


	return res;
}


/**
 * Methode qui va réaliser l'action selon la case
 * @return chaine vide pour une piece
 */
std::string Piece::action(){
    //appeler par une Porte on va appeler un ecran
    return "";
}

/**
 * Modificateur de la porte
 * @param une porte p
 */
void Piece::setPorte(Porte* p){
    porte=p;
}

/**
 * Methode qui trouve tous les chemins possibles
 * @param de le nombre a parcourir
 * @param res le vetor des chemins
 * @param p le plateau
 */
void Piece::trouverChemin(int de, vector<Case*> &res, Plateau* p){
    //on ne fait rien
}

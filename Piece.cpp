#include "Piece.h"

Piece::Piece() :Case(){}

Piece::Piece(int a, int b) :Case(a,b){}



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
 */
std::string Piece::action(){
    //appeler par une Porte on va appeler un ecran
    return "";
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

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


void Piece::trouverChemin(int de, vector<Case*> &res, Plateau* p){
    //on ne fait rien

}

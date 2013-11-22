#include "Mur.h"

Mur::Mur() : Case(){}

Mur::Mur(int a, int b) :Case(a,b){}


std::string Mur::toString(){

	std::string res;

	std::ostringstream oss;
	//oss << "["<< x_ << "]" << "["<< y_ << "]p";
    oss<<"m";
	res = oss.str();

	return res;
}

/**
 * Methode qui va réaliser l'action selon la case
 */
std::string Mur::action(){
    //appeler par une Porte on va appeler un ecran
    return "";
}

/**
 * Methode qui trouve tous les chemins possibles
 * @param de le nombre a parcourir
 * @param res le vetor des chemins
 * @param p le plateau
 */
void Mur::trouverChemin(int de, vector<Case*> &res, Plateau* p){}


Mur::~Mur()
{
    //dtor
}

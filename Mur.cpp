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


void Mur::trouverChemin(int de, vector<Case*> &res, Plateau* p){
}


Mur::~Mur()
{
    //dtor
}

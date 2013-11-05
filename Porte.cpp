#include "Porte.h"

Porte::Porte(string nom): Piece() {
    nom_=nom;
}

Porte::Porte(string nom,int a, int b) :Piece(a,b)  {nom_=nom;}


Porte::Porte(const Porte& p,int a, int b):Piece(a,b), tabPiece_(p.tabPiece_){
    nom_=p.getNom();

}

string Porte::toString(){

	string res;

	ostringstream oss;
	//oss << "["<< x_ << "]" << "["<< y_ << "]p";
    oss<<"¤";
	res = oss.str();

	return res;
}

void Porte::ajouterPiece(Piece* p){
    tabPiece_.push_back(p);
}

//Getter
string Porte::getNom() const{
    return nom_;
}


void Porte::trouverChemin(int de, vector<Case*> &res, Plateau* p){
    //on insere l'element courant
    res.push_back(this);

}





Porte::~Porte()
{
    //dtor

}

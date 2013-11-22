#include "Porte.h"

using namespace std;

/**
 *Constructeur
 */
Porte::Porte(string nom, Case* c): Piece(), cheminSecret(c) {
    nom_=nom;
}

/**
 *Constructeur
 */
Porte::Porte(string nom,int a, int b, Case* c) :Piece(a,b),cheminSecret(c)  {nom_=nom;}

/**
 *Constructeur
 */
Porte::Porte(const Porte& p,int a, int b, Case* c):Piece(a,b), tabPiece_(p.tabPiece_){
    nom_=p.getNom();
    cheminSecret = p.cheminSecret;
}

string Porte::toString(){

	string res;

	ostringstream oss;
	//oss << "["<< x_ << "]" << "["<< y_ << "]p";
    oss<<"¤";
	res = oss.str();

	return res;
}

/**
 * Methode qui ajoute une piece à la porte
 *
 */
void Porte::ajouterPiece(Piece* p){
    tabPiece_.push_back(p);
}

//Getter
string Porte::getNom() const{
    return nom_;
}

 void Porte::setCheminSecret(Case* c){
    cheminSecret= c;
 }

/**
 * Methode qui va réaliser l'action selon la case
 */
std::string Porte::action(){
    return nom_;
}

/**
 * Methode qui trouve tous les chemins possibles
 * @param de le nombre a parcourir
 * @param res le vetor des chemins
 * @param p le plateau
 */
void Porte::trouverChemin(int de, vector<Case*> &res, Plateau* p){
    //tester le taille du res
    if(res.size() == 0)
        Case::trouverChemin(de, res, p);
    else
        //on insere l'element courant
        if(std::find(res.begin(), res.end(), this) == res.end())
        res.push_back(this);

    //si il y a plusieurs on trouvechemin a partir de tout cela
}


/**
 * Destructeur
 */
Porte::~Porte()
{
    //dtor

}

#include "Porte.h"




using namespace std;

/**
 *Constructeur
 */
Porte::Porte(string nom, Case* c): Piece(nom), cheminSecret(c) {}

/**
 *Constructeur
 */
Porte::Porte(string nom,int a, int b, Case* c) :Piece(a,b,nom),cheminSecret(c) {}

/**
 *Constructeur
 */
Porte::Porte(const Porte& p,int a, int b):Piece(a,b,p.Porte::nom_), tabPiece_(p.tabPiece_){
    cheminSecret = p.cheminSecret;
}

/**
 * Affichage d'erreur
 */
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
 * @param une piece a ajouter
 */
void Porte::ajouterPiece(Piece* p){
    tabPiece_.push_back(p);
    p->setPorte(this);
}

//Getter
/**
 * Retourne le nom de la porte
 * @param une case pointant vers la porte de l'autre piece
 */
string Porte::getNom() const{
    return Porte::nom_;
}

/**
 * Modificateur du chemin secret
 * @return nom le nom de la porte
 */
 void Porte::setCheminSecret(Case* c){
    cheminSecret= c;
 }

/**
 * Methode qui va réaliser l'action selon la case
 * @return le nom
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
    if(res.size() == 0){

        Case::trouverChemin(de, res, p);

        if(cheminSecret!=NULL)
            res.push_back(cheminSecret);
    }
    else{
        //on insere l'element courant
        if(std::find(res.begin(), res.end(), this) == res.end())
            res.push_back(this);
   }

}


/**
 * Destructeur
 */
Porte::~Porte()
{
    //dtor

}

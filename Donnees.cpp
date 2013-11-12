#include "Donnees.h"


Donnees::Donnees()
{
    //initTabCarte();
    //initTabPerso();
}

Donnees::~Donnees()
{
    //dtor
}

/*void Donnees::initTabCarte(){

}

void Donnees::initTabPerso(){

}*/

/**
 *Retourne les cartes mysteres
 *
 */
/*vector<Carte*> Donnees::initCarteMystere(){
    vector<Carte*> res(3);
    srand(time(NULL)); // place le rand à un endroit diferent selon le time
    //0-8 piece
    int indice = rand() % 9;
    res.push_back(&tabCartes[indice]);

    //9-16 persos
    indice = rand() % 8+9;
    res.push_back(&tabCartes[indice]);

    //17-23 armes
    indice = rand() % 7+17;
    res.push_back(&tabCartes[indice]);

    return res;
}*/




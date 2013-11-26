#include "Jeu.h"

using namespace std;


/**
* Fonction principale
* Role : Elle cree un jeu puis le lance
*/
int main(void)
{
    Jeu* clue= Jeu::getInstance();
    clue->lancerJeu();

    //En cas de fermeture involontaire
    bool quitte=false;

    if(quitte==true){
        Jeu* clue2= Jeu::getInstance();
        clue2->lancerJeu();
    }


    return 0;
}

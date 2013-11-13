#include <iostream>

#include "Jeu.h"

#include "Partie.h"


using namespace std;


int main(void)
{
    cerr<<"Main:: CreationPlateau"<< endl;
    Plateau* p = new Plateau();
    cerr<<"Main:: Plateau Creer/ CreationPartie"<< endl;
    Partie partie(2, p);
    cerr<<"Main:: Partie creer"<< endl;


    delete p;

    return 0;
}

#include <iostream>

#include "Jeu.h"

#include "Partie.h"


using namespace std;


int main(void)
{
    Plateau* p = new Plateau();
    Partie partie(2, p);
    cerr<<"Main:: Partie creer"<< endl;
    delete p;

    return 0;
}

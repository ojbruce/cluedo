#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>

#include "ManagerEcran.h"

using namespace std;


class Jeu
{
    public:
        Jeu();
        virtual ~Jeu();

        void lancerJeu();

    protected:
    private:
        ManagerEcran manEcran;

};

#endif // JEU_H

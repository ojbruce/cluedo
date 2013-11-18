#ifndef MUR_H
#define MUR_H

//Pour l'heritage
#include "Case.h"

using namespace std;

class Mur : public Case
{
    public:
        Mur();
        Mur(int a, int b);
        virtual ~Mur();

        virtual void action();
        virtual string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);

    protected:
    private:
};

#endif // MUR_H

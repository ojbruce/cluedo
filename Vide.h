#ifndef VIDE_H
#define VIDE_H

#include "EtatCase.h"

class Case;

class Vide: public EtatCase{
    public:
        Vide(Case& client);
        virtual ~Vide();

        virtual void entrer();
        virtual void sortir();

    protected:
    private:
        Case& c;
};

#endif // VIDE_H

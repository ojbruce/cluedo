#ifndef PLEIN_H
#define PLEIN_H

#include "EtatCase.h"



class Case;

class Plein : public EtatCase{

    public:
        Plein(Case& client);
        virtual ~Plein();

        virtual void entrer();
        virtual void sortir();

    private:
        Case& c;
};

#endif // PLEIN_H

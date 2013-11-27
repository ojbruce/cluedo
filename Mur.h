#ifndef MUR_H
#define MUR_H

//Pour l'heritage
#include "Case.h"

using namespace std;

/**
 * Mur est la classe abstraite représentant les murs les positions ou on ne peut pas deplacer.
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Mur : public Case
{
    public:
        Mur();
        Mur(int a, int b);
        virtual ~Mur();

        virtual std::string action();
        virtual std::string toString();
        virtual void trouverChemin(int de, vector<Case*> &res, Plateau* p);


    protected:
    private:
};

#endif // MUR_H

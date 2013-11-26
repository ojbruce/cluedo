#ifndef FACTORYCARTE_H
#define FACTORYCARTE_H

#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "CartePiece.h"
#include "CartePersonnage.h"
#include "CarteArme.h"

class FactoryCarte : public Factory
{
    public:

        virtual Carte* creer(string type, string nom, string chemin);

};

#endif // FACTORYCARTE_H

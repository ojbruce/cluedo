#ifndef FACTORY_H
#define FACTORY_H

#include <SFML/Graphics.hpp>
#include "Carte.h"

class Factory
{
    public:

        virtual Carte* creer(string type, string nom, string chemin)=0;
};

#endif // FACTORY_H

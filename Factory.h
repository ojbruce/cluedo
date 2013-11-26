#ifndef FACTORY_H
#define FACTORY_H

#include <SFML/Graphics.hpp>
#include "Carte.h"

/**
 * Factory est la classe abstraite représentant la factory carte.
 *
 * Il est caractérisé par les informations suivantes :
 * une methode pour creer
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Factory
{
    public:

        virtual Carte* creer(string type, string nom, string chemin)=0;
};

#endif // FACTORY_H

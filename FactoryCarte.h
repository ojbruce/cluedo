#ifndef FACTORYCARTE_H
#define FACTORYCARTE_H

#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "CartePiece.h"
#include "CartePersonnage.h"
#include "CarteArme.h"

/**
 * FactoryCarte est la classe représentant la classe concrete de la factory carte.
 *
 * Il est caractérisé par les informations suivantes :
 * une methode pour creer des cartes
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class FactoryCarte : public Factory
{
    public:

        virtual Carte* creer(string type, string nom, string chemin);

};

#endif // FACTORYCARTE_H

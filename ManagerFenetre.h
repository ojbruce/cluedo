#ifndef MANAGERFENETRE_H
#define MANAGERFENETRE_H

#include "Fenetre.h"
#include "Observer.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

class FenetreInfo;
class FenetreChoix;
class FenetreContrer;

/**
 * ManagerFenetre est la classe représentant la classe qui fait les transitions entre les fenetres.
 *
 * Elle est caractérisé par les informations suivantes :
 * des methodes qui ouvre des fenetres
 * une methode qui observe les choix
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class ManagerFenetre
{
    public:

      ManagerFenetre();
      virtual ~ManagerFenetre();

      void ouvrirFenetreInfo();
      void ouvrirFenetreChoix();
      void ouvrirFenetreContrer(std::string chemin);

      void observerChoix(Observer* observer);

    private:

      FenetreInfo* fenetreInfo;          //La fenetre informant ce qui se passe
      FenetreChoix* fenetreChoix;        //La fentre permettant de chosir ce qu'on peut faire
      FenetreContrer* fenetreContrer;   //La fenetre qui montre ce qui a contrer

};

#endif

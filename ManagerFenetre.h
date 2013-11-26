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

#ifndef MANAGERFENETRE_H
#define MANAGERFENETRE_H

#include "Fenetre.h"
#include "Observer.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

class FenetreInfo;
class FenetreChoix;


class ManagerFenetre
{
    public:

      ManagerFenetre();
      virtual ~ManagerFenetre();

      void ouvrirFenetreInfo();
      void ouvrirFenetreChoix();

      void observerChoix(Observer* observer);

    private:

      FenetreInfo* fenetreInfo;
      FenetreChoix* fenetreChoix;

      //fenetreContrer;

};

#endif

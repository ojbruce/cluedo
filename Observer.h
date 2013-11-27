#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

using namespace std;

/**
 * Observer est la classe abstraite représentant l'observer abstrait.
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Observer
{
    public:

        virtual void estNotifie(std::string choix1, std::string choix2, std::string act)=0;

};

#endif

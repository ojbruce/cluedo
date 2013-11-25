#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

using namespace std;

class Observer
{
    public:
    
        virtual void estNotifie(std::string choix1, std::string choix2, std::string act)=0;

};

#endif 

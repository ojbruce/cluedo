#ifndef OBSERVABLE_H
#define OBSERVABLE_H


class Observable
{
    public:
    
      virtual void ajouterObs(Observer* obs)=0;
      virtual void enleverObs(Observer* obs)=0;
      virtual void notifyObs()=0;
};

#endif 

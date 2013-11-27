#ifndef OBSERVABLE_H
#define OBSERVABLE_H

/**
 * Observable est la classe abstraite représentant le sujet observer.
 *
 * Elle est caractérisé par les informations suivantes :
 * une methode ajouter un observateur
 * une methode supprimer un observateur
 * une methode notifier un observateur
 *
 *
 * @author Olivia Bruce
 * @author Cassandre Gloria
 * @version 1.0
 */
class Observable
{
    public:

      virtual void ajouterObs(Observer* obs)=0;
      virtual void enleverObs(Observer* obs)=0;
      virtual void notifyObs()=0;
};

#endif

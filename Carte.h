#ifndef DEF_CARTE
#define DEF_CARTE

#include<string>
using namespace std;

class Carte
{
    public:
        Carte(string nom, string chemin);   // Constructeur
        virtual ~Carte();                  //Destructeur

        bool operator== (Carte const &c2); // Operateur d'egalite

        // Getter
        string getNom();        //retourne le nom
        string getChemin();     //retourne le chemin

    private:

        string nom;
        string chemin;


};

#endif

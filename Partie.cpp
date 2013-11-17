#include "Partie.h"

//Partie::Partie():  donnees(p), partieFini_(false){}

Partie::Partie(int nbJ,  Plateau* plat,  ZoneAffichageTexte* zone1): donnees(plat),partieFini_(false), deClique_(false), joueurCourant(0),nbJoueur_(nbJ),p(plat), zoneText(zone1) {

    if (!font.loadFromFile("arial.ttf")){ }
    texte = new sf::Text("Lancer le de", font);


    //initialise le tableau de joueur
    tabJoueur_= donnees.initJoueur(nbJ);
    cerr<<"Partie::initialisation tableau de joueur fini"<< endl;

    //initialise le tableau des cartes mysteres
    tabMystere_ = donnees.initCarteMystere();
     cerr<<"Partie::initialisation tableau de carte Mystere fini"<< endl;

     //distribution des cartes aux joueurs
     donnees.distribuerCarte(tabJoueur_);
     cerr<<"Partie::distribution des cartes"<< endl;


    //afficher les joueurs

}

Partie::~Partie()
{
    //dtor
    cerr<<"Partie::Destruction"<< endl;
}

/**
 * Methoque qui prend un nombre aleatoire entre 2 et 12
 * @return rand un random entre 2 et 12
 **/
int Partie::lancerDe(){
	srand(time(NULL)); // place le rand à un endroit diferent selon le time
    return rand() % 11+2;
}

void Partie::update(sf::RenderWindow &window){

    //on recupere la position
    sf::Vector2i souris = sf::Mouse::getPosition(window);

    //Variables
    int de;


	if(p->positionValide(souris.x,souris.y)){

        Joueur j =tabJoueur_.at(joueurCourant);

        //Si le joueur clique sur le centre on lance le de et cherche les chemins
        if(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 && !deClique_ ){

            de = lancerDe();
            cerr<< "Partie::De = "<< de <<" " <<j.getPerso()->getNom() << endl;

            Case* posCourante = j.getPosition();    //la position du joueur avant le debut du tour
            posCourante->trouverChemin(de,chemin,p,true);                           //on cherche les positions possibles

            cerr<< "Partie:: taille chemin possible " <<chemin.size()<<endl;

            deClique_=true;
        }

        //si le joueur clique sur des cases et à cliquer sur le dé avant
        if(deClique_ && !(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 ) ){

            cerr<< "Partie:: taille chemin possible " <<chemin.size()<<endl;

            //Verifier que la case cliquer est bien dans le tableau des chemins
            Case* nCase= p->trouverCase(souris.x,souris.y);

            if(std::find(chemin.begin(), chemin.end(), nCase) == chemin.end()){
                //chemin ne contient pas la case elle n'est donc pas valide
                cerr<< "Partie::case en dehors du champ du dé" <<endl;

            }else{
                //on peut deplacer le joueur
                j.getPosition()->setEstVide(true);   //ancienne case vide
                j.setPosition(nCase);               // deplacer dasn nouvelle case
                nCase->setEstVide(false);            //nouvelle case pleine

                cerr<< "Partie:: Joueuer deplacer" <<endl;

                //On est dans la nouvelle case


                //On change les elements de la classe pour que le jeu continue
                deClique_ = false;
                //On vide le tableau des chemins poissibles
                chemin.clear();
                //on passe au joueur suivant
                if(joueurCourant< tabJoueur_.size()-1)
                    joueurCourant++;
                else
                    joueurCourant =0;
            }




        }

	}

}

void Partie::afficher(sf::RenderWindow &window){

    sf::Text* joueur = new sf::Text("J:" +tabJoueur_.at(joueurCourant).getPerso()->getNom(), font);
    joueur->setPosition(220,220);
    joueur->setCharacterSize(10);

    texte->setPosition(220,300);
    texte->setCharacterSize(15);


    window.draw(*joueur);
    window.draw(*texte);
}




#include "Partie.h"

Partie::Partie(Plateau* plat,  ZoneAffichageTexte* zoneT, ZoneCarte* zoneC, ZoneChecklist* zoneCheck, DonneesJeu* d): donnees(d), deClique_(false),p(plat), zoneText(zoneT), zoneCarte(zoneC),zoneChecklist(zoneCheck) {
  	armeCrime="";
  	persoCrime="";
  	action="";

  	manFen.observerChoix(this);

    if (!font.loadFromFile("arial.ttf")){ }

    cerr<<"Partie::Creation Partie"<<endl;
}

Partie::~Partie()
{
    //dtor
    cerr<<"Partie::Destruction"<< endl;
}


/**
* Fonction preparer
*/
void Partie::preparer()
{
    donnees->preparerPartie(p);
}


/**
* Fonction update
*/
void Partie::update(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;   //on recupere la position

    zoneChecklist->update(donnees->getJoueurCourant(), event);


	if(p->positionValide(x,y)){

        Joueur &j=*donnees->getJoueurCourant();
        cerr<<j.getNom()<<endl;


        //Si le joueur clique sur le centre on lance le de et cherche les chemins
        if(y >=220 && y<=360 && x>=220 && x<=320 && !deClique_ ){

            Case* posCourante = j.getPosition();        //la position du joueur avant le debut du tour
            posCourante->setEstVide(true);               // avant de chercher on vide la case
            posCourante->trouverChemin(donnees->lancerDe(),chemin,p);    //on cherche les positions possibles

            deClique_=true;
        }


        if(deClique_ && !(y >=220 && y<=360 && x>=220 && x<=320 ) ){

            Case* nCase= p->trouverCase(x,y);     //On trouve la case

            //Verifier que la case cliquer est bien dans le tableau des chemins
            if(std::find(chemin.begin(), chemin.end(), nCase) == chemin.end()){
                //chemin ne contient pas la case elle n'est donc pas valide
                cerr<< "Partie::case en dehors du champ du dé" <<endl;


            }else{

                //on peut deplacer le joueur
                j.getPosition()->setEstVide(true);   //ancienne case vide
                j.setPosition(nCase);               // deplacer dasn nouvelle case
                nCase->setEstVide(false);            //nouvelle case pleine

                std::string lieu;
                lieu=nCase->action();

                std::string cheminres;

                //On est dans la nouvelle case
                if(lieu !=""){
                    cerr<<"la"<<endl;
					manFen.ouvrirFenetreInfo();	//ouvre une fenetre d'info
					manFen.ouvrirFenetreChoix();//ouvre la fenetre permettant au joueur de faire un choix

					cerr<<"Partie::obs"<<armeCrime<<" " <<persoCrime<<" " <<lieu<<endl;

                    if(action=="a"){
                        cerr<<"Partie::accuser" <<lieu<<endl;
                        donnees->accuser(armeCrime,persoCrime,lieu);

                    }else{
                        cheminres=donnees->soupconner(armeCrime,persoCrime,lieu);
                    }
                }

                //On change les elements de la classe pour que le jeu continue
                deClique_ = false;

                //On vide le tableau des chemins poissibles
                chemin.clear();

                donnees->changerJoueur();
            }
        }
	}
}

void Partie::afficher(sf::RenderWindow &window){


    //affichage du chemin bleu
    for(unsigned int j=0; j < chemin.size(); j++)
    {
        chemin.at(j)->colorier(window);
    }


    //affichage du joueur
    for(int i=0; i < donnees->getNbJoueur(); i++)
    {
        donnees->getJoueurAt(i)->update(window);
    }

    //afficher les cartes du joueur en cours
    zoneChecklist->afficherChecklist(donnees->getJoueurCourant(), window);
    zoneCarte->afficherCarte(*donnees->getJoueurCourant(), window);
    //zoneText->afficher(window);

    //sf::Text de(L"Lancer le dé", font);
    //de.setPosition(820,10);
    //de.setCharacterSize(11);


    //window.draw(de);

}


/**
* Fonction notify
*/
void Partie::estNotifie(std::string choix1, std::string choix2, std::string act){
	    action =act;
	    persoCrime = choix1;
	    armeCrime = choix2;
}



#include "Partie.h"

//Partie::Partie():  donnees(p), partieFini_(false){}

Partie::Partie(int nbJ,  Plateau* plat,  ZoneAffichageTexte* zoneT, ZoneCarte* zoneC): partieFini_(false), deClique_(false), joueurCourant(0), de(0),nbJoueur_(nbJ),p(plat), zoneText(zoneT), zoneCarte(zoneC) {

    if (!font.loadFromFile("arial.ttf")){ }
    texte = new sf::Text("Lancer le de", font);

    //initialise le tableau de joueur
    tabJoueur_= donnees.initJoueur(nbJ);

    //initialise le tableau des cartes mysteres
    tabMystere_ = donnees.initCarteMystere();

    //distribution des cartes aux joueurs
    donnees.distribuerCarte(tabJoueur_);

    donnees.positionnerPerso(p);
    cerr<<"Fin creation partie" <<endl;
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
    cerr<<"lala"<<endl;
    sf::Vector2i souris = sf::Mouse::getPosition(window);   //on recupere la position

	if(p->positionValide(souris.x,souris.y)){

        Joueur &j =tabJoueur_.at(joueurCourant);    //on prend le joueur par refernce

        //Si le joueur clique sur le centre on lance le de et cherche les chemins
        if(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 && !deClique_ ){

            de = lancerDe();                            //on lance le de

            Case* posCourante = j.getPosition();        //la position du joueur avant le debut du tour
            posCourante->setEstVide(true);               // avant de chercher on vide la case
            posCourante->trouverChemin(de,chemin,p);    //on cherche les positions possibles

            deClique_=true;
        }


        if(deClique_ && !(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 ) ){
            //si le joueur clique sur des cases et à cliquer sur le dé avant

            Case* nCase= p->trouverCase(souris.x,souris.y);     //On trouve la case

            //Verifier que la case cliquer est bien dans le tableau des chemins
            if(std::find(chemin.begin(), chemin.end(), nCase) == chemin.end()){
                //chemin ne contient pas la case elle n'est donc pas valide
                cerr<< "Partie::case en dehors du champ du dé" <<endl;

            }else{

                //on peut deplacer le joueur
                j.getPosition()->setEstVide(true);   //ancienne case vide
                j.setPosition(nCase);               // deplacer dasn nouvelle case
                nCase->setEstVide(false);            //nouvelle case pleine

                //On est dans la nouvelle case
                nCase->action(); // Va renvoyer les 3 cartes et si on soupconne


                //int x;
                //cout <<"Entrer un nom"<<endl;
               //cin >>x;

                //on verifie que les cartes sont les mysteres
                //Carte* c1=donnees.getCarte(0);
                //Carte* c2=donnees.getCarte(5);
                //Carte* c3=donnees.getCarte(10);

                //std::find(tabMystere_.begin(), tabMystere_.end(), c1) == tabMystere_.end(){tabSoupcon_.push_back(c1);}
                //std::find(tabMystere_.begin(), tabMystere_.end(), c2) == tabMystere_.end(){tabSoupcon_.push_back(c2);}
                //std::find(tabMystere_.begin(), tabMystere_.end(), c3) == tabMystere_.end(){tabSoupcon_.push_back(c3);}







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

    std::stringstream sstm;
    sstm << "De= " << de;
    std::string result = sstm.str();
    sf::Text* text;

    sf::Text* joueur = new sf::Text("A vous joueur: \n" +tabJoueur_.at(joueurCourant).getPerso()->getNom(), font);
    joueur->setPosition(220,220);
    joueur->setCharacterSize(11);

    //Le texte depend de ce qui est clique ou pas
    if(!deClique_)
        text = new sf::Text(L"Cliquer au centre\npour\nlancer le dé", font);
    else
        text = new sf::Text(result, font);

    text->setPosition(220,300);
    text->setCharacterSize(11);


    //affichage du chemin bleu
    for(unsigned int j=0; j < chemin.size(); j++){
        chemin.at(j)->update(window);
    }

    //affichage du joueur
    for(unsigned int i=0; i < tabJoueur_.size(); i++){
        tabJoueur_.at(i).update(window);
    }

    //afficher les cartes du joueur en cour
    zoneCarte->afficherCarte(tabJoueur_.at(joueurCourant), window);

    window.draw(*joueur);
    window.draw(*text);

}




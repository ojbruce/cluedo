#include "Partie.h"

Partie::Partie(Plateau* plat,  ZoneAffichageTexte* zoneT, ZoneCarte* zoneC, DonneesJeu* d): donnees(d), deClique_(false),p(plat), zoneText(zoneT), zoneCarte(zoneC) {

    if (!font.loadFromFile("arial.ttf")){ }
    texte = new sf::Text("Lancer le de", font);

    cerr<<"Partie avant"<<endl;
    donnees->preparerPartie(p);

    cerr<<"Creation Partie"<<endl;
}

Partie::~Partie()
{
    //dtor
    cerr<<"Partie::Destruction"<< endl;
}


void Partie::update(sf::RenderWindow &window){

    sf::Vector2i souris = sf::Mouse::getPosition(window);   //on recupere la position

	if(p->positionValide(souris.x,souris.y)){

        Joueur &j=*donnees->getJoueurCourant();

        //Si le joueur clique sur le centre on lance le de et cherche les chemins
        if(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 && !deClique_ ){

            Case* posCourante = j.getPosition();        //la position du joueur avant le debut du tour
            posCourante->setEstVide(true);               // avant de chercher on vide la case
            posCourante->trouverChemin(donnees->lancerDe(),chemin,p);    //on cherche les positions possibles

            deClique_=true;
        }


        if(deClique_ && !(souris.y >=220 && souris.y<=360 && souris.x>=220 && souris.x<=320 ) ){

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

                std::string lieu;
                lieu=nCase->action();

                std::string chemin;

                //On est dans la nouvelle case
                if(lieu !=""){

                    cout<< "accuser a ou soupconner s?" <<endl;
                    std::string x;
                    x="s";

                    if(x=="a"){
                        donnees->accuser("book","Mrs. White",lieu);
                    }else{
                        chemin=donnees->soupconner("book","Mrs. White","Hall");
                    }
                }

                //On change les elements de la classe pour que le jeu continue
                deClique_ = false;

                donnees->changerJoueur();
            }

            //On vide le tableau des chemins poissibles
            chemin.clear();
        }
	}
}

void Partie::afficher(sf::RenderWindow &window){

    std::stringstream sstm;
    sstm << "De= " << donnees->getDe();

    std::string result = sstm.str();
    sf::Text* text;

    sf::Text* joueur = new sf::Text("A vous joueur: \n" +donnees->getJoueurCourant()->getPerso()->getNom(), font);
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
    for(int i=0; i < donnees->getNbJoueur(); i++){
        donnees->getJoueurAt(i)->update(window);
    }

    //afficher les cartes du joueur en cour
    //zoneCarte->afficherCarte(*donnees->getJoueurCourant(), window);
    //zoneText->afficher(window);


    window.draw(*joueur);
    window.draw(*text);

}





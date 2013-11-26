#include "FenetreChoix.h"
#include "ManagerFenetre.h"


#include <iostream>

using namespace std;


/**
* Constructeur
*/
 FenetreChoix::FenetreChoix(ManagerFenetre *man) :
    accuser(Bouton("Images/accuserDepart.png", "Images/accuserClique.png")),
    soupcon(Bouton("Images/soupconDepart.png", "Images/soupconClique.png")),
    c1(Bouton("Images/green.png", "Images/greenClique.png")),
    c2(Bouton("Images/meadowbrook.png", "Images/meadowbrookClique.png")),
    c3(Bouton("Images/mustard.png", "Images/mustardClique.png")),
    c4(Bouton("Images/peacock.png", "Images/peacockClique.png")),
    c5(Bouton("Images/plum.png", "Images/plumClique.png")),
    c6(Bouton("Images/rusty.png", "Images/rustyClique.png")),
    c7(Bouton("Images/scarlett.png", "Images/scarlettClique.png")),
    c8(Bouton("Images/white.png", "Images/whiteClique.png")),
    c9(Bouton("Images/book.png", "Images/bookClique.png")),
    c10(Bouton("Images/telescope.png", "Images/telescopeClique.png")),
    c11(Bouton("Images/revolver.png", "Images/revolverClique.png")),
    c12(Bouton("Images/pen.png", "Images/penClique.png")),
    c13(Bouton("Images/paperweight.png", "Images/paperweightClique.png")),
    c14(Bouton("Images/letteropener.png", "Images/letteropenerClique.png")),
    c15(Bouton("Images/hairpin.png", "Images/hairpinClique.png")),
    manager(man),
    aClique(false)
{
    // On charge l'image d'accueil dans la texture "image"
    image.loadFromFile("Images/choix.png");

    // On met la texture dans le sprite accueil
    fond.setTexture(image);
}


/**
* Cette fonction lance l'affichage de la fênetre
* @param window la fenetre
*/
void FenetreChoix::afficher(RenderWindow &fenetre)
{
    fenetre.draw(fond);

 	if(aClique==false)
	{
		deselectionnerTout();
	}

    Sprite sp;

	//******************************************** A FAIRE
    // affichage des cartes personnage
    sp = accuser.getSprite();
    sp.move(sf::Vector2f(150, 500));
    fenetre.draw(sp);

    sp = soupcon.getSprite();
    sp.move(sf::Vector2f(580, 500));
    fenetre.draw(sp);

    sp = c1.getSprite();
    sp.move(sf::Vector2f(4,150));
    fenetre.draw(sp);

    sp = c2.getSprite();
    sp.move(sf::Vector2f(116,150));
    fenetre.draw(sp);

    sp = c3.getSprite();
    sp.move(sf::Vector2f(228,150));
    fenetre.draw(sp);

    sp = c4.getSprite();
    sp.move(sf::Vector2f(340,150));
    fenetre.draw(sp);

    sp = c5.getSprite();
    sp.move(sf::Vector2f(452,150));
    fenetre.draw(sp);

    sp = c6.getSprite();
    sp.move(sf::Vector2f(564,150));
    fenetre.draw(sp);

    sp = c7.getSprite();
    sp.move(sf::Vector2f(676,150));
    fenetre.draw(sp);

    sp = c8.getSprite();
    sp.move(sf::Vector2f(788,150));
    fenetre.draw(sp);


   // affichage des cartes armes
    sp = c9.getSprite();
    sp.move(sf::Vector2f(60,324));
    fenetre.draw(sp);

    sp = c10.getSprite();
    sp.move(sf::Vector2f(172,324));
    fenetre.draw(sp);

    sp = c11.getSprite();
    sp.move(sf::Vector2f(284,324));
    fenetre.draw(sp);

    sp = c12.getSprite();
    sp.move(sf::Vector2f(396,324));
    fenetre.draw(sp);

    sp = c13.getSprite();
    sp.move(sf::Vector2f(508,324));
    fenetre.draw(sp);

    sp = c14.getSprite();
    sp.move(sf::Vector2f(620,324));
    fenetre.draw(sp);

    sp = c15.getSprite();
    sp.move(sf::Vector2f(732,324));
    fenetre.draw(sp);
}



/**
 * Cette fonction permet le changement d'ecran en fonction des evenements
 * @param event un evenement envoyé par les classes superieurs
 */
void FenetreChoix::update(sf::Event event, sf::RenderWindow &fenetre)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

	aClique = true;

    cliqueConditionnel1(x,y,4,112,150,320,c1,c2,c3,c4,c5,c6,c7,c8);
    cliqueConditionnel1(x,y,116,224,150,320,c2,c1,c3,c4,c5,c6,c7,c8);
    cliqueConditionnel1(x,y,228,336,150,320,c3,c1,c2,c4,c5,c6,c7,c8);
    cliqueConditionnel1(x,y,340,448,150,320,c4,c1,c2,c3,c5,c6,c7,c8);
    cliqueConditionnel1(x,y,452,560,150,320,c5,c1,c2,c3,c4,c6,c7,c8);
    cliqueConditionnel1(x,y,564,672,150,320,c6,c1,c2,c3,c4,c5,c7,c8);
    cliqueConditionnel1(x,y,676,784,150,320,c7,c1,c2,c3,c4,c5,c6,c8);
    cliqueConditionnel1(x,y,788,892,150,320,c8,c1,c2,c3,c4,c5,c6,c7);

    cliqueConditionnel2(x,y,60,168,324,494,c9,c10,c11,c12,c13,c14,c15);
    cliqueConditionnel2(x,y,172,280,324,494,c10,c9,c11,c12,c13,c14,c15);
    cliqueConditionnel2(x,y,284,392,324,494,c11,c9,c10,c12,c13,c14,c15);
    cliqueConditionnel2(x,y,396,504,324,494,c12,c9,c10,c11,c13,c14,c15);
    cliqueConditionnel2(x,y,508,616,324,494,c13,c9,c10,c11,c12,c14,c15);
    cliqueConditionnel2(x,y,620,728,324,494,c14,c9,c10,c11,c12,c13,c15);
    cliqueConditionnel2(x,y,732,840,324,494,c15,c9,c10,c11,c12,c13,c14);

    actualiserChoix();

    if(150<=x && x<=320 && 500<=y && y<=570)
    {
        action = "a";
        actualiserChoix();
        notifyObs();
        accuser.clique();
        fenetre.close();
    }

    if(580<=x && x<=750 && 500<=y && y<=570)
    {
    	action = "s";
        actualiserChoix();
        notifyObs();
        soupcon.clique();
        fenetre.close();
    }
}


/**
 * Fonction cliqueConditionnel1
 * Role : appel la fonction clique du bouton si la souris a clique sur le bouton et deselectionne les autres boutons personnages
 */
void FenetreChoix::cliqueConditionnel1(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7, Bouton &b8)
{
    if(xmin<=x && x<=xmax && ymin<=y && y<=ymax)
    {
        b1.clique();
        b2.deselection();
        b3.deselection();
        b4.deselection();
        b5.deselection();
        b6.deselection();
        b7.deselection();
        b8.deselection();
    }
}


/*
* Fonction cliqueConditionnel2
* Role : appel la fonction clique du bouton si la souris a clique sur le bouton et deselectionne les autres boutons armes
*/

void FenetreChoix::cliqueConditionnel2(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton &b1, Bouton &b2, Bouton &b3, Bouton &b4, Bouton &b5, Bouton &b6, Bouton &b7)
{
    if(xmin<=x && x<=xmax && ymin<=y && y<=ymax)
    {
        b1.clique();
        b2.deselection();
        b3.deselection();
        b4.deselection();
        b5.deselection();
        b6.deselection();
        b7.deselection();
    }
}


/*
* Fonction ajouterObs
* Role : permet d'ajouter un observateur
*/
void FenetreChoix::ajouterObs(Observer* obs)
{
    observateurs.push_back(obs);
}


/*
* Fonction enleverObs
* Role : permet d'enlever un observateur
*/
void FenetreChoix::enleverObs(Observer* obs)
{
    for (std::vector<Observer*>::iterator it=observateurs.begin(); it!=observateurs.end(); ++it )
    {
        if (*it == obs)
            it = observateurs.erase(it);
    }
}


/*
* Fonction notifyObs
* Role : permet aux observateurs d'actualiser leurs donnees concernant les cartes selectionnees dans la fenetre
*/
void FenetreChoix::notifyObs()
{

    for (unsigned int index=0; index<observateurs.size(); ++index)
    {
        observateurs.at(index)->estNotifie(carte1, carte2, action);
    }
}


/*
* Fonction actualiserChoix
* Role : permet d'actualiser les attributs carte1 et carte2 correspondants aux cartes selectionnees par le joueur
*/
void FenetreChoix::actualiserChoix()
{
    if(c1.getClique()==true)
        carte1 = "Reverend-Green";
    if(c2.getClique()==true)
        carte1 = "Mrs-Meadow-Brook";
    if(c3.getClique()==true)
        carte1 = "Colonel-Mustard";
    if(c4.getClique()==true)
        carte1 = "Mrs-Peacock";
    if(c5.getClique()==true)
        carte1 = "Professor-Plum";
    if(c6.getClique()==true)
        carte1 = "Mr-Rusty";
    if(c7.getClique()==true)
        carte1 = "Miss-Scarlett";
    if(c8.getClique()==true)
        carte1 = "Mrs-White";

    if(c9.getClique()==true)
        carte2 = "Rare-Book";
    if(c10.getClique()==true)
        carte2 = "Telescope";
    if(c11.getClique()==true)
        carte2 = "Revolver";
    if(c12.getClique()==true)
        carte2 = "Gold-Pen";
    if(c13.getClique()==true)
        carte2 = "Crystal-Paperweight";
    if(c14.getClique()==true)
        carte2 = "Letter-Opener";
    if(c15.getClique()==true)
        carte2 = "Jade-Hairpin";
}


/*
* Fonction deselectionnerTout
*/
void FenetreChoix::deselectionnerTout()
{
	accuser.deselection();
	soupcon.deselection();

	c1.deselection();
	c2.deselection();
	c3.deselection();
	c4.deselection();
	c5.deselection();
	c6.deselection();
	c7.deselection();
	c8.deselection();
	c9.deselection();
	c10.deselection();
	c11.deselection();
	c12.deselection();
	c13.deselection();
	c14.deselection();
	c15.deselection();
}


/**
* Fonction setAClique
*/
void FenetreChoix::setACliqueFalse()
{
	aClique = false;
}



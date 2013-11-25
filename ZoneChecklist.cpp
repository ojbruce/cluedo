#include "ZoneChecklist.h"
#include "Joueur.h"

#include <iostream>

using namespace std;


/**
* Constructeur
*/
ZoneChecklist::ZoneChecklist(): 
    c1(Bouton("Images/checkDepart.png", "Images/checkClique.png")), 
    c2(Bouton("Images/checkDepart.png", "Images/checkClique.png")), 
     c3(Bouton("Images/checkDepart.png", "Images/checkClique.png")), 
     c4(Bouton("Images/checkDepart.png", "Images/checkClique.png")), 
     c5(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c6(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c7(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c8(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c9(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c10(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c11(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c12(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c13(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c14(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c15(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c16(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c17(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c18(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c19(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c20(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c21(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c22(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c23(Bouton("Images/checkDepart.png", "Images/checkClique.png")),
     c24(Bouton("Images/checkDepart.png", "Images/checkClique.png"))
{
    imageCheck.loadFromFile("Images/check.png");
    zoneCheck.setTexture(imageCheck);
    zoneCheck.move(sf::Vector2f(520,0));  
}


/**
* Destructeur
*/
ZoneChecklist::~ZoneChecklist()
{
}


/**
* Fonction importation
*/
void ZoneChecklist::importation(Bouton& b, int i, vector<bool> vec)
{
	if(vec[i]==true)
		b.selection();
	else
		b.deselection();
}


/**
* afficherChecklist
*/
void ZoneChecklist::afficherChecklist(Joueur* j, sf::RenderWindow &fenetre)
{
    vector<bool> vec = j->getChecklist();

    // Affichage de la checkliste 
    fenetre.draw(zoneCheck);
    
	//
	importation(c1,0,vec);		
	importation(c2,1,vec);
	importation(c3,2,vec);
	importation(c4,3,vec);
	importation(c5,4,vec);
	importation(c6,5,vec);	
	importation(c7,6,vec);
	importation(c8,7,vec);
	importation(c9,8,vec);	
	importation(c10,9,vec);
	importation(c11,10,vec);
	importation(c12,11,vec);	
	importation(c13,12,vec);
	importation(c14,13,vec);
	importation(c15,14,vec);	
	importation(c16,15,vec);
	importation(c17,16,vec);
	importation(c18,17,vec);
	importation(c19,18,vec);
	importation(c20,19,vec);	
	importation(c21,20,vec);
	importation(c22,21,vec);
	importation(c23,22,vec);	
	importation(c24,23,vec);		
	
    // Affichage des case a cocher 
    placerCaseCocher(c1,28,fenetre);
	placerCaseCocher(c2,46,fenetre);
	placerCaseCocher(c3,65,fenetre);
	placerCaseCocher(c4,83,fenetre);
	placerCaseCocher(c5,102,fenetre);
	placerCaseCocher(c6,120,fenetre);
	placerCaseCocher(c7,139,fenetre);
	placerCaseCocher(c8,157,fenetre);
	placerCaseCocher(c9,200,fenetre);
	placerCaseCocher(c10,218,fenetre);
	placerCaseCocher(c11,237,fenetre);
	placerCaseCocher(c12,255,fenetre);
	placerCaseCocher(c13,274,fenetre);
	placerCaseCocher(c14,292,fenetre);
	placerCaseCocher(c15,311,fenetre);

	placerCaseCocher(c16,329,fenetre);
	placerCaseCocher(c17,348,fenetre);
	placerCaseCocher(c18,394,fenetre);
	placerCaseCocher(c19,412,fenetre);
	placerCaseCocher(c20,430,fenetre);
	placerCaseCocher(c21,448,fenetre);
	placerCaseCocher(c22,466,fenetre);
	placerCaseCocher(c23,484,fenetre);
	placerCaseCocher(c24,502,fenetre);

      //Affichage des changements
      //fenetre.display();
}

/**
* Fonction placerCaseCocher
*/
void ZoneChecklist::placerCaseCocher(Bouton b, int y, sf::RenderWindow &fenetre)
{
    Sprite sp1;

    sp1 = b.getSprite();
    sp1.move(sf::Vector2f(570,y));
    fenetre.draw(sp1);
}


/*
* Fonction update
*/    
void ZoneChecklist::update(Joueur* j, sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    // Interaction avec la checkliste

    cliqueConditionnel(x,y,570,587,28,45,c1);
    cliqueConditionnel(x,y,570,587,46,63,c2);
    cliqueConditionnel(x,y,570,587,65,82,c3);
    cliqueConditionnel(x,y,570,587,83,100,c4);
    cliqueConditionnel(x,y,570,587,102,119,c5);
    cliqueConditionnel(x,y,570,587,120,137,c6);
    cliqueConditionnel(x,y,570,587,139,156,c7);
    cliqueConditionnel(x,y,570,587,157,174,c8);
    cliqueConditionnel(x,y,570,587,200,217,c9);
    cliqueConditionnel(x,y,570,587,218,235,c10);
    cliqueConditionnel(x,y,570,587,237,254,c11);
    cliqueConditionnel(x,y,570,587,255,272,c12);
    cliqueConditionnel(x,y,570,587,274,291,c13);
    cliqueConditionnel(x,y,570,587,292,309,c14);
    cliqueConditionnel(x,y,570,587,311,328,c15);
    cliqueConditionnel(x,y,570,587,329,346,c16);
    cliqueConditionnel(x,y,570,587,348,365,c17);
    cliqueConditionnel(x,y,570,587,394,411,c18);
    cliqueConditionnel(x,y,570,587,412,429,c19);
    cliqueConditionnel(x,y,570,587,430,447,c20);
    cliqueConditionnel(x,y,570,587,448,465,c21);
    cliqueConditionnel(x,y,570,587,466,482,c22);
    cliqueConditionnel(x,y,570,587,484,501,c23);
    cliqueConditionnel(x,y,570,587,502,519,c24);

    actualiserChecklist(j);
}




/**
* Fonction placerCaseCocher
*/
void ZoneChecklist::actualiserChecklist(Joueur* j)
{
    std::vector<bool> liste;

    liste.push_back(c1.getClique());
    liste.push_back(c2.getClique());
    liste.push_back(c3.getClique());
    liste.push_back(c4.getClique());
    liste.push_back(c5.getClique());
    liste.push_back(c6.getClique());
    liste.push_back(c7.getClique());
    liste.push_back(c8.getClique());

    liste.push_back(c9.getClique());
    liste.push_back(c10.getClique());
    liste.push_back(c11.getClique());
    liste.push_back(c12.getClique());
    liste.push_back(c13.getClique());
    liste.push_back(c14.getClique());
    liste.push_back(c15.getClique());
    liste.push_back(c16.getClique());
    liste.push_back(c17.getClique());

    liste.push_back(c18.getClique());
    liste.push_back(c19.getClique());
    liste.push_back(c20.getClique());
    liste.push_back(c21.getClique());
    liste.push_back(c22.getClique());
    liste.push_back(c23.getClique());
    liste.push_back(c24.getClique());    


    j->setChecklist(liste);
    cerr<<"ZoneCheckList::actualiser()"<<endl;

}


/*
* Fonction cliqueConditionnel
* Role : appel la fonction clique du bouton si la souris a clique sur le bouton
*/
void ZoneChecklist::cliqueConditionnel(int x, int y, int xmin, int xmax, int ymin, int ymax, Bouton & b)
{  
    if(xmin<=x && x<=xmax && ymin<=y && y<=ymax)
    {
        b.clique();
    }
}



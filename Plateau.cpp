#include "Plateau.h"

using namespace sf;
using namespace std;

Plateau::Plateau()
{
	//on récupere limage du plateau et on l'affiche
	if(!im.loadFromFile("Donnees/plateaurefait.png")){}
	im.setSmooth(true);
	plateau.setTexture(im);

    //on met les pointeurs vers cases à NULL
    for(int i=0; i<hautPlateau_;i++){
		for(int j=0; j<largPlateau_;j++){
			tab[i][j] = NULL;
		}
	}

    //on initialise notre tableau de case
	initCases();
    cerr<< "Plateau::Creation du plateau"<<endl;
}


/**
 * Renvoi la case du plateau à la position correspondante niveau graphique
 * @param x abscisse
 * @param y ordonnee
 */
Case* Plateau::trouverCase(int x, int y){

    int posX = x-ecartX_;   // x - lecart qu'il y a en haut
    int posY =y-ecartY_;    //y - lecart qu'il ya en bas

    int cptX=0;
    int cptY=0;

    int tmp=1;
    while(posX > tmp*tailleCase_){
        tmp++;
        cptX++;
    }

    tmp=1;
    while(posY > tmp*tailleCase_){
        tmp++;
        cptY++;
    }

    return tab[cptY][cptX];
}


/**
 * Retourne un pointeur vers une case du tableau
 * @param x abscisse
 * @param y ordonnee
 * @return une case en x,y
 */
Case* Plateau::getCase(int x, int y){
    return tab[y][x];
}

/**
 * Pour Case::trouverChemin verifie si on ne depasse pas les bords du tableau
 * @param x abscisse
 * @param y ordonnee
 * @return si la case est valide
 */
bool Plateau::caseValide(int x, int y){
    //verification des positions invalides
    if(x < 0 || y < 0 || x >= largPlateau_ || y >= hautPlateau_)
        return false;
    else
        return true;
}

//Affichage

/**
 * Methode qui affiche l'image du plateau
 * Affichage de l'interface
 * @param window la fenetre de rendu
 **/
void Plateau::afficher(sf::RenderWindow &window){
    //on affiche le plateau
	window.draw(plateau);
}


/**
 * Methode qui affiche la structure du plateau
 * Affichage d'erreur
 */
void Plateau::afficher(){

    cerr<<endl;
	for(int i=0; i<hautPlateau_;i++){

		for(int j=0; j<largPlateau_;j++){
			cerr << tab[i][j]->toString()<<" ";
		}
		cerr <<" " << i << endl;
	}
}



/**
 * Methode qui renvoie si la position de la souris est sur le plateau
 * @param x abscisse
 * @param y ordonnee
 * @return si la position est valide
 */
bool Plateau::positionValide(int x, int y){

    bool valid = true;

    //On test si la souris est bien dans le plateau en x
    if(x < ecartX_ || x> largPlateau_*tailleCase_+ecartX_)
        valid = false;

    //On test si la souris est bien dans le plateau en y
    if(y < ecartY_ || y> hautPlateau_*tailleCase_+ecartY_)
        valid = false;

    return valid;
}

/**
 *************************************************************************************
 **************************Construction du plateau************************************
 *************************************************************************************
 */


/**
 * Va initier le tableau de case
 * Attention pour garder le meme type de creation entre tableau et case on aura les case prenant Case(y,x);
 *
 **/
void Plateau::initCases(){


	/**On definit les cases speciales
     *on place les portes dans le plateau
     **/

    //La cuisine de [0,0] à [5,6] une porte
    Porte *kitchen=new Porte("Kitchen",6,4);

	for(int i=0; i<7;i++){
		for(int j=0; j<6;j++){
			Piece* p= new Piece(i,j,"Kitchen");
			tab[i][j] = p;
			kitchen->ajouterPiece(p);
		}
	}
	tab[6][4] = kitchen;


	//La salle à manger [0,9][7,15] deux portes
	Porte *diningRoom1=new Porte("Dining-room",12,7);
    Porte *diningRoom2;
	for(int i=9; i<16;i++){
		for(int j=0; j<8;j++){
			Piece* p= new Piece(i,j,"Dining-room");
			tab[i][j] = p;
			diningRoom1->ajouterPiece(p);
		}
	}
	tab[12][7] = diningRoom1 ;
    diningRoom2=new Porte(*diningRoom1,15,6);
    tab[15][6] = diningRoom2 ;

    //Le salon [0,19] à [6,24] une porte
    Porte* lounge= new Porte("Lounge",19,6 );
	for(int i=19; i<25;i++){
		for(int j=0; j<7;j++){
			Piece* p= new Piece(i,j,"Lounge");
			tab[i][j] = p;
			lounge->ajouterPiece(p);
		}
	}
	tab[19][6]=lounge;


	//Le hall [9,18] à [14;24] 3 portes
	Porte* hall1=new Porte("Hall",18,11);
	Porte* hall2;
	Porte* hall3;
	//on cree la piece
	for(int i=18; i<25;i++){
		for(int j=9; j<15;j++){
			Piece* p= new Piece(i,j,"Hall");
			tab[i][j] = p;
			hall1->ajouterPiece(p);
		}
	}
	hall2 =new Porte(*hall1, 18,12);
	hall3 =new Porte(*hall1, 20,14);

	tab[18][11]=hall1;
	tab[18][12]=hall2;
	tab[20][14]=hall3;

	//le study [17,21] à [23,24] une porte
	Porte* study = new Porte("Study",21,17);
    for(int i=21; i<25;i++){
		for(int j=17; j<24;j++){
			Piece* p= new Piece(i,j,"Study");
			tab[i][j] = p;
			study->ajouterPiece(p);
		}
	}
	tab[21][17] =study;


	//la library [17,14] à [23,18] 2 portes
	Porte* library1 = new Porte("Library",16,17);
	Porte* library2;

    for(int i=14; i<19;i++){
		for(int j=17; j<24;j++){
			Piece* p= new Piece(i,j,"Library");
			tab[i][j] = p;
			library1->ajouterPiece(p);
		}
	}
	library2 = new Porte(*library1,14,20);

	tab[16][17]=library1;
	tab[14][20]=library2;

	//le game room [18,8] à [23,12] deux portes
	Porte* game1 = new Porte("Billiard-room",9,18);
	Porte* game2;
    for(int i=8; i<13;i++){
		for(int j=18; j<24;j++){
			Piece* p= new Piece(i,j,"Billiard-room");
			tab[i][j] = p;
			game1->ajouterPiece(p);
		}
	}
	game2 = new Porte(*game1,12,22);

	tab[9][18]=game1;
	tab[12][22]=game2;

	//la conservatory [18,0] à [23,5] une porte
	Porte* conservatory = new Porte("Conservatory",5,19);
    for(int i=0; i<6;i++){
		for(int j=18; j<24;j++){
			Piece* p= new Piece(i,j,"Conservatory");
			tab[i][j] = p;
			conservatory->ajouterPiece(p);
		}
	}
	tab[5][19]=conservatory;


	//bedroom [8,2] à [15,7] quatre portes
	Porte* ballroom1=new Porte("Ballroom",5,15);
	Porte* ballroom2;
	Porte* ballroom3;
	Porte* ballroom4;

    for(int i=2; i<8;i++){
		for(int j=8; j<16;j++){
			Piece* p= new Piece(i,j,"Ballroom");
			tab[i][j] = p;
			ballroom1->ajouterPiece(p);
		}
	}
    for(int i=0; i<2;i++){
		for(int j=10; j<14;j++){
			Piece* p= new Piece(i,j,"Ballroom");
			tab[i][j] = p;
			ballroom1->ajouterPiece(p);
		}
	}

	ballroom2 = new Porte(*ballroom1,7,14);
	ballroom3 = new Porte(*ballroom1,7,9);
	ballroom4 = new Porte(*ballroom1,5,8);

	tab[5][15]=ballroom1;
	tab[7][14]=ballroom2;
	tab[7][9]=ballroom3;
	tab[5][8]=ballroom4;

    //La grosse case inutile du milieu [10,10] à [14,16]
    for(int i=10; i<17;i++){
		for(int j=10; j<15;j++){
			creerMur(i,j);
		}
	}
	//Les "murs" cases où on ne peut pas se deplacer
    creerMur(24,8);
    creerMur(24,15);
    creerMur(20,23);
    creerMur(13,23);
    creerMur(18,0);
    creerMur(16,0);
    creerMur(24,8);
    creerMur(7,23);
    creerMur(0,6);
    creerMur(0,7);
    creerMur(0,8);
    creerMur(1,6);
    creerMur(0,15);
    creerMur(0,16);
    creerMur(0,17);
    creerMur(1,17);
    creerMur(8,0);


    //Les cases depassant des pieces
    delete tab[5][18];
	tab[5][18]=new Case(5,18);

	delete tab[9][5];
	tab[9][5]=new Case(9,5);

	delete tab[9][6];
	tab[9][6]=new Case(9,6);

	delete tab[9][7];
	tab[9][7]=new Case(9,7);

	delete tab[14][17];
	tab[14][17]=new Case(14,17);

	delete tab[18][17];
	tab[18][17]=new Case(18,17);


	//On remplit notre tableau à double dimension de case normal pour ce qui reste
	for(int i=0; i<hautPlateau_;i++){       //pour les y

		for(int j=0; j<largPlateau_;j++){   //pour les x
		    if(tab[i][j] == NULL){
                Case* c = new Case(i,j);
                tab[i][j] = c;
		    }
		}
	}

    //Passage secret
    kitchen->setCheminSecret(tab[21][17]);
	study->setCheminSecret(tab[6][4]);

	lounge->setCheminSecret(tab[5][19]);
	conservatory->setCheminSecret(tab[20][6]);

}

/**
 * Methode interne qui cree les murs
 */
void Plateau::creerMur(int a, int b){
    Mur* m= new Mur(a,b);
	tab[m->getY()][m->getX()]= m;
}


/**
 *Destructeur
 */
Plateau::~Plateau(){

    for(int i=0; i<hautPlateau_;i++){       //pour les y

		for(int j=0; j<largPlateau_;j++){   //pour les x

                delete tab[i][j];
                tab[i][j]=NULL;
		}
    }

    cerr<<"Destruction du plateau"<<endl;
}



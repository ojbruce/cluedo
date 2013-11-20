#include "Donnees.h"

using namespace std;


Donnees::Donnees(){

    // Ouverture du fichier contenant les donnees du jeu
    ifstream fichier("Donnees/donnees.txt", ios::in);

    if(fichier)
    {
        string ch1, ch2, ch3, ch4, ligne;
        int i;

        // On passe les premieres lignes de commentaires
        getline(fichier, ligne);
        getline(fichier, ligne);
        getline(fichier, ligne);

        // On initialise le tableau contenant les Cartes du jeu
        for(i=1 ; i<25 ; ++i)
        {
            fichier >> ch1 >> ch2;
            Carte carte(ch1,ch2);
            tabCartes.push_back(carte);
         }

         // On passe les lignes de commentaires
         getline(fichier, ligne);
         getline(fichier, ligne);
         getline(fichier, ligne);
         getline(fichier, ligne);

         // On initialise le tableau de Personnages
         for(i=25 ; i<33 ; ++i)
         {
            fichier >> ch1 >> ch2 >> ch3>>ch4;
            Personnage personnage(ch1+" "+ch2,ch3,ch4);
            tabPersonnages.push_back(personnage);
         }


         // On ferme le fichier
        fichier.close();

        //position des persos
        /*tabPersonnages[0].setPositionDepart(p->getCase(14,0));
        tabPersonnages[1].setPositionDepart(p->getCase(16,24));
        tabPersonnages[2].setPositionDepart(p->getCase(0,17));
        tabPersonnages[3].setPositionDepart(p->getCase(23,6));
        tabPersonnages[4].setPositionDepart(p->getCase(23,19));
        tabPersonnages[5].setPositionDepart(p->getCase(0,7));
        tabPersonnages[6].setPositionDepart(p->getCase(7,24));
        tabPersonnages[7].setPositionDepart(p->getCase(9,0));*/

         cerr << "Donnees:: fin creation" << endl;
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier de donnees." << endl;
    }

}


Donnees::~Donnees()
{
    //dtor
    cerr<<"Donnee::destruction des Donnees"<< endl;
}


Carte* Donnees::getCarte(int ind){
    return &tabCartes[ind];
}

/**
 *Retourne les cartes mysteres
 *
 */
vector<Carte*> Donnees::initCarteMystere(){
    vector<Carte*> res(3);
    srand(time(NULL)); // place le rand à un endroit diferent selon le time

    //0-8 piece
    int indice = rand() % 9;
    res.push_back(&tabCartes[indice]);

    //9-16 persos
    indice = rand() % 8+9;
    res.push_back(&tabCartes[indice]);

    //17-23 armes
    indice = rand() % 7+17;
    res.push_back(&tabCartes[indice]);

    return res;
}

/**
 * Va renvoyer un n nombre de joueur avec des persos aléatoires
 *
 **/
vector<Joueur> Donnees::initJoueur(int n){
    //tableau de joueur à retourner
    vector<Joueur> tabJoueur;
    int i =0;

    cerr << "Donnees::initJoueur" << endl;
    srand(time(NULL));


   do{
       //8 perso max
        int indice = rand() % 8;
        Joueur joueur(&tabPersonnages[indice]);

        if(std::find(tabJoueur.begin(), tabJoueur.end(), joueur) != tabJoueur.end()){
            //tabJoueur contient joueur
        }else{
            tabJoueur.push_back(joueur);
            i++;
        }

    } while(i<n);

    return tabJoueur;
}

void Donnees::positionnerPerso(Plateau* p){

    tabPersonnages[0].setPositionDepart(p->getCase(14,0));
    tabPersonnages[1].setPositionDepart(p->getCase(16,24));
    tabPersonnages[2].setPositionDepart(p->getCase(0,17));
    tabPersonnages[3].setPositionDepart(p->getCase(23,6));
    tabPersonnages[4].setPositionDepart(p->getCase(23,19));
    tabPersonnages[5].setPositionDepart(p->getCase(0,7));
    tabPersonnages[6].setPositionDepart(p->getCase(7,24));
    tabPersonnages[7].setPositionDepart(p->getCase(9,0));

}


/**
 * Methodes qui va distribuer les cartes aux joueurs
 *
 **/
void Donnees::distribuerCarte(vector<Joueur> &lesJoueurs){

    srand(time(NULL));

    vector<int> temoin; //tableau d'int

    for(int i =0; i<24; i++){
        temoin.push_back(i);
    }

    //On initialise une taille et un indice
    int taille = 24;
    int indice;
    int carte;
    unsigned int j =0;

    //Tant qu'il y a des cartes on ajoute
    do{
        indice= rand() % taille;
        carte = temoin[indice];

        Joueur& joueur =lesJoueurs.at(j);

        joueur.ajouterCarteDepart(&tabCartes.at(carte));
        joueur.ajouterCarteVu(&tabCartes.at(carte));

        temoin.erase(temoin.begin() +indice);

        j++;
        taille--;

        if(j == lesJoueurs.size())
            j = 0;

    }while(!temoin.empty());


}


/**
 * Va initier le tableau de case
 * Attention pour garder le meme type de creation entre tableau et case on aura les case prenant Case(y,x);
 *

void initCases(){


    //La cuisine de [0,0] à [5,6] une porte
    Porte *kitchen=new Porte("Cuisine",6,4);
	for(int i=0; i<7;i++){
		for(int j=0; j<6;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			kitchen->ajouterPiece(p);
		}
	}
	tab[6][4] = kitchen;

	//La salle à manger [0,9][7,15] deux portes
	Porte *diningRoom1=new Porte("Salle à manger",12,7);
    Porte *diningRoom2;
	for(int i=9; i<16;i++){
		for(int j=0; j<8;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			diningRoom1->ajouterPiece(p);
		}
	}

	tab[12][7] = diningRoom1 ;
    diningRoom2=new Porte(*diningRoom1,15,6);
    tab[15][6] = diningRoom2 ;

    //Le salon [0,19] à [6,24] une porte
    Porte* lounge= new Porte("Salon",19,6 );
	for(int i=19; i<25;i++){
		for(int j=0; j<7;j++){
			Piece* p= new Piece(i,j);
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
			Piece* p= new Piece(i,j);
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
	Porte* study = new Porte("Le study",21,17);
    for(int i=21; i<25;i++){
		for(int j=17; j<24;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			study->ajouterPiece(p);
		}
	}
	tab[21][17] =study;


	//la library [17,14] à [23,18] 2 portes
	Porte* library1 = new Porte("La bibliothèque",16,17);
	Porte* library2;

    for(int i=14; i<19;i++){
		for(int j=17; j<24;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			library1->ajouterPiece(p);
		}
	}
	library2 = new Porte(*library1,14,20);

	tab[16][17]=library1;
	tab[14][20]=library2;

	//le game room [18,8] à [23,12] deux portes
	Porte* game1 = new Porte("La salle de jeu",9,18);
	Porte* game2;
    for(int i=8; i<13;i++){
		for(int j=18; j<24;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			game1->ajouterPiece(p);
		}
	}
	game2 = new Porte(*game1,12,22);

	tab[9][18]=game1;
	tab[12][22]=game2;

	//la conservatory [18,0] à [23,5] une porte
	Porte* conservatory = new Porte("Salle de bain",5,19);
    for(int i=0; i<6;i++){
		for(int j=18; j<24;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			conservatory->ajouterPiece(p);
		}
	}
	tab[5][19]=conservatory;


	//bedroom [8,2] à [15,7] quatre portes
	Porte* bedroom1=new Porte("Chambre",5,15);
	Porte* bedroom2;
	Porte* bedroom3;
	Porte* bedroom4;

    for(int i=2; i<8;i++){
		for(int j=8; j<16;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			bedroom1->ajouterPiece(p);
		}
	}
    for(int i=0; i<2;i++){
		for(int j=10; j<14;j++){
			Piece* p= new Piece(i,j);
			tab[i][j] = p;
			bedroom1->ajouterPiece(p);
		}
	}

	bedroom2 = new Porte(*bedroom1,7,14);
	bedroom3 = new Porte(*bedroom1,7,9);
	bedroom4 = new Porte(*bedroom1,5,8);

	tab[5][15]=bedroom1;
	tab[7][14]=bedroom2;
	tab[7][9]=bedroom3;
	tab[5][8]=bedroom4;

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
}**/

/**
 * Methode pour creer des murs
 *

void creerMur(int a, int b){
    Mur* m= new Mur(a,b);
	tab[m->getY()][m->getX()]= m;
}**/

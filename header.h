#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct neurone {
    double *valeur;
    char *etiquette;   
};
typedef struct neurone neurone;


struct reseau {
    struct neurone** Reseau; 
    int longueur;
    int largeur;
};
typedef struct reseau reseau;

 struct donnée {
     double *vecteur;
     char* nom;
     double norme;
 };  
 typedef struct donnée donnée;

 struct base_de_données {
     struct donnée* donnée;
     int taille_vecteur;
     int nb_lignes;
     double* moy_vect;
 };
 typedef struct base_de_données base_de_données;


typedef struct bmu{
    int ligne;
    int colonne;
    struct bmu *suivant;
}bmu;

typedef struct liste_bmu{
    int nb;
    //bmu *premier;
    bmu *dernier;
}liste_bmu;



double normalise(double *vect, int distance);
double tire_aleatoirement(double min, double max);
double distance_euclidienne (double *x, double *y, int taille);
base_de_données initialisation_bd();
reseau* initialisation_reseau(base_de_données b);
int* shuffle(int *tab_ind, int taille);
bmu trouver_le_bmu (reseau *r, base_de_données b, int pos );
void apprentissage( base_de_données b, reseau *r, int nb_iteration);
void voisinage(reseau *r,bmu bm, int rayon, double alpha, int pos, base_de_données b);
int calculer_rayon(int iteration, int phase1, int rayon);
void affecte_valeur(reseau *r,bmu bm, int pos, base_de_données b);
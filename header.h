#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct neurone {
    double *valeur;
    char *etiquette; 
    int val[3];  
};
typedef struct neurone neurone;


struct reseau {
    struct neurone** Reseau; 
    int longueur;
    int largeur;
};
typedef struct reseau reseau;

 struct donnee {
     double *vecteur;
     char* nom;
     double norme;
 };  
 typedef struct donnee donnee;

 struct base_de_donnees {
     struct donnee* donnee;
     int taille_vecteur;
     int nb_lignes;
     double* moy_vect;
 };
 typedef struct base_de_donnees base_de_donnees;


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
base_de_donnees initialisation_bd();
reseau* initialisation_reseau(base_de_donnees b);
int* shuffle(int *tab_ind, int taille);
bmu trouver_le_bmu (reseau *r, base_de_donnees b, int pos );
void apprentissage( base_de_donnees b, reseau *r, int nb_iteration);
void voisinage(reseau *r,bmu bm, int rayon, double alpha, int pos, base_de_donnees b);
int calculer_rayon(int iteration, int phase1, int rayon);
void affecte_valeur(reseau *r,bmu bm, int pos, base_de_donnees b);
void affiche_res(reseau *r);
void stat (reseau *r, bmu bm, int pos, base_de_donnees b);
void affecte_valeur_fin(reseau *r,bmu bm, int pos, base_de_donnees b);
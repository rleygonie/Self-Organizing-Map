#include "assert.h"
#include "header.h"
//     
//
//    Dans ce fichier ce trouve toutes les étapes d'initialisation propres au SOM
//
//



base_de_données initialisation_bd(){
    base_de_données b;
    b.nb_lignes=150;
    b.taille_vecteur=4;
    //Allocation de mémoire
    b.donnée=(donnée*) malloc(b.nb_lignes*sizeof(struct base_de_données));
    assert(b.donnée);
    for (int z=0; z <= b.nb_lignes; z++){
        b.donnée[z].vecteur= (double *) malloc( (b.taille_vecteur)*sizeof(double));
        assert(b.donnée[z].vecteur);
        b.donnée[z].nom=(char *) malloc(30 *sizeof(char));
        assert(b.donnée[z].nom);
    }
    //
    //
    //Ouverture du fichier + par ligne, extraire les valeurs, les mettre en type double et les inserer dans la structure bd
    //
    //
    
    FILE *iris;
    iris = fopen("iris.txt" , "r");
    char *str;
    char *delim=",";
    char *token;
    char line[600];
    int j=0;
    char *ptr;
    for (int i = 0; i < b.nb_lignes; ++i)  {
        fgets (line, sizeof line, iris);
        str = line;
        token=strtok(str,delim);
        b.donnée[i].vecteur[j]= strtod(token, &ptr);
        j++;
        while(token!=NULL){
            while(j<b.taille_vecteur){
                token=strtok(NULL,delim);
                b.donnée[i].vecteur[j]=strtod(token,&ptr);
                j++;
                
            }
            //On met les étiquettes 
            token=strtok(NULL,delim);
            b.donnée[i].nom=strcpy(b.donnée[i].nom,token);
            token = NULL;
            j=0;
        
         }
    } 
    fclose(iris);

    //
    //Normalisation
    //

    for (int i=0; i < b.nb_lignes; ++i){
        b.donnée[i].norme=normalise(b.donnée[i].vecteur, b.taille_vecteur);
    }
    for (int i=0; i < b.nb_lignes; ++i){
        for (j = 0; j< (b.taille_vecteur); ++j){
            b.donnée[i].vecteur[j]/=b.donnée[i].norme;
            
        }
    }
   

    // 
    //Calcul du vecteur moyen de la bd
    // 
    
    b.moy_vect = (double*) calloc ((b.taille_vecteur), sizeof(double));
    assert(b.moy_vect);
    for (int j = 0; j< b.taille_vecteur; j++){
        for (int i=0; i < b.nb_lignes; i++){
            b.moy_vect[j]+= b.donnée[i].vecteur[j];
        }
        
        b.moy_vect[j] = b.moy_vect[j] / b.nb_lignes;
    }
   return b;
}



reseau* initialisation_reseau(base_de_données b){
    reseau *r = malloc(sizeof(*r));
    assert(r);
    r->largeur=6;
    r->longueur=10;
    //Allocation de mémoire
    r->Reseau= (neurone **) malloc(r->largeur*r->longueur*sizeof(*r->Reseau));
    assert(r->Reseau);
    for ( int i = 0; i < r->longueur; i++) {
        //for ( int j = 0; j < r.largeur; j++) {
        r->Reseau[i]=(neurone *)malloc(r->largeur*sizeof(*r->Reseau[i]));
        assert(r->Reseau[i]);
       // }
    }
    for ( int i= 0; i < r->longueur; i++) {
        for (int j = 0; j < r->largeur; j++) {
            r->Reseau[i][j].valeur= (double *) malloc( (b.taille_vecteur) *sizeof(*r->Reseau[i][j].valeur));
            assert(r->Reseau[i][j].valeur);
        }
    }
   
    //Initialisation du reseau de neurones en tirant des valeurs alétoirement dans un intervalle proche du vecteur moyen de la bd

   for (int i = 0; i < r->longueur; ++i){
        for (int j= 0; j < r->largeur; ++j){
            for (int z = 0; z < b.taille_vecteur; ++z){
                r->Reseau[i][j].valeur[z]=tire_aleatoirement(-0.02 + b.moy_vect[z], 0.05 + b.moy_vect[z]);
            }
            r->Reseau[i][j].etiquette="*";
        }
    }

    return r;
}
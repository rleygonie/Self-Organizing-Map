#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
   
    base_de_données b;
    b=initialisation_bd();
    reseau *r;
    r=initialisation_reseau(b);
    
    printf("------------------Inititialisation-------------------\n");
    for (int i=0;i<r->largeur;i++){
        for(int j=0; j<r->longueur;j++){
            printf("%s ",r->Reseau[i][j].etiquette);
        }
        printf("\n");
    }
    printf("------------------Apprentissage-------------------\n");
    int iteration_totale =500*b.taille_vecteur; 
    apprentissage(b,r,iteration_totale);
    
    printf("------------------------Fin------------------------\n");
    for (int j=0; j<r->largeur;j++){
        for(int i=0;i<r->longueur;i++){
            printf("%s ",r->Reseau[i][j].etiquette);
        }
        printf("\n");
    }



    return 0;
}



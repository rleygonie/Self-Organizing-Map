#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void foo(int *a) {
    *a = 10;
}
int main(){
   
    base_de_données b;
    b=initialisation_bd();
    reseau *r;
    r=initialisation_reseau(b);
    /*for(int i=0;i<b.nb_lignes;i++){
        printf("%s",b.donnée[i].nom);
    }*/
    printf("------------------Inititialisation-------------------\n");
    for (int i=0;i<r->longueur;i++){
        for(int j=0; j<r->largeur;j++){
            printf("%s ","*");
        }
        printf("\n");
    }
    //printf("%d",somme);
    printf("------------------Apprentissage-------------------\n");
    int iteration_totale =2000; //500*taillevec
    apprentissage(b,r,iteration_totale);
    
    printf("------------------Fin-------------------\n");
    for (int j=0; j<r->largeur;j++){
        for(int i=0;i<r->longueur;i++){
            printf("%s",r->Reseau[i][j].nom);
        }
        printf("\n");
    }



    return 0;
}



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
    apprentissage(b,r,2000);
    //int iteration_total =2000 //500*taillevec
    /*int somme=0;
     for (int i=0;i<r.longueur;i++){
        for(int j=0; j<r.largeur;j++){
            printf("%f %f %f %f\n",r.Reseau[i][j].valeur[0],r.Reseau[i][j].valeur[1],r.Reseau[i][j].valeur[2],r.Reseau[i][j].valeur[3]);
            //somme+=1;
        }
    }
    printf("%d",somme);*/

    return 0;
}



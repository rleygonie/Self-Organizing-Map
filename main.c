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
    affiche_res(r);
    printf("------------------Apprentissage-------------------\n");
    int iteration_totale =500*b.taille_vecteur; 
    apprentissage(b,r,iteration_totale);
    
    printf("------------------------Fin------------------------\n");
    affiche_res(r);



    return 0;
}



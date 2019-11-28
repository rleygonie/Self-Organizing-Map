

#include "header.h"
void apprentissage( base_de_données b, reseau *r, int nb_iteration){
    int *tab_ind;
    tab_ind=(int *) malloc(b.nb_lignes*sizeof(int));
    int rayon;
    bmu bm;
    
    int phase1= nb_iteration/4;
    int phase2= nb_iteration-phase1;
    for (int i = 0; i < b.nb_lignes; i++)
    {
        tab_ind[i]=i;  
    }
    double alpha=0.7;
    printf("1\n");
    for (int j=0; j<phase1;j++){
        tab_ind=shuffle(tab_ind, b.nb_lignes);
        for (int ind=0;ind<150;ind++){
            bm = trouver_le_bmu(r,b,tab_ind[ind]);
            rayon=calculer_rayon(j,phase1,3);
            voisinage(r,bm,rayon,alpha,tab_ind[ind],b);
            affecte_valeur(r,bm,tab_ind[ind],b);
        }
        alpha=alpha*(1-j/phase1);
    }
    
    
    //printf("--------------Phase 2-----------------"); 
    printf("2\n"); 
    alpha=0.07;
    for (int j=0; j<phase2;j++){
        tab_ind=shuffle(tab_ind, b.nb_lignes);
        for (int ind=0;ind<150;ind++){
            bm = trouver_le_bmu(r,b,tab_ind[ind]);
            voisinage(r,bm,1,alpha,tab_ind[ind],b);
            affecte_valeur(r,bm,tab_ind[ind],b);
        }
        alpha=alpha*(1-j/phase1);
        /*for (int j=0; j<r->largeur;j++){
            for(int i=0;i<r->longueur;i++){
                printf("%s",r->Reseau[i][j].nom);
            }
            printf("\n");
        }
        printf("\n\n");*/
    }
    printf("3\n");
    for (int ind=0;ind<150;ind++){
        bm = trouver_le_bmu(r,b,ind);
        affecte_valeur(r,bm,ind,b);
    }


    
    

}


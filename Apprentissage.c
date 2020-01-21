
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
    double alpha_init=0.7;
    double alpha=alpha_init;
    printf("----------------------Phase 1--------------------\n");
    for (int j=0; j<phase1;j++){
        tab_ind=shuffle(tab_ind, b.nb_lignes);
        for (int ind=0;ind<b.nb_lignes;ind++){
            bm = trouver_le_bmu(r,b,tab_ind[ind]);
            rayon=calculer_rayon(j,phase1,3);
            voisinage(r,bm,rayon,alpha,tab_ind[ind],b);
            affecte_valeur(r,bm,tab_ind[ind],b);
        }
        alpha=alpha_init*(1-((double)j/(double)phase1));
        if (j%100==0){
            affiche_res(r);
            printf("_______________________________\n\n");
            
        }
        
    }

    printf("----------------------Phase 2--------------------\n");
    alpha_init=0.07;
    alpha=alpha_init;
    for (int j=0; j<phase2;j++){
        tab_ind=shuffle(tab_ind, b.nb_lignes);
        for (int ind=0;ind<b.nb_lignes;ind++){
            bm = trouver_le_bmu(r,b,tab_ind[ind]);
            voisinage(r,bm,1,alpha,tab_ind[ind],b);
            affecte_valeur(r,bm,tab_ind[ind],b);
        }
        alpha=alpha_init*(1-((double)j/(double)phase2));
        if (j%400==0){
            affiche_res(r);
            printf("_______________________________\n\n");

            
        }
    }

    for (int i=0;i<r->longueur;i++){
        for(int j=0; j<r->largeur;j++){
            r->Reseau[i][j].etiquette="*";
        }
    }
    for (int ind=0;ind<b.nb_lignes;ind++){
        bm = trouver_le_bmu(r,b,ind);
        stat(r,bm,ind,b);
    }
    for (int fi=0;fi<b.nb_lignes;fi++){
        bm=trouver_le_bmu(r,b,fi);
        affecte_valeur_fin(r,bm,fi,b);
    }
}


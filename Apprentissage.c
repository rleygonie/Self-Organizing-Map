

#include "header.h"
void apprentissage( base_de_données b, reseau *r, int nb_iteration){
    int *tab_ind;
    tab_ind=(int *) malloc(b.nb_lignes*sizeof(int));
    bmu bm;
    int rayon;
    int phase1= nb_iteration/4;
    for (int i = 0; i < b.nb_lignes; i++)
    {
        tab_ind[i]=i;
        //printf("%d\n", tab_ind[i]);
    }
    for(int ite=0;ite<nb_iteration; ite++){
        double alpha=0.7;
        for (int j=0; j<phase1;j++){
            // printf("tata");
            tab_ind=shuffle(tab_ind, b.nb_lignes);
            for (int ind=0;ind<150;ind++){
                // printf("indice :%d\n",tab_ind[ind]);
                bm = trouver_le_bmu(r,b,tab_ind[ind]);
                rayon=calculer_rayon(j,phase1,3);
                voisinage(r,bm,rayon,alpha,tab_ind[ind],b);

            // printf("ligne :%d, colonne :%d\n", bm.ligne, bm.colonne);
            }
            alpha=alpha*(1-j/phase1);
        

        }
       
    }
    




}


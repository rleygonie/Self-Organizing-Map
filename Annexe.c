#include "assert.h"
#include "header.h"

//La fonction shuffle prend un tableau d'idice et le mélange alétoirement 
int* shuffle(int *tab_ind, int taille){
    int tmp =0;
    for (int i=0; i<taille;i++){
            int j= rand()%(taille);
            tmp=tab_ind[i];
            tab_ind[i]=tab_ind[j];
            tab_ind[j]=tmp;
            // printf("%d",tab_ind[i]);
        } 
    return tab_ind;
} 

bmu trouver_le_bmu (reseau *r, base_de_données b, int pos ){
    liste_bmu *liste= malloc(sizeof(*liste));
    assert(liste);
    bmu *bm=malloc(sizeof(*bm));
    assert(bm);
    // bmu *dernier=malloc(sizeof(*dernier));
    // bmu *suivant=malloc(sizeof(*suivant));
    bm->colonne=0;
    bm->ligne=0;
    bm->suivant =NULL;
    liste->dernier=NULL;

    double tmp=0.0;
    double distance_min=1.0;

    for( int i=0; i<r->longueur;i++){
        for (int j=0;j<r->largeur;j++){
            tmp=distance_euclidienne(b.donnée[pos].vecteur,r->Reseau[i][j].valeur,b.taille_vecteur);
            //printf("tmp : %f\n",tmp);
            // printf("distance min : %f\n",distance_min);

            if (tmp<distance_min){
                while(bm->suivant){
                    free(bm->suivant);    
                }
                
                free(liste->dernier);
                liste->nb=0;
                distance_min=tmp;
                bm->ligne=i;
                bm->colonne=j;
                // bmu *suivant=malloc(sizeof(*suivant));
                // bmu *dernier=malloc(sizeof(*dernier));
                bm->suivant=NULL;
                liste->dernier=NULL;
                
            }
            else {
                if (tmp==distance_min){
                    bmu *new=malloc(sizeof(*new));
                    assert(new); 
                    while (bm->suivant){
                        bm=bm->suivant;
                    }

                    bm->suivant=liste->dernier;
                    new->ligne=i;
                    new->colonne=j;
                    liste->dernier=new;
                    liste->nb+=1;
                }
            }
        }

    }

    if (liste->nb>1){
        int alea=rand()% liste->nb;
        return bm[alea];
        for (int i=0; i<alea;i++){
            bm=bm->suivant;
        }
        
    }
    return bm[0];
}


void voisinage(reseau *r,bmu bm, int rayon, double alpha, int pos, base_de_données b){
    printf("%d\n",pos);
    // printf("ligne : %d, colonne : %d", bm.ligne,bm.colonne);
    int x_min=bm.ligne-rayon;
    if (x_min<0){
        x_min=0;
    }
    int y_min=bm.colonne-rayon;
    if (y_min<0){
        y_min=0;
    }
    int x_max=bm.ligne+rayon;
    if (x_max>=r->longueur){
        x_max=r->longueur-1;
        //printf("%d \n",x_max);
    }
    int y_max=bm.colonne+rayon;
    if(y_max>=r->largeur){
        y_max=r->largeur-1;
        //printf("%d \n",y_max);
    }

    for(int i=x_min;i<=x_max;i++){
        for(int j=y_min;j<=y_max;j++){
            for(int z=0;z<b.taille_vecteur;z++){
                //printf("%d \n",r.Reseau[i][j]);
                //printf("avant %d: %f\n",z,r.Reseau[i][j].valeur[z]);
                
                //printf("%f\n", r.Reseau[i][j].valeur[z]+alpha*(b.donnée[pos].vecteur[z]-r.Reseau[i][j].valeur[z]));
                //printf("%f + %f * (%f-%f)\n",r->Reseau[i][j].valeur[z],alpha,b.donnée[pos].vecteur[z],r->Reseau[i][j].valeur[z]);
                r->Reseau[i][j].valeur[z]=r->Reseau[i][j].valeur[z]+alpha*(b.donnée[pos].vecteur[z]-r->Reseau[i][j].valeur[z]);
                //printf("apres %d : %f\n",z,r.Reseau[i][j].valeur[z]);
                // printf("%f",b.donnée[pos].vecteur[z]);
            }


        }
        //printf("toto");
    }


}


int calculer_rayon(int iteration, int phase1, int rayon){
    int r;
    double chgmt= phase1/rayon;
    if (iteration<=chgmt){
        r=3;
    }
    else{
        if(iteration>phase1-chgmt){
            r=1;
        }
        else{
            r=2;
        }
    }
    return r;

}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double normalise(double *vect, int distance){
    double norme=0;
    for (int i=0; i < distance-1; ++i){
        norme += pow(vect[i],2);
    }
    norme= sqrt(norme);
    return norme;
}


double tire_aleatoirement(double min, double max){
    return (rand()/ (double) RAND_MAX) * (max-min)+min;
}

    

double distance_euclidienne (double *x, double *y, int taille){
    int i;
    double dist=0.0,z=0.0;
    for ( i = 0; i < taille; ++i){
        z=x[i] -y[i];
        dist = dist + pow(z,2);
    }
    dist= sqrt(dist);
    return dist;
}


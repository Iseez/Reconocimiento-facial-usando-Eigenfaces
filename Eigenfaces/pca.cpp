//
// Created by sebas on 19/11/2019.
//

#include "pca.h"
#include "stdio.h"

Pca::Pca() {

}
Pca::~Pca() {

}

//se invierte la matriz//
void Pca::tras_mat(double **mat, double **tras, int rows, int cols) {
    for (int i = 0; i <cols ; ++i) {
        for (int j = 0; j <rows ; ++j) {
            tras[i][j]=0;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            tras[j][i]=mat[i][j];

        }
    }

}

//se calcula el promedio de los puntos//
void Pca::mean(double **mat, double *mean, int rows, int cols) {
    int n=cols; //2000
    double u;
    //se llena de ceros el vector
    for(int i=0;i<rows;i++){
        mean[i]=0;
    }
    //calcular los promedios
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            mean[i]=mean[i]+mat[i][j];
        }
    }

    for(int i=0;i<rows;i++){
        u=mean[i];
        mean[i]=u/n;
    }
}

//Se calcula la matriz M , es decir, se sustrae el promedio//
void Pca::M(double **mat, double *mean, int rows, int cols, double **M) {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            M[i][j]=0;
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            M[i][j]=(mat[i][j]-mean[i]);
        }
    }
}

//Se calcula la matriz de covarianza M*M_tras//
void Pca::C(double **M, double **tras, int rows, int cols, double **C) {
    for(int i=0;i<cols;i++){
        for(int j=0;j<cols;j++){
            C[i][j]=0;
        }
    }
    for(int i=0;i<cols;i++)
        for(int j=0;j<cols;j++)
            for(int k=0;k<rows;k++){
                C[i][j]+=M[i][k]*tras[k][j];
            }

}

//imprime un vector//
void Pca::printVector(double *vec, int cols) {
    for (int i = 0; i< cols; i++) {
        // Print current element
        printf(" %f ", vec[i]);
    }
}

//impirme una matriz//
void Pca::printMatrix(double **mat,int rows, int cols) {
    for(int i=0; i<rows ; i++){
        for(int j=0; j<cols; j++) {
            printf(" %f ", mat[i][j]);
        }
        printf("\n");
    }

}







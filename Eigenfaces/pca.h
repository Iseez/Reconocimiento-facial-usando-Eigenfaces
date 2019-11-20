//
// Created by sebas on 19/11/2019.
//

#ifndef EIGENFACES_PCA_H
#define EIGENFACES_PCA_H

#endif //EIGENFACES_PCA_H

using namespace std;

class Pca{
    public:
    Pca();
    ~Pca();

    void dat_mat(double **mat,double **tras,int rows, int cols);
    void mean(double **mat,double *mean,int rows,int cols);
    void M(double **mat,double *mean,int rows, int cols,double **M);
    void C(double **M,double **tras, int rows, int cols,double **C);
    void printVector(double *vec,int cols);
    void printMatrix(double **mat,int rows, int cols);
    private:

};

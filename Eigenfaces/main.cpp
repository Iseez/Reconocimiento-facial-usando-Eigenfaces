
#include "reader.h"
#include "pca.h"
#include "eigenv.h"
#include <Eigen/Eigen>
#include <stdio.h>		//for printf
#include <iostream>
#include <stdlib.h>
Reader objReader;
using namespace std;
int main(int argc, char *argv[]) {

    //Lectura del archivo//
    string fileName = "C://Users//sebas//CLionProjects//Eigenfaces//mat_face.csv";
    int rows = objReader.noRows(fileName);
    int cols = objReader.noCols(fileName);
    double **mat = objReader.genMat(fileName, rows, cols); //Esta matriz de lectura es la matriz que contiene las caras (cara por columna)
    // ROWS 16384
    // COLS 99

    //Creación matrices y vectores//
    double **M = new double *[cols];
    double **Mtras = new double *[rows];
    double **C = new double *[cols];
    double **tras_eigen= new double*[cols];
    double **resize = new double*[cols];
    double **tras_resize = new double*[rows];
    double **w = new double*[cols];

    for (int i = 0; i <rows ; ++i) {
        M[i]=new double[rows];
        resize[i]= new double[rows];
    }
    for (int i = 0; i <cols ; ++i) {
        Mtras[i]=new double[cols];
        tras_resize[i]=new double[cols];
        C[i]=new double[cols];
        tras_eigen[i]=new double[cols];
        w[i]=new double[cols];
    }
    double *mean= new double[rows];
///////////////////////////////////////////////////////////////////////////////////////
    int debug=0; //Variable de chequeo

    Pca objPca;
    //objPca.printMatrix(mat,rows,cols); //se imprime la matriz de datos

    objPca.mean(mat, mean, rows, cols);//se crea el vector que almacena los promedios de la matriz mat es de SIZE 16384
    debug++;
    printf("%d\n",debug);
    //objPca.printVector(mean,rows); //se imprime el vector

    //Se crea matriz M//
    objPca.M(mat, mean, rows,cols, M); //La matriz M (se le resta el vector de los promedios) SIZE 16384X99
    debug++;
    printf("%d\n",debug);
    printf("\n");
    //objPca.printMatrix(M,rows,cols);  //se imprime la matriz m

    //Se calcula la matriz de covarianza C
        //se calucla traspuesta de M//
        objPca.tras_mat(M, Mtras, rows, cols); //La traspuesta de m es de SIZE 99X16384
        debug++;
    printf("%d\n",debug);
     //objPca.printMatrix(Mtras,cols,rows);  //se imprime la traspuesta de m

     objPca.C(Mtras, M, rows, cols, C);//SE OBTIENE LA MATRIZ DE COVARIANZA (traspuesta de M por M) SIZE 99X99
    debug++;
    printf("%d\n",debug);
    //objPca.printMatrix(C,cols,cols); // se imprime la matriz C de covarianza

    eigenv objEigenv;

    double **mat_eigen = objEigenv.Eigenvectors(C,cols,cols); //SE CALCULAN LOS EIGENVECTORES DE C Y SE GUARDAN EN MATRIZ DE 99X99
    //objPca.printMatrix(mat_eigen,cols,cols);

    debug++;
    printf("%d\n",debug);
    //se calcula traspuesta de los eigenvectores
    objPca.tras_mat(mat_eigen,tras_eigen,cols,cols);  //SE CREA LA TRASPUESTA DE LOS EIGENVECTORES SIZE 99X99
    debug++;
    printf("%d\n",debug);

    //se ajusta el tamaño de los eigenvectores
    objEigenv.resizing(M,rows,cols,tras_eigen,resize);//Multiplicación de la matriz M por la traspuesta de los eigenvectores SIZE 16384X99
    debug++;
    printf("%d\n",debug);

    //Sacamos traspuesta de resize
    objPca.tras_mat(resize,tras_resize,rows,cols); //LA TRASPUESTA ES DE SIZE 99X16384
    debug++;
    printf("%d\n",debug);

    //Se calucal W , que contiene los pesos que contribuyen a cada imagen
    objEigenv.w(tras_resize,M,rows,cols,w);//La multiplicación de la traspuesta de size por la matriz M    SIZE 99X99
    debug++;
    printf("%d\n",debug);
    objPca.printMatrix(w,cols,cols);

    while(getchar()!='h'){

    }

   return 0;
}
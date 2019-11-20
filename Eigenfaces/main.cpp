
#include "reader.h"
#include "pca.h"
Reader objReader;
using namespace std;

int main(int argc, char *argv[]){
    //Lectura del archivo//
    string fileName =  "C://Users//sebas//Downloads//Reconocimiento-facial-usando-Eigenfaces-master//DevC++//prueba.csv";
    int rows = objReader.noRows(fileName);
    int cols = objReader.noCols(fileName);
    double** mat = objReader.genMat(fileName,rows,cols);
//*******************************************************************************//
    //Creación matrices y vectores//
    double **dat= new double*[cols];
    double **M=new double*[cols];
    double **Mtras=new double*[rows];
    double **C=new double*[cols];
    for (int i=0;i<rows;i++){
        dat[i]=new double[rows];
        M[i]=new double[rows];
        Mtras[i]=new double[rows];
    }
    for (int i=0;i<cols;i++){
        C[i]=new double[cols];
    }
    double *mean=new double[rows];
//******************************************************************************//
    Pca objPca;
    objPca.printMatrix(mat,rows,cols); //se imprime el archivo leido
    //se crea el data matrix//
    objPca.dat_mat(mat,dat,rows,cols);
    int temp=0;
    temp=rows;  //se invierten las columnas por las filas y viceversa
    rows=cols;
    cols=temp;
    objPca.printMatrix(dat,rows,cols); //se imprime la matriz de datos

    //se crea el vector que almacena los promedios//
    objPca.mean(dat,mean,rows,cols);
    objPca.printVector(mean,rows); //se imprime el vector
    //Se crea matriz M//
    objPca.M(dat,mean,rows,cols,M);
    printf("\n");
    objPca.printMatrix(M,rows,cols);  //se imprime la matriz m
    //Se calcula la matriz de covarianza C
        //se calucla traspuesta de M//
        objPca.dat_mat(M,Mtras,rows,cols);
        objPca.printMatrix(Mtras,cols,rows);  //se imprime la traspuesta de m
    objPca.C(M,Mtras,rows,cols,C);
    objPca.printMatrix(C,rows,rows); // se imprime la matriz C de covarianza
}
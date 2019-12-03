//
// Created by sebas on 02/12/2019.
//

#ifndef EIGENFACES_EIGENV_H
#define EIGENFACES_EIGENV_H
class eigenv{
    // Private section
public:
    // Public Declarations
    eigenv();
    ~eigenv();
    double** Eigenvectors(double **mt,int row,int col);
    void resizing(double **mat,int rows, int cols, double **eigen, double **resize);
    void w(double **M,double **face,int rows, int cols,double **w);


protected:
// Protected Declarations
};
#endif //EIGENFACES_EIGENV_H

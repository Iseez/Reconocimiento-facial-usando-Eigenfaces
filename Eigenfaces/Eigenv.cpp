#include "Eigenv.h"
#include <stdio.h>		//for printf
#include <iostream>		//for std::cout, as a replacemente for printf

// Eigen include
#include <Eigen>

Reader::Reader(){
}
Reader::~Reader(){
}
double** Eigenv::Eigenvectors(double **mt,int row,int col){
	double** mat = new double*[row];
	int i,j;
	int col = 3;
	int row = 3;
	/*
	 * The following defines A as a 2x2 matrix, filled with doubles.
	 * That's why it ends with 'd'. If you want to use floats,
	 * use MatrixXf.
	 */
	Eigen::MatrixXd A(row,col);
	for(i=0; i < row; i++){
		for(j=0; j < col; j++){
			A(i,j)=mt[i][j];
		}
	}

	/*
	 * If iostream is used instead of stdio.h, the following line can
	 * replace the last two for's that print the A matrix:
	 */
	//std::cout << "The matrix A is:\n" << A << std::endl << std::endl;


	/*
	 * EigenValues and the components of the EigenVectors are usually
	 * returned as std::complex type.
	 */
	//obtencion de eigenvectores
	/*
	Eigen::EigenSolver<Eigen::MatrixXd> es(A);
	printf("--- Eigenvalues of A:\n");
	for(i=0; i < col; i++){
		printf("\t%d: \t%f\n", i+1,es.eigenvalues()[i].imag());
	}
	printf("\n");
	//======================================================================
	*/
	/*
	 * If iostream is used instead of stdio.h, the following line can
	 * replace the last two for's that print the EigenValues list:
	 */
	//std::cout << "The eigenvalues of A are:\n" << es.eigenvalues().real() << std::endl << std::endl;

	printf("--- Eigenvectors of mt:\n");
	for(i=0; i < row; i++){
		//printf("\t%d:", i+1);
		for(j=0; j < col; j++){
			mat[i][j]=es.eigenvectors().col(i)[j].real();
			//printf("\t %f",es.eigenvectors().col(i)[j].real()); de donde salio
		}
	}
	//printf("\n");
	return mat;
}

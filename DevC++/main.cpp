#include "reader.h"
Reader objReader;

int main(int argc, char *argv[]){
	string fileName = argv[1];//"C:/Users/ACER/Documents/GitHub/Reconocimiento-facial-usando-Eigenfaces/Dataset/faces/eigenfaces.csv";
	int rows = objReader.noRows(fileName);
	int cols = objReader.noCols(fileName);
	double** mat = objReader.genMat(fileName,rows,cols);
	for(int i = 0;i < rows;i++){
		for(int j = 0;j < cols;j++){
			printf("\t%f",mat[i][j]);
		}
		printf("\n");
	}
}

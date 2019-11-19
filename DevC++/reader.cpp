#include "reader.h"
Reader::Reader(){
}
Reader::~Reader(){
}
int Reader::noRows(string name){
	printf("Leyendo:\t%s\n",name.c_str());
	int counter = 0;
	ifstream file(name.c_str());
	string data;
	while(getline(file,name)){
		counter++;
	}
	printf("No. de filas:\t%d\n",counter);
	return counter;
}
int Reader::noCols(string name){
	printf("Leyendo:\t%s\n",name.c_str());
	int counter = 0;
	ifstream file(name.c_str());
	string data;
	getline(file,data);
	stringstream sstream(data);
	while(!sstream.eof()){
		getline(sstream,data,',');
		counter++;
	}
	printf("No. de columnas:\t%d\n",counter);
	return counter;
}
double** Reader::genMat(string name,int rows,int cols){
	double** mat = new double*[rows];
	ifstream file(name.c_str());
	stringstream buffer;
	buffer << file.rdbuf();
	string data;
	for(int i = 0; i<rows;i++){
		mat[i] = new double[cols];
		string temp1;
		getline(buffer,temp1,',');
		data = temp1;
		mat[i][0] = atof(data.c_str());
		for(int j = 1;j<cols;j++){
			if(j == cols-1){
				getline(buffer,data,'\n');
				mat[i][j] = atof(data.c_str());
			}
			else{
				getline(buffer,data,',');
				mat[i][j] = atof(data.c_str());
			}
		}
	}

	return mat;
}


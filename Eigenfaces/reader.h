//
// Created by sebas on 19/11/2019.
//

#ifndef EIGENFACES_READER_H
#define EIGENFACES_READER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;
class Reader
{
public:
    Reader();
    ~Reader();
    int noRows(string name);
    int noCols(string name);
    double** genMat(string name,int rows,int cols);
protected:

};

#endif //EIGENFACES_READER_H
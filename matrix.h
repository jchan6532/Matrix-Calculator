#include <stdlib.h>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix 
{
private:
    int dimension;
    int** elements;

public:
    Matrix(void);
    Matrix(int dimension, int** elements);
    ~Matrix(void);

    void SetDimension(int dimension);
    int GetDimension(void);

    void SetElements(int** elements);
    int** GetElements(void);

    void Show(void);
};

#endif

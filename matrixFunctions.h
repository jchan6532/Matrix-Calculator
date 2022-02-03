#include "matrix.h"
#include "Determinant.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define TWOTOONE 1
#define ONETOTWO 2


void convert(int** doubleArray, int* singleArray, int conversionType, int dimension);
void getInput(char** input);
int findDimension(int strLength);
void showInputMatrix(int* stringInput, int length, int rows, int cols);
int*** calcChildMatrix(int* elements, int dimension);
int CalcSimplestDeterminant(Determinant* current);
int totalMatrices(int dimension);
Matrix* findSpecificMatrix(Matrix* head, int dimension, int i);
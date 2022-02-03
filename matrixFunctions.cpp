#include "matrixFunctions.h"
#pragma warning(disable:4996)

void convert(int** doubleArray, int* singleArray, int conversionType, int dimension) {
	if (conversionType == TWOTOONE) {
		int i, j;
		for (i = 0; i < dimension; i++) {
			for (j = 0; j < dimension; j++) {
				if (singleArray && doubleArray) {
					singleArray[j + i * dimension] = doubleArray[i][j];
				}
			}
		}
	}
	else if (conversionType == ONETOTWO) {
		int i, j;
		for (i = 0; i < dimension; i++) {
			for (j = 0; j < dimension; j++) {
				doubleArray[i][j] = singleArray[j + i * dimension];
			}
		}
	}
	return;
}

void getInput(char** input) {
	int i = 0;
	int size = 2;
	*input = (char*)calloc(2, sizeof(char));
	bool end_found = false;
	char buffer[2];
	if (*input) {
		do {
			char* reallocBlock = NULL;
			fgets(buffer, 2, stdin);
			strcat(*input, buffer);
			size = size + 2;
			for (i = 0; i < 2; i++) {
				if (buffer[i] == '\n') {
					end_found = true;
				}
			}
			if (!end_found) {
				reallocBlock = (char*)realloc(*input, sizeof(char) * size);
				if (reallocBlock) {
					*input = reallocBlock;
				}
			}
		} while (!end_found);
		(*input)[strlen(*input) - 1] = '\0';
	}
	return;
}

int findDimension(int strLength) {
	double number = pow((double)strLength, (1.0 / 2.0));
	return (int)round(number);
}

void showInputMatrix(int* stringInput, int length, int rows, int cols) {
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d\t", stringInput[i * cols + j]);
		}
		printf("\n\n");
	}

	if (length > rows * cols) {
		for (i = 0; i < length - rows * cols; i++) {
			printf("%d\t", stringInput[rows * cols + i]);
		}
	}

	return;
}

int*** calcChildMatrix(int* elements, int dimension) {
	int i, j, k;
	int a, b;
	int cofactorCol = 0;
	int cofactorRow = 0;
	int*** childMatrices = NULL;
	childMatrices = (int***)calloc(dimension, sizeof(int**));

	for (i = 0; i < dimension; i++) {
		if (childMatrices) {
			childMatrices[i] = (int**)calloc(dimension - 1.0, sizeof(int*));
			for (j = 0; j < dimension - 1; j++) {
				if (childMatrices[i]) {
					childMatrices[i][j] = (int*)calloc(dimension - 1.0, sizeof(int));
				}
			}
		}
	}

	bool skipRow = false;
	bool skipCol = false;
	for (i = 0; i < dimension; i++) {
		cofactorCol = i;
		cofactorRow = 0;
		skipCol = false;
		skipRow = false;
		for (j = 0, a = 0; (j < dimension) && (a < dimension - 1); j++, a++) {
			for (k = 0, b = 0; (k < dimension) && (b < dimension - 1); k++, b++) {
				if (j == cofactorRow) {
					skipRow = true;
				}
				if (k == cofactorCol) {
					skipCol = true;
				}

				if (skipCol) {
					k++;
					skipCol = false;
				}
				if (skipRow) {
					j++;
					skipRow = false;
				}
				if (childMatrices && childMatrices[i] && childMatrices[i][a])  {
					childMatrices[i][a][b] = (double)elements[j * dimension + k];
				}
			}
		}
	}

	return childMatrices;
}

int CalcSimplestDeterminant(Determinant* current) {
	if (current->GetDimension() > 2) {
		return 0;
	}
	int result = 0;
	result = current->GetElements()[0][0] * current->GetElements()[1][1] + current->GetElements()[0][1] * current->GetElements()[1][0];
	return result;
}
#include "matrix.h"
#include "Determinant.h"
#include "matrixFunctions.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

using namespace std; 
int main(void) {
	int** elements = new int*[3];
	for (int i = 0; i < 3; i++) {
		elements[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			elements[i][j] = i * 3 + j+1;
		}
	}

	Determinant* myDet = new Determinant(3, elements);
	Determinant* current = myDet;
	myDet->CreateChilds();

	current->Dump();
	current = current->GetChild();

	current->Dump();
	current = current->GetNext();

	current->Dump();
	current = current->GetNext();	

	current->Dump();
	return 0;
}
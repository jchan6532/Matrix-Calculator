#include "Determinant.h"
#include "matrixFunctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

Determinant::Determinant() : Matrix() {
	this->cofactor = 1;
	this->next = NULL;
	this->child = NULL;
	this->parent = NULL;
}

Determinant::Determinant(int cofactor, Determinant* next, Determinant* child, Determinant* parent, int dimension, int** elements) : Matrix(dimension, elements) {
	this->cofactor = cofactor;
	this->child = child;
	this->next = next;
	this->parent = parent;
}

Determinant::Determinant(int dimension, int** elements) : Matrix(dimension, elements) {
	this->cofactor = 1;
	this->child = NULL;
	this->next = NULL;
	this->parent = NULL;
}

Determinant::~Determinant() {
	printf("Determinant delete\n\n");
}

void Determinant::SetCofactor(int cofactor) {
	this->cofactor = cofactor;
	return;
}

int Determinant::GetCofactor() {
	return this->cofactor;
}

void Determinant::SetNext(Determinant* next) {
	this->next = next;
}

Determinant* Determinant::GetNext() {
	return this->next;
}

void Determinant::SetChild(Determinant* child) {
	this->child = child;
}

Determinant* Determinant::GetChild() {
	return this->child;
}

void Determinant::SetParent(Determinant* parent) {
	this->parent = parent;
}
Determinant* Determinant::GetParent() {
	return this->parent;
}

void Determinant::Dump() {
	printf("%-20s %d\n", "Dimension", this->GetDimension());
	printf("%-20s %p\n", "Elements", this->GetElements());
	Matrix::Show();
	printf("%-20s %d\n", "Cofactor", this->cofactor);
	printf("%-20s %p\n", "Next", this->next);
	printf("%-20s %p\n", "Child", this->child);

	printf("\n\n\n");
	return;
}

void Determinant::CreateChilds() {
	int* elements1D = NULL;
	elements1D = (int*)calloc(pow((float)this->GetDimension(), 2), sizeof(int));
	convert(this->GetElements(), elements1D, TWOTOONE, this->GetDimension());

	int*** childs = calcChildMatrix(elements1D, this->GetDimension());
	int** elements = this->GetElements();
	int* childCofactors = (int*)calloc(this->GetDimension(), sizeof(int));
	int i = 0;
	for (i = 0; i < this->GetDimension(); i++) {
		if (childCofactors) {
			childCofactors[i] = elements[0][i];
		}
	}

	if (childCofactors) {
		this->SetChild(new Determinant(childCofactors[0], NULL, NULL, this, this->GetDimension() - 1, childs[0]));
		Determinant* current = this->GetChild();
		for (i = 1; i < this->GetDimension(); i++) {
			current->SetNext(new Determinant(childCofactors[i], NULL, NULL, this,this->GetDimension() - 1, childs[i]));
			current = current->GetNext();
		}
	}
	return;
}
//undone
int Determinant::CalcDeterminant() {
	int result = 0;
	Determinant* current = this->GetSmallestChild();
	if (current) {
		if (current->GetDimension() == 2) {
			int j = 0;
			for (j = 0; j < current->GetParent()->GetDimension(); j++) {
				result = result + current->GetCofactor() * CalcSimplestDeterminant(current);
				current = current->GetNext();
			}
		}
	}
	return result;
}

Determinant* Determinant::GetSmallestChild() {
	Determinant* current = this;
	while (current->GetDimension() > 2) {
		current = current->GetChild();
		if (current->GetDimension() == 2) {
			return current;
		}
	}
	return NULL;
}
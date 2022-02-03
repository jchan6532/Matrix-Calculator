#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

Matrix::Matrix(){
    this->dimension = 2;
    this->elements = (int**)calloc(this->dimension, sizeof(int*));
    if (this->elements) {
        int i;
        bool elementsValid = true;
        for (i = 0; i < this->dimension; i++) {
            this->elements[i] = (int*)calloc(this->dimension, sizeof(int));
            if (!this->elements[i]) {
                elementsValid = false;
            }
        }
        if (elementsValid) {
            this->elements[0][0] = 1;
            this->elements[0][1] = 0;
            this->elements[1][0] = 0;
            this->elements[1][1] = 1;
        }
    }
}

Matrix::Matrix(int dimension, int** elements){
    if(dimension >= 2){
        this->dimension = dimension;
        int i,j;
        this->elements = (int**)calloc(this->dimension, sizeof(int*));
        if (this->elements) {
            for (i = 0; i < this->dimension; i++) {
                this->elements[i] = (int*)calloc(this->dimension, sizeof(int));
            }
            for (i = 0; i < dimension; i++) {
                for (j = 0; j < dimension; j++) {
                    if (this->elements[i] != NULL) {
                        this->elements[i][j] = elements[i][j];
                    }
                }
            }
        }
    }
    else{
        this->dimension = 2;
        this->elements[0][0] = 1;
        this->elements[0][1] = 0;
        this->elements[1][0] = 0;
        this->elements[1][1] = 1;
    }
}

Matrix::~Matrix() {
    printf("Matrix delete\n\n");
}

void Matrix::SetDimension(int dimension){
    if(dimension >= 2){
        this->dimension = dimension;
    }
    return;
}

int Matrix::GetDimension(){
    return this->dimension;
}

void Matrix::SetElements(int** elements){
    int i,j;
    for(i=0;i<this->dimension;i++){
        for(j=0;j<this->dimension;j++){
            this->elements[i][j] = elements[i][j];
        }
    }
    return;
}

int** Matrix::GetElements(){
    int** elementsCpy = (int**)calloc(this->dimension, sizeof(int*));
    int i,j;
    if (elementsCpy) {
        for (i = 0; i < this->dimension; i++) {
            elementsCpy[i] = (int*)calloc(this->dimension, sizeof(int));
            if (elementsCpy[i]) {
                for (j = 0; j < this->dimension; j++) {
                    elementsCpy[i][j] = this->elements[i][j];
                }
            }
        }
    }
    return elementsCpy;
}

void Matrix::Show(){
    int i,j;
    for(i=0;i<this->dimension;i++){
        for(j=0;j<this->dimension;j++){
            printf("%d\t", this->elements[i][j]);
            if(j == this->dimension-1){
                printf("\n\n");
            }
        }
    }
    return;
}

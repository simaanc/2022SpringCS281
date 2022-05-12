//
// Created by Chris Simaan on 5/11/22.
//

#include "SquareMatrix.h"

void SquareMatrix::MakeEmpty(int n) {

    size = n;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}

void SquareMatrix::StoreValue(int i, int j, int value) {
    matrix[i][j] = value;
}

void SquareMatrix::Add(SquareMatrix a,SquareMatrix b)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            b.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
        }
    }
    b.ListMatrix();
}

void SquareMatrix::Subtract(SquareMatrix a, SquareMatrix b) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a.matrix[i][j] = matrix[i][j] - b.matrix[i][j];

    a.ListMatrix();
}

void SquareMatrix::Copy(SquareMatrix a) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = a.matrix[i][j];
        }
    }
}

void SquareMatrix::ListMatrix() {
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;

    }
}
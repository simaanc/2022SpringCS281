//
// Created by Chris Simaan on 5/11/22.
//

#include <iostream>

using namespace std;

class SquareMatrix {
public:
    void MakeEmpty(int n);
    void StoreValue(int i, int j, int value);
    void Add(SquareMatrix a, SquareMatrix b);
    void Subtract(SquareMatrix a, SquareMatrix b);
    void Copy(SquareMatrix a);

    void ListMatrix();
private:
    int size;
    int matrix[50][50];
};

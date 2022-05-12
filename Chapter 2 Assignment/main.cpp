#include <iostream>
#include "SquareMatrix.h"

using namespace std;

int main()
{
    SquareMatrix m1,m2,addMatrix,subMatrix,copyMatrix;
//Empty Matrix Test
    cout<<"Empty Matrix";
    m1.MakeEmpty(5);
    m1.ListMatrix();

    cout<<endl<<"Matrix 1";
// Create M1
    m1.StoreValue(0,1,8);
    m1.StoreValue(0,2,9);
    m1.StoreValue(0,3,4);
    m1.StoreValue(2,1,2);
    m1.StoreValue(2,2,1);
    m1.StoreValue(4,3,5);
    m1.ListMatrix();

//Create M2
    m2.MakeEmpty(5);
    m2.StoreValue(0,0,4);
    m2.StoreValue(0,1,3);
    m2.StoreValue(1,2,6);
    m2.StoreValue(2,3,1);
    m2.StoreValue(2,2,9);
    m2.StoreValue(3,2,2);
    m2.StoreValue(4,0,5);
    m2.StoreValue(5,2,3);
    cout<<endl<<"Matrix 2";
    m2.ListMatrix();

    addMatrix.MakeEmpty(5);
    subMatrix.MakeEmpty(8);
    copyMatrix.MakeEmpty(5);

    cout<<endl<<"Add 2 Matrix";
    m1.Add(m2,m1);

    cout<<endl<<"Subtract 2 Matrix";
    subMatrix.Subtract(m1,m2);

    cout<<endl<<"Copy Matrix 1";
    copyMatrix.Copy(m1);
    copyMatrix.ListMatrix();
    return 0;
}
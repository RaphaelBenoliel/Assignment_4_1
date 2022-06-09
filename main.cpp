#include <iostream>
#include "Set.h"
#include"Date.h"
int main() {
    int sizeA,sizeB,sizeX,sizeY,day, month, year;
    /*float *arrA, *arrB, num;
    cout<<"Enter size of A: ";
    cin>>sizeA;
    arrA = new float[sizeA];
    cout<<"Enter elements of A: ";
    for (int i = 0; i < sizeA; ++i)
        cin>>arrA[i];
    cout<<"Enter size of B: ";
    cin>>sizeB;
    arrB = new float[sizeB];
    cout<<"Enter elements of B: ";
    for (int i = 0; i < sizeB; ++i)
        cin>>arrB[i];
    Set<float>A(arrA,sizeA);
    Set B(arrB, sizeB);
    cout<<"Which number should be added to A?: ";
    cin>>num;
    A += num;
    cout<<"Which number should be removed from B?: ";
    cin>>num;
    B -= num;
    Set Union = A + B;
    Set Diff = A - B;
    cout<<"A=";
    A.printSet();
    cout<<"B=";
    B.printSet();
    cout<<"Union=";
    Union.printSet();
    cout<<"Difference=";
    Diff.printSet();
    */
    cout<<"Enter size of X: ";
    cin>>sizeX;
    Date *arrX = new Date[sizeX];
    cout<<"Enter elements of X: ";
    for (int i = 0; i < sizeX; ++i) {
        cin >> day >> month >> year;
        try {
            arrX[i].setDate(day, month, year);
        }
        catch (const char *msg) {
            cout<<msg<<endl;
            i--;
        }
    }


    return 0;
}

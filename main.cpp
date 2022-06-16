#include <iostream>
#include "Set.h"
#include"Date.h"
template<>int Set<float>::totalSize=0;
template<>int Set<Date>::totalSize=0;

int main() {
    int sizeA, sizeB, sizeX, sizeY, day, month, year;
    float *arrA, *arrB, num;
    /////////////////////////////   FLOAT   ////////////////////////////////////////////////////
    cout << "Enter size of A: ";
    cin >> sizeA;
    arrA = new float[sizeA];
    cout << "Enter elements of A: ";
    for (int i = 0; i < sizeA; ++i)
        cin >> arrA[i];
    cout << "Enter size of B: ";
    cin >> sizeB;
    arrB = new float[sizeB];
    cout << "Enter elements of B: ";
    for (int i = 0; i < sizeB; ++i)
        cin >> arrB[i];
    Set<float> A(arrA, sizeA);
    Set<float> B(arrB, sizeB);
    cout << "Which number should be added to A?: ";
    cin >> num;
    A += num;
    cout << "Which number should be removed from B?: ";
    cin >> num;
    B -= num;
    Set<float> Union = A + B;
    Set<float> Diff = A - B;
    cout << "A=";
    A.printSet();
    cout << "B=";
    B.printSet();
    cout << "Union=";
    Union.printSet();
    cout << "Difference=";
    Diff.printSet();
    cout << "Total size is: " << Set<float>::getStatic() << endl;
    /////////////////////////////   DATE   ////////////////////////////////////////////////////
    cout << "Enter size of X: ";
    cin >> sizeX;
    Date *arrX = new Date[sizeX];
    cout << "Enter elements of X: ";
    for (int i = 0; i < sizeX; ++i) {
        cin >> day >> month >> year;
        try {
            arrX[i].setDate(day, month, year);
        }
        catch (const char *msg) {
            cout << msg << endl;
            i--;
        }
    }
    cout << "Enter size of Y: ";
    cin >> sizeY;
    Date *arrY = new Date[sizeY];
    cout << "Enter elements of Y: ";
    for (int i = 0; i < sizeY; ++i) {
        cin >> day >> month >> year;
        try {
            arrY[i].setDate(day, month, year);
        }
        catch (const char *msg) {
            cout << msg << endl;
            i--;
        }
    }
    Set<Date> X(arrX, sizeX);
    Set<Date> Y(arrY, sizeY);
    Date date;
    bool run = true, flag;
    cout << "Which date should be added to X?: ";
    while (run) {
        flag = false;
        cin >> day >> month >> year;
        try {
            date.setDate(day, month, year);
        }
        catch (const char *msg) {
            cout << msg << endl;
            run = true;
            flag = true;
        }
        if (!flag)
            run = false;
    }
    X += date;
    cout << "Which date should be removed from Y?: ";
    run = true;
    while (run) {
        flag = false;
        cin >> day >> month >> year;
        try {
            date.setDate(day, month, year);
        }
        catch (const char *msg) {
            cout << msg << endl;
            run = true;
            flag = true;
        }
        if (!flag)
            run = false;
    }
    Y -= date;
    Set<Date> UnionD = X + Y;
    Set<Date> DiffD = X - Y;
    cout << "X=";
    X.printSet();
    cout << "Y=";
    Y.printSet();
    cout << "Union=";
    UnionD.printSet();
    cout << "Difference=";
    DiffD.printSet();
    cout << "Total size is: " << Set<Date>::getStatic() << endl;
    return 0;
}
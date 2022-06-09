//
// Created by Raphael Benoliel on 01/06/2022.
//

#ifndef ASSIGNMENT_4_1_SET_H
#define ASSIGNMENT_4_1_SET_H
#include<iostream>
using namespace std;
template<class T>
class Set
{
private:
    T* arr;
    int size;
public:
    Set(T* arr, int size);
    void printSet()const;
    Set &operator+=(const T &val);
    Set &operator-=(const T &val);
    const Set &operator+(const Set& other)const;
    const Set<T> & operator-(const Set& other) const;

};

template<class T>
Set<T>::Set(T *arr, int size) {
    if(size)
    {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; ++i)
            this->arr[i] = arr[i];
    }
    else
    {
        this->size = 0;
        this->arr = nullptr;
    }
}

template<class T>
Set<T> &Set<T>::operator+=(const T &val) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == val)
            return *this;
    T *temp = new T[size + 1];
    if (temp) {
        for (int i = 0; i < size; ++i)
            temp[i] = arr[i];
        temp[size] = val;
        this->size++;
        delete[] arr;
        arr = temp;
    }
    return *this;
}

template<class T>
Set<T> &Set<T>::operator-=(const T &val) {
    for (int i = 0; i < size; ++i) {
        if(arr[i] == val)
        {
            T *temp = new T[size-1];
            for (int j = 0; j < i; ++j)
                temp[j] = arr[j];
            for (int k = i; k < size; ++k)
                temp[k] = arr[k+1];
            size--;
            delete[] arr;
            arr = temp;
            return *this;
        }
    }
    return *this;
}

template<class T>
const Set<T> & Set<T>::operator+(const Set &other) const {
    int newSize = size;
    bool flag = false;
    T *newArr = new T[newSize];
    for (int i = 0; i < size; ++i)
        newArr[i]= arr[i];
    for (int i = 0; i < other.size; ++i) {
        flag = false;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == other.arr[i])
                flag = true;
        }
        if(!flag){
            T* temp = new T[newSize+1];
            for (int j = 0; j < newSize; ++j)
                temp[j] = newArr[j];
            temp[newSize] = other.arr[i];
            newSize++;
            delete[] newArr;
            newArr = temp;
        }
    }
    return Set(newArr,newSize);
}

template<class T>
const Set<T> & Set<T>::operator-(const Set &other) const {
    int newSize = size, k = 0;
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < other.size; ++j) {
            if(arr[i] == other.arr[j])
                newSize--;
        }
    }
    T *newArr = new T[newSize];
    for (int i = 0; i < size; ++i) {
        flag = false;
        for (int j = 0; j < other.size; ++j)
        {
            if(arr[i] == other.arr[i])
                flag = true;
        }
        if(!flag || k == newSize) {
            newArr[k] = arr[i];
            k++;
        }
    }
    return Set(newArr,newSize);
}

template<class T>
void Set<T>::printSet() const {
    cout<<"{";
    for (int i = 0; i < size; ++i) {
        if(i != size - 1)
            cout<<arr[i]<<", ";
        else
            cout<<arr[i]<<"}"<<endl;
    }
}

#endif //ASSIGNMENT_4_1_SET_H

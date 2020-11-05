//
//  sorts.h
//  act 1.2
//
//  Created by Manolo Medina on 9/9/20.
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#ifndef sorts_h
#define sorts_h
#include <vector>

using namespace std;

template <class T>
class Sorts {
private:
    void swap(vector<T>&, int, int);
    void copyArray(vector<T>&, vector<T>&, int, int);
    void mergeArray(vector<T>&, vector<T>&, int, int, int);
    void mergeSplit(vector<T>&, vector<T>&, int, int);
public:
  //vector<T> ordenaSeleccion(vector<T>&);
  vector<T> ordenaSeleccion(vector<T>&);
  vector<T> ordenaBurbuja(vector<T>&);
  vector<T> ordenaMerge(vector<T>&);
  int busqSecuencial(vector<T>&, int);
  int busqBinaria(vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &v) {
    for (long int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &v) {
    int posicion;

    for (int i=0; i < v.size(); i++) {
        posicion = i;
        for (int j = i; j < v.size(); j++) {
            if (v[j] <= v[posicion]) {
                posicion = j;
            }
        }

        if (posicion != i) {
            swap(v, i, posicion);
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &v) {
    vector<T> temp(v.size());

    mergeSplit(v, temp, 0, v.size() - 1);
    return v;
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    int mid;

    if ( (high - low) < 1 ) {
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid &&j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int num) {

    for (int i = 0; i < v.size(); i++) {
        if (num == v[i]) {
            return i;
        }
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int num) {

    int mid;
    int down = 0;
    int top = v.size() - 1;

    while (down < top) {
        mid = (top + down) / 2;
        if (num == v[mid]) {
            return mid;
        } else if (num < v[mid]) {
            top = mid - 1;
        } else if (num > v[mid]) {
            down = mid + 1;
        }
    }
    return down;
}


#endif /* sorts_h */

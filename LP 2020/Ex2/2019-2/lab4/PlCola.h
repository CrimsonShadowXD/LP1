/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlCola.h
 * Author: crimson
 *
 * Created on July 15, 2020, 10:03 AM
 */

#ifndef PLCOLA_H
#define PLCOLA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlNodoCola.h"

using namespace std;

template <typename T>
class PlCola {
private:
    class PlNodoCola<T>*primer, *ultimo;
public:
    PlCola();
    virtual ~PlCola();
    void crear(ifstream&);
    void insertar(const T&);
    void imprimir(ofstream&);
    T Pop();
    bool vacia();
};

template <typename T>
PlCola<T>::PlCola() {
    primer = NULL;
    ultimo = NULL;
}

template <typename T>
PlCola<T>::~PlCola() {

}

template <typename T>
void PlCola<T>::crear(ifstream&in) {
    while (1) {
        T dato;
        in>>dato;
        if (in.eof())break;
        insertar(dato);
    }
}

template <typename T>
void PlCola<T>::insertar(const T& dato) {
    class PlNodoCola<T> *nuevo;
    nuevo = new class PlNodoCola<T>;
    nuevo->dato = dato;
    if (ultimo != NULL)
        ultimo->sig = nuevo;
    if (primer == NULL)
        primer = nuevo;
    ultimo = nuevo;
}

template <typename T>
void PlCola<T>::imprimir(ofstream&out) {
    class PlNodoCola<T> *p = primer;
    while (p) {
        out << p->dato << endl;
        p = p->sig;
    }
    out << endl;
}

template <typename T>
T PlCola<T>::Pop() {
    class PlNodoCola<T>*p;
    T v;
    p = primer;
    if (!p)return 0;
    primer = p->sig;
    v = p->dato;
    delete p;
    if (!primer)ultimo = NULL;
    return v;
}

template <typename T>
bool PlCola<T>::vacia() {
    return (primer == NULL);
}


#endif /* PLCOLA_H */


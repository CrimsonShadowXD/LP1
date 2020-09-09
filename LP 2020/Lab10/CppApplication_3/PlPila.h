/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlPila.h
 * Author: crimson
 *
 * Created on July 15, 2020, 8:31 PM
 */

#ifndef PLPILA_H
#define PLPILA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlNodoPila.h"
using namespace std;

template <typename T>
class PlPila {
private:
    class PlNodoPila<T>*top;
public:
    PlPila();
    virtual ~PlPila();
    void crear(ifstream&);
    void insertar(const T&);
    void imprimir(ofstream&);
    T Desapilar();
    bool vacia();
};

template <typename T>
PlPila<T>::PlPila() {
    top = NULL;
}

template <typename T>
PlPila<T>::~PlPila() {

}

template <typename T>
void PlPila<T>::crear(ifstream&in) {
        T dato;
        in>>dato;
        insertar(dato);
}

template <typename T>
void PlPila<T>::insertar(const T& dato) {
    class PlNodoPila<T> *nuevo;
    nuevo = new class PlNodoPila<T>;
    nuevo->dato = dato;
    nuevo->sig = top;
    top = nuevo;
}

template <typename T>
void PlPila<T>::imprimir(ofstream&out) {
    class PlNodoPila<T> *p = top;
    while (p) {
        out << p->dato << endl;
        p = p->sig;
    }
    out << endl;
}

template <typename T>
T PlPila<T>::Desapilar() {
    class PlNodoPila<T>*p;
    T v;
    p = top;
    if (!p)return v;
    top = p->sig;
    v = p->dato;
    delete p;
    return v;
}

template <typename T>
bool PlPila<T>::vacia() {
    return (top == NULL);
}


#endif /* PLPILA_H */


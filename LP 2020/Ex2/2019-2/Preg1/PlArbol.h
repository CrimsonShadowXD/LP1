/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlArbol.h
 * Author: crimson
 *
 * Created on July 20, 2020, 5:29 PM
 */

#ifndef PLARBOL_H
#define PLARBOL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlNodoArbol.h"
using namespace std;

template <typename T>
class PlArbol {
private:
    class PlNodoArbol<T>*inicio;
    void insertar(PlNodoArbol<T> *&, const T&);
    void imprimeNodo(PlNodoArbol<T>*, ofstream&);
    void eliminarNodo(PlNodoArbol<T>*);
    T extraerDato(PlNodoArbol<T>*, const T&);
    void modificarNodo(PlNodoArbol<T>*&, const T&);
public:
    PlArbol();
    virtual ~PlArbol();
    void crear(ifstream&);
    void imprimir(ofstream&);
    T buscarDato(const T&);
    void modificar(const T&);
    bool vacia();
};

template <typename T>
PlArbol<T>::PlArbol() {
    inicio = NULL;
}

template <typename T>
PlArbol<T>::~PlArbol() {
    eliminarNodo(inicio);
    inicio = NULL;
}

template <typename T>
void PlArbol<T>::crear(ifstream&in) {
    while (1) {
        T dato;
        in>>dato;
        if (in.eof())break;
        insertar(inicio, dato);
    }
}

template <typename T>
void PlArbol<T>::insertar(PlNodoArbol<T> *&nodo, const T& dato) {
    class PlNodoArbol<T> *nuevo;
    if (nodo == NULL) {
        nuevo = new class PlNodoArbol<T>;
        nuevo->dato = dato;
        nodo = nuevo;
    } else {
        if (nodo->dato > dato)
            insertar(nodo->izq, dato);
        else
            insertar(nodo->der, dato);
    }
}

template <typename T>
void PlArbol<T>::imprimeNodo(PlNodoArbol<T> *nodo, ofstream&out) {
    if (nodo == NULL)return;
    imprimeNodo(nodo->izq, out);
    out << nodo->dato << endl;
    imprimeNodo(nodo->der, out);
}

template <typename T>
void PlArbol<T>::imprimir(ofstream&out) {
    imprimeNodo(inicio, out);
}

template <typename T>
void PlArbol<T>::eliminarNodo(PlNodoArbol<T>*nodo) {
    if (nodo == NULL)return;
    eliminarNodo(nodo->izq);
    class PlNodoArbol<T> *aux;
    aux = nodo->der;
    delete nodo;
    eliminarNodo(aux);
}

template <typename T>
T PlArbol<T>::buscarDato(const T& dato) {
    class PlNodoArbol<T>*p;
    T v;
    v = extraerDato(inicio, dato);
    return v;
}

template <typename T>
T PlArbol<T>::extraerDato(PlNodoArbol<T>*nodo, const T& dato) {
    //    class PlNodoArbol<T>*p;
    T v;
    if (!nodo)return v;
    if (nodo->dato == dato) {
        v = nodo->dato;
    } else if (nodo->dato > dato) {
        v = extraerDato(nodo->izq, dato);
    } else if (nodo->dato < dato) {
        v = extraerDato(nodo->der, dato);
    }
    return v;
}

template <typename T>
void PlArbol<T>::modificarNodo(PlNodoArbol<T>*& nodo, const T& dato) {
    if (!nodo)return;
    if (nodo->dato == dato) {
        nodo->dato = dato;
    } else if (nodo->dato > dato) {
        modificarNodo(nodo->izq, dato);
    } else if (nodo->dato < dato) {
        modificarNodo(nodo->der, dato);
    }
}

template <typename T>
void PlArbol<T>::modificar(const T& dato) {
    modificarNodo(inicio, dato);
}

template <typename T>
bool PlArbol<T>::vacia() {
    return (inicio == NULL);
}


#endif /* PLARBOL_H */


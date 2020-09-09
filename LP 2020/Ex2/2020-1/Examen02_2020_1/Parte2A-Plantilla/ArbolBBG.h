/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBBG.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:17 AM
 */

#ifndef ARBOLBBG_H
#define ARBOLBBG_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "NodoArbolBBG.h"
using namespace std;

template <typename T>
class ArbolBBG {
private:
    class NodoArbolBBG<T>*inicio;
    void insertar(NodoArbolBBG<T> *&, const T&);
    void imprimeNodo(NodoArbolBBG<T>*, ofstream&);
    void eliminarNodo(NodoArbolBBG<T>*);
    void modificarNodo(NodoArbolBBG<T>*&,int,float);
public:
    ArbolBBG();
    virtual ~ArbolBBG();
    void crear(ifstream&);
    void imprimir(ofstream&);
    void modificar(int,float);
    bool vacia();
};

template <typename T>
ArbolBBG<T>::ArbolBBG() {
    inicio = NULL;
}

template <typename T>
ArbolBBG<T>::~ArbolBBG() {
    eliminarNodo(inicio);
    inicio = NULL;
}

template <typename T>
void ArbolBBG<T>::crear(ifstream&in) {
    while (1) {
        T dato;
        in>>dato;
        if (in.eof())break;
        insertar(inicio, dato);
    }
}

template <typename T>
void ArbolBBG<T>::insertar(NodoArbolBBG<T> *&nodo, const T& dato) {
    class NodoArbolBBG<T> *nuevo;
    if (nodo == NULL) {
        nuevo = new class NodoArbolBBG<T>;
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
void ArbolBBG<T>::imprimeNodo(NodoArbolBBG<T> *nodo, ofstream&out) {
    if (nodo == NULL)return;
    imprimeNodo(nodo->izq, out);
    out << nodo->dato << endl;
    imprimeNodo(nodo->der, out);
}

template <typename T>
void ArbolBBG<T>::imprimir(ofstream&out) {
    imprimeNodo(inicio, out);
}

template <typename T>
void ArbolBBG<T>::eliminarNodo(NodoArbolBBG<T>*nodo) {
    if (nodo == NULL)return;
    eliminarNodo(nodo->izq);
    class NodoArbolBBG<T> *aux;
    aux = nodo->der;
    delete nodo;
    eliminarNodo(aux);
}

template <typename T>
void ArbolBBG<T>::modificarNodo(NodoArbolBBG<T>*& nodo, int dato,float valorPF) {
    if (!nodo)return;
    if (nodo->dato == dato) {
        nodo->dato += valorPF;
    } else if (nodo->dato > dato) {
        modificarNodo(nodo->izq, dato,valorPF);
    } else if (nodo->dato < dato) {
        modificarNodo(nodo->der, dato,valorPF);
    }
}

template <typename T>
void ArbolBBG<T>::modificar(int dato,float valorPF) {
    modificarNodo(inicio, dato,valorPF);
}

template <typename T>
bool ArbolBBG<T>::vacia() {
    return (inicio == NULL);
} 

#endif /* ARBOLBBG_H */


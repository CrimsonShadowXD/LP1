/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.h
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 10:35 AM
 */

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class ArbolBinario {
private:
    class Nodo<T> *raiz;
    
    void inorden(Nodo<T> *raiz, ofstream &arch);
    void insertar(Nodo<T> *&nodo, T &dato);
public:
    ArbolBinario();
    void insertar(T &);
    void crear(ifstream &);
    void imprimir(ofstream &);

};

template <typename T>
ArbolBinario<T>::ArbolBinario(){
    raiz = NULL;
}

template <typename T>
void ArbolBinario<T>::crear(ifstream &arch){
    T dato;
    while(!arch.eof()){
        arch >> dato;
        arch.ignore(1000, '\n'); //Ignoramos si qedo algo en el archivo
        insertar(dato);
        arch >> ws;
    }
}


template <typename T>
void ArbolBinario<T>::insertar(T& dato){
    insertar(raiz, dato);
}

template <typename T>
void ArbolBinario<T>::insertar(Nodo<T>*& nodo, T& dato){
    if(nodo==NULL){ //Se lelgo a la hoja
        nodo = new Nodo<T>;
        nodo->dato = dato;
    }else{
        if (dato< nodo->dato) insertar(nodo->izq, dato);
        else insertar(nodo->der, dato);
    }
}


template <typename T>
void ArbolBinario<T>::imprimir(ofstream &arch){
    inorden(raiz, arch);
}

template <typename T>
void ArbolBinario<T>::inorden(Nodo<T>* nodo, ofstream& arch){
    if(nodo==NULL) return;
    inorden(nodo->izq, arch);
    arch << nodo->dato;
    arch << endl;
    inorden(nodo->der, arch);
}
#endif /* ARBOLBINARIO_H */


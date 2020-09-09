/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlLista.h
 * Author: crimson
 *
 * Created on July 15, 2020, 6:47 PM
 */

#ifndef PLLISTA_H
#define PLLISTA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlNodoLista.h"
using namespace std;

template <typename T>
class PlLista {
private:
    class PlNodoLista<T>*inicio;
public:
    PlLista();
    virtual ~PlLista();
    void crear(ifstream&);
    void insertar(const T&);
    void imprimir(ofstream&);
    int tamano();
    T DevolverNValor(int);
};

template <typename T>
PlLista<T>::PlLista() {
    inicio = NULL;
}

template <typename T>
PlLista<T>::~PlLista() {

}

template <typename T>
void PlLista<T>::crear(ifstream&in) {
    
        T dato;
        in>>dato;
        insertar(dato);
    
}

template <typename T>
void PlLista<T>::insertar(const T& dato) {
    class PlNodoLista<T> *nuevo,*ant,*p;
    nuevo = new class PlNodoLista<T>;
    nuevo->dato = dato;
    ant=NULL;
    p=inicio;
    while(p){
        if(p->dato > nuevo->dato)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant)ant->sig=nuevo;
    else inicio=nuevo;
}

template <typename T>
void PlLista<T>::imprimir(ofstream&out) {
    class PlNodoLista<T> *p = inicio;
    while (p) {
        out << p->dato << endl;
        p = p->sig;
    }
    out << endl;
}

template <typename T>
int PlLista<T>::tamano(){
    int contador=0;
    class PlNodoLista<T> *p = inicio;
    while (p) {
        contador++;
        p = p->sig;
    }
    return contador;
}

template <typename T>
T PlLista<T>::DevolverNValor(int n){
    class PlNodoLista<T> *p = inicio;
    int ind=0;
    T v;
    while(ind<n && p){
        ind++;
        p = p->sig;        
    }
    if (!p)return v;
    v=p->dato;
    return v;
}




#endif /* PLLISTA_H */


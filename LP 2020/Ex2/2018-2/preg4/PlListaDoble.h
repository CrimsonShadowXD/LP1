/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlListaDoble.h
 * Author: crimson
 *
 * Created on July 20, 2020, 7:07 AM
 */

#ifndef PLLISTADOBLE_H
#define PLLISTADOBLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "PlNodoListaDoble.h"
using namespace std;

template <typename T>
class PlListaDoble {
private:
    class PlNodoListaDoble<T>*inicio,*ultimo;
public:
    PlListaDoble();
    virtual ~PlListaDoble();
    void crear(ifstream&);
    void insertar(const T&);
    void imprimir(ofstream&);
    void imprimirRev(ofstream&);
    void imprimirOrden(ofstream&,int);
    int tamano();
    T DevolverNValor(int);
    double buscarMonto(int);
};

template <typename T>
PlListaDoble<T>::PlListaDoble() {
    inicio = NULL;
    ultimo = NULL;
}

template <typename T>
PlListaDoble<T>::~PlListaDoble() {

}

template <typename T>
void PlListaDoble<T>::crear(ifstream&in) {
    while(1){
        T dato;
        in>>dato;
        if(in.eof())break;
        insertar(dato);
    }
}

template <typename T>
void PlListaDoble<T>::insertar(const T& dato) {
    class PlNodoListaDoble<T> *nuevo, *ant, *p;
    nuevo = new class PlNodoListaDoble<T>;
    nuevo->dato = dato;
    ant = NULL;
    p = inicio;
    while (p) {
        if (p->dato > dato)break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    nuevo->ant = ant;
    if(p) p->ant=nuevo;
    else ultimo=nuevo;
    if (ant)ant->sig = nuevo;
    else inicio = nuevo;
}

template <typename T>
void PlListaDoble<T>::imprimir(ofstream&out) {
    class PlNodoListaDoble<T> *p = inicio;
    while (p) {
        out << p->dato << endl;
        p = p->sig;
    }
    out << endl;
}

template <typename T>
int PlListaDoble<T>::tamano() {
    int contador = 0;
    class PlNodoListaDoble<T> *p = inicio;
    while (p) {
        contador++;
        p = p->sig;
    }
    return contador;
}

template <typename T>
T PlListaDoble<T>::DevolverNValor(int n) {
    class PlNodoListaDoble<T> *p = inicio;
    int ind = 0;
    T v;
    while (ind < n && p) {
        ind++;
        p = p->sig;
    }
    if (!p)return v;
    v = p->dato;
    return v;
}
template <typename T>
void PlListaDoble<T>::imprimirRev(ofstream&out){
    class PlNodoListaDoble<T> *p = ultimo;
    while (p) {
        out << p->dato << endl;
        p = p->ant;
    }
    out << endl;
}

template <typename T>
void PlListaDoble<T>::imprimirOrden(ofstream&out,int orden){
    if(orden>0){
        imprimirRev(out);
    }
    else{
        imprimir(out);
    }
}

template <typename T>
double PlListaDoble<T>::buscarMonto(int v){
    class PlNodoListaDoble<T> *p = inicio;
    while (p) {
        if(p->dato==v){
            return ++p->dato;
        }
        p = p->ant;
    }
    return -1;
}


#endif /* PLLISTADOBLE_H */


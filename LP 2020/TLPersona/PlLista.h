/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlLista.h
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 11:01 AM
 */

#ifndef PLLISTA_H
#define PLLISTA_H
#include <fstream>
#include <iostream>
#include "PlNodo.h"


using namespace std;

template <typename T>
class PlLista {
public:
    PlLista();
    virtual ~PlLista();
    void inserta(const T&);
    void quita(T&);
    int vacia(void);
    void mostrar(ofstream &);
private:
    class PlNodo<T>*ini;
};

template <typename T>
PlLista<T>::PlLista(){
   ini = NULL;
}

template <typename T>
PlLista<T>::~PlLista(){
    
}

template <typename T>
void PlLista<T>::inserta(const T &c){
    PlNodo<T> *nuevo;
    PlNodo<T> *p=ini,*ant=NULL; 
    
    nuevo = new PlNodo<T>;
    nuevo ->dato = c;
   
    while(p){
        if(p->dato >  c) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if(ant) ant->sig = nuevo;
    else
        ini = nuevo;
}

template <typename T>
void PlLista<T>::quita(T& c){
    PlNodo<T> *sale;
    c = ini->dato;
    sale = ini;
    ini = ini ->sig;
    delete sale;

}

template <typename T>
void PlLista<T>::mostrar(ofstream &arch){
    PlNodo<T> *p = ini;
    while(p){
        arch << p->dato;
        arch << endl;
        p = p->sig;
    }
    
}

template <typename T>
int PlLista<T>::vacia(){
    return !(ini==NULL);
}


#endif /* PLLISTA_H */


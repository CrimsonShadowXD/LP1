/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaPrioridad.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:33 AM
 */
//20150008 Daniela Cisneros
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Nodo.h"
using namespace std;

template <typename T> 
class ColaPrioridad {
public:
    ColaPrioridad();
    ColaPrioridad(const ColaPrioridad& orig);
  
    void Arribo(T&);
    void Atencion(T&);
    void Listado(ostream &);
private:
    class Nodo<T> * frente;
    class Nodo<T> * final;
};

#endif /* COLAPRIORIDAD_H */

template <typename T> 
ColaPrioridad<T>::ColaPrioridad(){
    frente=NULL;
    final=NULL;
}
template <typename T> 
void ColaPrioridad<T>::Arribo(T& dato){
    class Nodo<T> *p=frente, *ant=NULL,* nuevo;
    nuevo = new  Nodo<T>;
    nuevo->dato=dato;
    while(p){
        if(p->dato>dato) break;
        ant=p;
        p=p->siguiente;
    }
    nuevo->siguiente=p;
    if(ant !=NULL){
        ant->siguiente=nuevo;
    }
    else frente=nuevo;
   
    if(p==NULL) final=nuevo;
}
template <typename T> 
void ColaPrioridad<T>::Atencion(T& dato){
    if(frente){
        dato = frente->dato;
        frente=frente->siguiente;
    }
}
template <typename T> 
void ColaPrioridad<T>::Listado(ostream& arch){
     class Nodo<T> *p=frente;
     arch<<setw(30)<<"LISTADO DE DATOS"<<endl;
     while(p){
        arch<<p->dato;
        p=p->siguiente;
    }
}
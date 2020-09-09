/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlCola.h
 * Author: crimson
 *
 * Created on July 8, 2020, 8:46 PM
 */

#ifndef PLCOLA_H
#define PLCOLA_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "NodoCola.h"

using namespace std;

template <typename T>
class PlCola{
    private:
        class NodoCola<T>*primer,*ultimo;
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
PlCola<T>::PlCola(){
    primer = nullptr;
    ultimo = nullptr;
}

template <typename T>
PlCola<T>::~PlCola(){
    
}

template <typename T>
void PlCola<T>::crear(ifstream&in){
    
    T dato;
    in>>dato;
    insertar(dato);
}


template <typename T>
void PlCola<T>::insertar(const T& dato){
    class NodoCola<T> *nuevo;
    nuevo=new class NodoCola<T>;
    nuevo->dato=dato;
    if(ultimo != nullptr)
        ultimo->sig=nuevo;
    if(primer == nullptr)
        primer=nuevo;
    ultimo=nuevo;    
}

template <typename T>
void PlCola<T>::imprimir(ofstream&out){
    class NodoCola<T> *p=primer;
    while(p){
        out<<p->dato<<endl;
        p=p->sig;
    }
    out<<endl;
}

template <typename T>
T PlCola<T>::Pop(){
    class NodoCola<T>*p;
    T v;
    p=primer;
    if(!p)return v;
    primer=p->sig;
    v=p->dato;
    delete p;
    if(!primer)ultimo = nullptr;
    return v;
}

template <typename T>
bool PlCola<T>::vacia(){
    return (primer == nullptr);
}

#endif /* PLCOLA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlCola.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 08:04 AM
 */

#ifndef PLCOLA_H
#define PLCOLA_H
#include <fstream>

#include "PlNodoCola.h"

using namespace std;
template <typename T>
class PlCola {
public:
    PlCola(){
      primer=NULL;
      ultimo=NULL;
    };
    void crearCola(ifstream&);
    void imprimirCola(ofstream&);
    void anadir(T v);
    T leer();
    
private:
    PlNodoCola<T>*primer,*ultimo;
};

template <typename T>
void PlCola<T>::crearCola(ifstream&archIn){
    T dato;
    while(1){
        archIn>>dato;
        if(archIn.eof())break;
        anadir(dato);
    }
}

template <typename T>
void PlCola<T>::anadir(T v){
    PlNodoCola<T>*nuevo;
    nuevo=new PlNodoCola<T>;
    nuevo->dato=v;
    
    if(ultimo)ultimo->sig=nuevo;
    ultimo=nuevo;
    if(!primer)primer=nuevo;
}

template <typename T>
void PlCola<T>::imprimirCola(ofstream&archOut){
    class PlNodoCola<T>*p=primer;
    while(p){
        archOut<<p->dato;
        archOut<<endl;
        p=p->sig;
    }
}

template <typename T>
T PlCola<T>::leer(){
    class PlNodoCola<T>*p;
    T v;
    p=primer;
    if(!p)return 0;
    primer=p->sig;
    v=p->dato;
    delete p;
    if(!primer)ultimo=NULL;
    return v;
}


#endif /* PLCOLA_H */


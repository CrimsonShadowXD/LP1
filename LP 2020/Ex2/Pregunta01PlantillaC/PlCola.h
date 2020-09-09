/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Nombre: Leandro Lazo La Rosa
 * Codigo: 20130263
 *
 * Created on 10 de diciembre de 2019, 08:03 AM
 */

#ifndef PLCOLA_H
#define PLCOLA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "NodoCola.h"
using namespace std;

template <typename T>
class PlCola{
public:
    PlCola();
    void insertar(T);
    void mostrar();
    T Pop();
private:
    class NodoCola *inicio;
    class NodoCola *final;
};

PlCola::PlCola(){
    inicio=NULL;
    final=NULL;
}

template <typename T>
void PlCola<T>::insertar(T a){
    class NodoCola *p,*aux;
    aux=new NodoCola;
    aux->valor=a;
    aux->sig=NULL;
    p=final;
    if(p==NULL){
        inicio=aux;
        final=aux;
    }
    else{
        p->sig=aux;
        final=aux;
    }
}

template <typename T>
void PlCola<T>::mostrar(){
    class NodoCola *aux;
    aux=inicio;
    while(aux!=NULL){
        cout<<aux->valor<<' ';
        aux=aux->sig;
    }
    cout<<endl;
}

template <typename T>
T PlCola<T>::Pop(){
    class NodoCola *aux;
    aux=inicio;
    inicio=aux->sig;
    return aux->valor;    
}
#endif /* PLCOLA_H */


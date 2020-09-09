/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallets.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 1:18 AM
 */

#include "ListaPallets.h"

ListaPallets::ListaPallets() {
    inicio=NULL;
}

ListaPallets::ListaPallets(const ListaPallets& orig) {
}

ListaPallets::~ListaPallets() {
}

void ListaPallets::crear(ifstream&in){
    Nodo *nuevo;
    nuevo=new Nodo;
    nuevo->elem.leerP(in);
    this->insertar(nuevo);  
}

void ListaPallets::insertar(Nodo*nuevo){
    Nodo *p,*ant;
    ant=NULL;
    p=inicio;
    while(p){
//        if(p->elem > nuevo->elem)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
//    nuevo->ant=ant;
//    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else inicio=nuevo;
}

void ListaPallets::imprime(ofstream&out){
    Nodo *p;
    p=inicio;
    while(p){
        p->elem.imprimirP(out);
        p=p->sig;
        out<<endl;
    }
}

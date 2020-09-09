/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:52 AM
 */

#include "ListaConductores.h"

ListaConductores::ListaConductores() {
    inicio=NULL;
}

ListaConductores::ListaConductores(const ListaConductores& orig) {
}

ListaConductores::~ListaConductores() {
}

void ListaConductores::cargar(ifstream&in){
    NodoC *nuevo;
    while(1){
        nuevo=new NodoC;
        nuevo->elem.leer(in);
        if(in.eof())break;
        this->insertar(nuevo);        
    }
}

void ListaConductores::insertar(NodoC *nuevo){
    NodoC *p,*ant;
    ant=NULL;
    p=inicio;
    while(p){
        if(p->elem.GetDni() > nuevo->elem.GetDni())break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    nuevo->ant=ant;
    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else inicio=nuevo;
}

void ListaConductores::imprimir(ofstream&out){
    NodoC *p;
    p=inicio;
    while(p){
        p->elem.imprimir(out);
        p=p->sig;
    }
}

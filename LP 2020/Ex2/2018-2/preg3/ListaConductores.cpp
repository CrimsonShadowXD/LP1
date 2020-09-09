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
    ultimo=NULL;
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
    if(p!=NULL){
        p->ant=nuevo;
    }
    else{
        ultimo=nuevo;
    }
    if(ant!=NULL){
        ant->sig=nuevo;
    }
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

void ListaConductores::imprimirRev(ofstream&out){
    NodoC *p;
    p=ultimo;
    while(p){
        p->elem.imprimir(out);
        p=p->ant;
    }
}

void ListaConductores::imprimirOrden(ofstream&out,int orden){
    if(orden==1){
        imprimirRev(out);
    }
    else{
        imprimir(out);
    }
}

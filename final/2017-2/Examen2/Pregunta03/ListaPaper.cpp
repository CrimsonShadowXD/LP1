/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPaper.cpp
 * Author: alulab14
 * 
 * Created on 5 de diciembre de 2017, 10:24 AM
 */
//20150008 Daniela Cisneros
#include "ListaPaper.h"

ListaPaper::ListaPaper() {
    lista=NULL;
}

ListaPaper::ListaPaper(const ListaPaper& orig) {
}

ListaPaper::~ListaPaper() {
}

void ListaPaper::insertar(Paper* d) {
    NodoPaper *p=lista, *ant=NULL,* nuevo;
    nuevo = new NodoPaper;
    nuevo->dato=d;
    while(p){
        if(*(p->dato)>*d) break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant !=NULL) ant->sig=nuevo;
    else lista=nuevo;
}

void ListaPaper::imprimir(ostream& arch) {
    NodoPaper *p=lista;
    while(p){
        p->dato->citar(arch);
        p=p->sig;
    }
}

void ListaPaper::eliminar() {
    NodoPaper *p=lista, *ant;
    
    while(p){
        if(p->dato) delete p->dato;
        ant=p;
        p=p->sig;
        delete ant;
    }
}
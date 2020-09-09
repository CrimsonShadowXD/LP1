/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaNotas.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 4:31 AM
 */

#include "ListaNotas.h"

ListaNotas::ListaNotas() {
    inicio=NULL;
}

ListaNotas::ListaNotas(const ListaNotas& orig) {
}

ListaNotas::~ListaNotas() {
}

void ListaNotas::insertar(NodoNota *nuevo){
    NodoNota *p,*ant;
    ant=NULL;
    p=inicio;
    while(p){
//        if(p->nota > nuevo->elem)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
//    nuevo->ant=ant;
//    if(p)p->ant=nuevo;
    if(ant)ant->sig=nuevo;
    else inicio=nuevo;
}

void ListaNotas::leer(ifstream&in){
    NodoNota *p;
    while(1){
        p=new NodoNota;
        p->nota.leerNota(in);
        if(in.eof())break;
        this->insertar(p);
    }
}

void ListaNotas::imprimir(ofstream&out){
    NodoNota *p;
    p=inicio;
    while(p){
        p->nota.imprimirNota(out);
        p=p->sig;
        out<<endl;
    }
}

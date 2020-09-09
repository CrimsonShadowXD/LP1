/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaMiembros.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 8:24 PM
 */

#include "ListaMiembros.h"

ListaMiembros::ListaMiembros() {
    inicio=NULL;
}

ListaMiembros::ListaMiembros(const ListaMiembros& orig) {
    NodoMiembro *p, *sale;
    p=inicio;
    while (p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}

ListaMiembros::~ListaMiembros() {
}

void ListaMiembros::insertar(Miembro *nuevo){
    NodoMiembro *p=inicio, *ant=NULL,*nodo;   
    
    nodo = new NodoMiembro;
    nodo->elem = nuevo;

    while(p){
        ant=p;
        p=p->sig;
    }
    if (ant==NULL){
        inicio=nodo;
    }
    else {
        ant->sig=nodo;
        nodo->sig=p; 

    }
}

void ListaMiembros::crear(ifstream&in){
    Miembro *entrada;
    while(1){
        char T;
        in>>T;
        if(in.eof())return;
        in.get();
        if(T=='A')
            entrada=new Alumno;
        else if(T=='D')
            entrada=new Docente;
        else if(T=='a')
            entrada=new Administrativo;
        in>>entrada;
//        entrada->leer(in);;
        this->insertar(entrada);         
    }
}

void ListaMiembros::imp(ofstream&out){
    NodoMiembro *p;
    p=inicio;

    while(p){
//        out<<p->elem;
        p->elem->imprimir(out);
        p=p->sig;
    }
}

void ListaMiembros::mod(float f){
    NodoMiembro *p;
    p=inicio;

    while(p){
        p->elem->modificar(f);
        p=p->sig;
    }
}

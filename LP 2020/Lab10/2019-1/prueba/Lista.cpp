/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: crimson
 * 
 * Created on July 10, 2020, 6:35 AM
 */

#include "Lista.h"

Lista::Lista() {
    inicio=NULL;
}

Lista::Lista(const Lista& orig) {
    Npdp *p, *sale;
    p=inicio;
    while (p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}

Lista::~Lista() {
}

void Lista::insertar(Miembro *nuevo){
    Npdp *p=inicio, *ant=NULL,*nodo;   
    
    nodo = new Npdp;
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

void Lista::crear(ifstream&in){
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

void Lista::imp(ofstream&out){
    Npdp *p;
    p=inicio;

    while(p){
//        out<<p->elem;
        p->elem->imprimir(out);
        p=p->sig;
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 5:20 PM
 */

#include "Lista.h"

Lista::Lista() {
    inicio=NULL;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    NodoLista *p, *sale;
    p = inicio;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void Lista::crear(ifstream&in){
    Alumno *entrada;
    while (1) {
        char T;
        in>>T;
        if (in.eof())return;
        in.get();
        if (T == 'R')
            entrada = new Nacional;
        else if (T == 'I')
            entrada = new Intercambio;
        entrada->leer(in);;
        this->insertar(entrada);
    }
}

void Lista::insertar(Alumno *nuevo){
    NodoLista *p = inicio, *ant = NULL, *nodo;

    nodo = new NodoLista;
    nodo->elem = nuevo;

    while (p) {
        if(p->elem->GetCodigo() > nodo->elem->GetCodigo())break;
        ant = p;
        p = p->sig;
    }
    nodo->sig = p;
    if (ant == NULL) inicio = nodo; 
    else ant->sig = nodo;
}

void Lista::imprimir(ofstream&out){
    NodoLista *p;
    p = inicio;
    while (p) {
        p->elem->imprimir(out);
        p = p->sig;
    }
}

void Lista::BuscarInsertar(ifstream&in,int x){
    NodoLista *p;
    p = inicio;
    while (p) {
        CursoNotas aux;
        if(p->elem->GetCodigo()==x){
            in>>aux;
            p->elem->insertarNota(aux);
            break;
        }
        p = p->sig;
    }
}


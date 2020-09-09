/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCursos.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 11:06 PM
 */

#include "ListaCursos.h"

ListaCursos::ListaCursos() {
    inicio = NULL;
}

ListaCursos::~ListaCursos() {
    NodoCurso *p, *sale;
    p = inicio;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaCursos::crear(ifstream&in) {
    
    while (1) {
        class Curso entrada;
        entrada.leer(in);
        if (in.eof())return;
        this->insertar(entrada);
    }
}

void ListaCursos::insertar(const class Curso& nuevo) {
    NodoCurso *p = inicio, *ant = NULL, *nodo;

    nodo = new NodoCurso;
    nodo->elem = nuevo;
    char cad1[10],cad2[10];
    while (p) {
        p->elem.GetCodigo(cad1);
        nodo->elem.GetCodigo(cad2); 
        if (strcmp(cad1,cad2)>0)break;
        ant = p;
        p = p->sig;
    }
    nodo->sig = p;
    if (ant == NULL) inicio = nodo;
    else ant->sig = nodo;
}

void ListaCursos::imprimir(ofstream&out) {
    NodoCurso *p;
    p = inicio;
    while (p) {
        p->elem.imprimir(out);
        p = p->sig;
    }
}
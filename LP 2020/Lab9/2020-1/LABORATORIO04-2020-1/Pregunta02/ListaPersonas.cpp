/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPersonas.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:21 AM
 */

#include "ListaPersonas.h"

ListaPersonas::ListaPersonas() {
    inicio=NULL;
}

ListaPersonas::ListaPersonas(const ListaPersonas& orig) {
}

ListaPersonas::~ListaPersonas() {
    NodoPersona *p, *sale;
    p = inicio;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaPersonas::insertar(Persona *nuevo) {
    NodoPersona *p = inicio, *ant = NULL, *nodo;

    nodo = new NodoPersona;
    nodo->elem = nuevo;

    while (p) {
        if(p->elem->getPrio() > nodo->elem->getPrio())break;
        ant = p;
        p = p->sig;
    }
    if (ant == NULL) {
        inicio = nodo;
    } else {
        ant->sig = nodo;
        nodo->sig = p;

    }
}

void ListaPersonas::crear(ifstream&in) {
    Persona *entrada;
    while (1) {
        char T;
        in>>T;
        if (in.eof())return;
        in.get();
        if (T == 'A')
            entrada = new Alumno;
        else if (T == 'P')
            entrada = new Profesor;
        entrada->leer(in);;
        this->insertar(entrada);
    }
}

void ListaPersonas::imprResultados(int TC,int TP,int TPA,int ALUM,ofstream&out){
    out<<"           Reservas Asignadas"<<endl;
    out<<"Cantidad de TC:      "<<TC<<endl;
    out<<"Cantidad de TP:      "<<TP<<endl;
    out<<"Cantidad de TPA:     "<<TPA<<endl;
    out<<"Cantidad de Alumnos: "<<ALUM<<endl;
    out<<"======================================"<<endl;
}

void ListaPersonas::imp(ofstream&out) {
    NodoPersona *p;
    int TC=0,TP=0,TPA=0,Al=0,n;
    p = inicio;
    cout<<TC<<TP<<TPA<<Al<<endl;
    while (p) {
        n=p->elem->getPrio();
        if(n==1) TC++;
        else if(n==2) TP++;
        else if(n==3) TPA++;
        else if(n==4) Al++;
        p = p->sig;
    }    
    imprResultados(TC,TP,TPA,Al,out);
    p = inicio;
    while (p) {
        p->elem->imprimir(out);
        p = p->sig;
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallet.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:48 PM
 */

#include "ListaPallet.h"

ListaPallet::ListaPallet() {
    inicio = NULL; 
}
 
ListaPallet::~ListaPallet() {
    NodoP *p, *sale;
    p = inicio;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaPallet::crear(ifstream&in) {
    Pallet *entrada;
    while (1) {
        char T[3];
        in>>ws;
        if (in.eof())return;
        in.getline(T,3,','); 
        if (strcmp(T,"EU")==0)
            entrada = new PalletEU;
        else if (strcmp(T,"PE")==0)
            entrada = new PalletPE;
        else if (strcmp(T,"US")==0)
            entrada = new PalletUS;
        entrada->leer(in);;
        this->insertar(entrada);
    }
}

void ListaPallet::insertar(Pallet *nuevo) {
    NodoP *p = inicio, *ant = NULL, *nodo;

    nodo = new NodoP;
    nodo->elem = nuevo;

    while (p) {
//        if(p->elem->getPeso() > nodo->elem->getPeso())break;
        ant = p;
        p = p->sig;
    } 
    nodo->sig = p;
    nodo->ant = ant;
    if (p!=NULL) p->ant = nodo;
    else fin = nodo;
    if (ant == NULL) {
        inicio = nodo;
    } else {
        ant->sig = nodo; 
    }
}

void ListaPallet::imprimir(ofstream&out) {
    NodoP *p;
    p = inicio;
    while (p) {
        p->elem->imprimir(out);
        p = p->sig;
    }
    out<<endl;
}

void ListaPallet::eliminarNodo(NodoP *&nodo){
    NodoP *auxAnt,*auxSig;
    auxAnt=nodo->ant;
    auxSig=nodo->sig;
    
    if(auxAnt==NULL)inicio=auxSig;
    else auxAnt->sig=auxSig;
    
    if(auxSig==NULL)fin=auxAnt;
    else auxSig->ant=auxAnt;
    delete nodo;
}

void ListaPallet::eliminar(int n){
    NodoP *p;
    p = inicio;
    int i=0;
    while (p) {
        i++;
        if(i==n){
            eliminarNodo(p);
            break;
        }
        p = p->sig;
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaPallet.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 6:23 PM
 */

#include "PilaPallet.h"

PilaPallet::PilaPallet() {
    top=NULL; 
} 

PilaPallet::~PilaPallet() {
    NodoPila *p, *sale;
    p = top;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void PilaPallet::crear(ifstream&in){
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

void PilaPallet::insertar(Pallet*nuevo){
    NodoPila *nodo;
    nodo = new NodoPila;
    nodo->elem = nuevo;
    nodo->sig = top;
    top = nodo;
}

void PilaPallet::imprimir(ofstream&out){
    class NodoPila *p = top;
    while (p) {
        p->elem->imprimir(out);
        p = p->sig;
    }
    out << endl;
}

Pallet* PilaPallet::Desapilar(){
    class NodoPila *p;
    p = top;
    if (!p)return NULL;
    top = p->sig;
    Pallet* v;
    char cad[10],T;
    if(T=='U')v=new PalletUS;
    else if(T=='P')v=new PalletPE;
    else v=new PalletEU;
    p->elem->GetId(cad);
    v->SetId(cad);
    delete p;
    return v;
}

bool PilaPallet::vacia(){
    return (top == NULL);
}

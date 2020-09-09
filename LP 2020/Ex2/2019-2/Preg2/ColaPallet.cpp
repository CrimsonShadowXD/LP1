/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaPallet.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 7:21 PM
 */

#include "ColaPallet.h"

ColaPallet::ColaPallet() {
    inicio=NULL;
    fin=NULL;
}

ColaPallet::ColaPallet(const ColaPallet& orig) {
}

ColaPallet::~ColaPallet() {
    NodoCola *p, *sale;
    p = inicio;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ColaPallet::crear(ifstream&in){
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

void ColaPallet::insertar(Pallet*nuevo){
    NodoCola *nodo;
    nodo = new NodoCola;
    nodo->elem = nuevo;
    if (fin != NULL)
        fin->sig = nodo;
    if (inicio == NULL)
        inicio = nodo;
    fin = nodo;
}

void ColaPallet::imprimir(ofstream&out){
    class NodoCola *p = inicio;
    while (p) {
        p->elem->imprimir(out);
        p = p->sig;
    }
    out << endl;
}

Pallet* ColaPallet::Pop(){
    class NodoCola *p;
    p = inicio;
    if (!p)return NULL;
    inicio = p->sig;
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

bool ColaPallet::vacia(){
    return (inicio == NULL);
}

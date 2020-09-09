/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pallet.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 1:22 AM
 */

#include "Pallet.h"

Pallet::Pallet() {
    elem=NULL;
}

Pallet::Pallet(const Pallet& orig) {
}

Pallet::~Pallet() {
}

void Pallet::leerP(ifstream&in){
    char tipo[3];
    in>>ws;
    if (in.eof()) return;
    
    in.getline(tipo,3,',');

    if (strcmp(tipo,"EU")==0) 
        elem = new PalletEU;
    else if (strcmp(tipo,"PE")==0) 
        elem = new PalletPE;
    else if (strcmp(tipo,"US")==0) 
        elem = new PalletUS;

    elem->leer(in);
}

void Pallet::imprimirP(ofstream&out){
    out<<this->elem->getPeso()<<' ';
    char cad[15];
    this->elem->GetId(cad);
    out<<cad<<' ';
    this->elem->getTipo(cad);
    out<<cad<<' ';
    out<<"=================================="<<endl;
//    this->elem->imprimir(out);
}

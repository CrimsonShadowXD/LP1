/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:36 PM
 */

#include "PalletPE.h"

PalletPE::PalletPE() {
}

PalletPE::PalletPE(const PalletPE& orig) {
}

PalletPE::~PalletPE() {
}

void PalletPE::leer(ifstream&in) {
    char c,cad[10];
    c=13;
    in.getline(cad,10,c);
    SetId(cad);
}

void PalletPE::imprimir(ofstream&out) {
    char c,cad[10]; 
    GetId(cad);
    out<<cad<<' '<<getPeso()<<' '<<getTipo()<<endl;
}

int PalletPE::getPeso() {
    return 60;
}

char PalletPE::getTipo(){
    return 'P';
}
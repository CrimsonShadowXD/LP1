/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletUS.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:35 PM
 */

#include "PalletUS.h"

PalletUS::PalletUS() {
}

PalletUS::PalletUS(const PalletUS& orig) {
}

PalletUS::~PalletUS() {
}

void PalletUS::leer(ifstream&in){
    char c,cad[10];
    c=13;
    in.getline(cad,10,c);
    SetId(cad);
}

void PalletUS::imprimir(ofstream&out){
    char c,cad[10]; 
    GetId(cad);
    out<<cad<<' '<<getPeso()<<' '<<getTipo()<<endl;
}

int PalletUS::getPeso(){
    return 40;
}

char PalletUS::getTipo(){
    return 'U';
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:36 PM
 */

#include "PalletEU.h"

PalletEU::PalletEU() {
}

PalletEU::PalletEU(const PalletEU& orig) {
}

PalletEU::~PalletEU() {
}

void PalletEU::leer(ifstream&in) {
    char c,cad[10];
    c=13;
    in.getline(cad,10,c);
    SetId(cad);
}

void PalletEU::imprimir(ofstream&out) {
    char c,cad[10]; 
    GetId(cad);
    out<<cad<<' '<<getPeso()<<' '<<getTipo()<<endl;
}

int PalletEU::getPeso() {
    return 50;
}

char PalletEU::getTipo(){
    return 'E';
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletEU.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 11:08 PM
 */

#include "PalletEU.h"

PalletEU::PalletEU() {
}

void PalletEU::setCap(int cap) {
    this->cap = cap;
}

int PalletEU::getCap() const {
    return cap;
}

PalletEU::PalletEU(const PalletEU& orig) {
}

PalletEU::~PalletEU() {
}

void PalletEU::leer(ifstream &in){
    char cad[50];
    in.getline(cad,50);
    SetId(cad);
    
}

void PalletEU::getTipo(char *cad){
    strcpy(cad,"EU");
}

int PalletEU::getPeso(){
    return 50; 
}

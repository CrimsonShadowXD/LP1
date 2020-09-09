/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletPE.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 11:09 PM
 */

#include "PalletPE.h"

PalletPE::PalletPE() {
}

PalletPE::PalletPE(const PalletPE& orig) {
}

PalletPE::~PalletPE() {
}

void PalletPE::SetCap(int cap) {
    this->cap = cap;
}

int PalletPE::GetCap() const {
    return cap;
}

void PalletPE::leer(ifstream &in){
    char cad[50];
    in.getline(cad,50);
    SetId(cad);
    
}

void PalletPE::getTipo(char *cad){
    strcpy(cad,"PE");
}

int PalletPE::getPeso(){
    return 60; 
}
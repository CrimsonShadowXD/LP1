/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PalletUS.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 11:08 PM
 */

#include "PalletUS.h"

PalletUS::PalletUS() {
}

PalletUS::PalletUS(const PalletUS& orig) {
}

PalletUS::~PalletUS() {
}

void PalletUS::SetCap(int cap) {
    this->cap = cap;
}

int PalletUS::GetCap() const {
    return cap;
}

void PalletUS::leer(ifstream &in){
    char cad[50];
    in.getline(cad,50);
    SetId(cad);
    
}

void PalletUS::getTipo(char *cad){
    strcpy(cad,"US");
}

int PalletUS::getPeso(){
    return 40; 
}
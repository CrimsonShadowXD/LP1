/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltante.cpp
 * Author: crimson
 * 
 * Created on July 14, 2020, 1:23 PM
 */

#include "Faltante.h"

Faltante::Faltante() {
}

Faltante::Faltante(const Faltante& orig) {
}

Faltante::~Faltante() {
}

void Faltante::SetCantp(double cantp) {
    this->cantp = cantp;
}

double Faltante::GetCantp() const {
    return cantp;
}

void Faltante::SetCodp(int codp) {
    this->codp = codp;
}

int Faltante::GetCodp() const {
    return codp;
}

void Faltante::operator=(const Faltante&p){
    SetCantp(p.GetCantp());
    SetCodp(p.GetCodp());
}

ofstream& operator<<(ofstream&out, Faltante&p){
    return out;
}

void operator>>(ifstream&in, Faltante&p){
    
}
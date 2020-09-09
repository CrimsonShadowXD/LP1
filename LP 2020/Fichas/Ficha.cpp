/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ficha.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 7:24 PM
 */

#include "Ficha.h"

Ficha::Ficha() {
    id=NULL;
    fil=-1;
    col=-1;
}

Ficha::Ficha(const Ficha& orig) {
}

Ficha::~Ficha() {
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFil(int fil) {
    this->fil = fil;
}

int Ficha::GetFil() const {
    return fil;
}

void Ficha::SetId(char* cad) {
    if (cad==NULL) return;
    if(id!=NULL) delete id;
    id = new char[strlen(cad)+1];
    strcpy(id,cad);
}

void Ficha::GetId(char* cad) const {
    if(id==NULL)
        return;
    strcpy(cad,id);
}

void Ficha::asigna(char*cad,int fila,int columna){
    SetId(cad);
    SetFil(fila);
    SetFil(columna);
}
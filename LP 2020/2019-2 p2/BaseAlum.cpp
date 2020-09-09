/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseAlum.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 5:28 AM
 */

#include "BaseAlum.h"

BaseAlum::BaseAlum() {
    codigo=-1;
    nombre=NULL;
}

BaseAlum::BaseAlum(const BaseAlum& orig) {
}

BaseAlum::~BaseAlum() {
}

void BaseAlum::SetNombre(char* cad) {
    if (cad==NULL) return;
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void BaseAlum::GetNombre(char* cad) const {
    if(nombre==NULL)
        return;
    strcpy(cad,nombre);
}

void BaseAlum::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int BaseAlum::GetCodigo() const {
    return codigo;
}


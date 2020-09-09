/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.cpp
 * Author: crimson
 * 
 * Created on July 9, 2020, 6:55 PM
 */

#include "Miembro.h"

Miembro::Miembro() {
    nombre=NULL;
    codigo=-1;
    distrito=NULL;
}


Miembro::Miembro(const Miembro& orig) {
}

Miembro::~Miembro() {
}

void Miembro::setDistrito(const char* cad) {
    if (cad==NULL) return;
    if(distrito!=NULL) delete distrito;
    distrito = new char[strlen(cad)+1];
    strcpy(distrito,cad); 
}

void Miembro::getDistrito(char* cad) const {
    if(distrito==NULL)
        return;
    strcpy(cad,distrito);
}

void Miembro::setCodigo(int codigo) {
   this->codigo = codigo;
}

int Miembro::getCodigo() const {
    return codigo;
}

void Miembro::setNombre(const char* cad) {
     if (cad==NULL) return;
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Miembro::getNombre(char* cad) const {
    if(nombre==NULL)
        return;
    strcpy(cad,nombre);
}

ofstream &operator << (ofstream &arch, Miembro *&c){
    c->imprimir(arch);
    return arch;
}

ifstream &operator >> (ifstream &arch, Miembro *&c){
    c->leer(arch);
    return arch;
}
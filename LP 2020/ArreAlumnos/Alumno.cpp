/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: cueva
 * 
 * Created on 1 de julio de 2020, 12:47 PM
 */
#include <iostream>
#include <cstring>
#include "Alumno.h"

using namespace std;

Alumno::Alumno() {
    codigo = -1;
    nombre = NULL;
}


Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::SetNombre(char* cad) {
    if(cad==NULL) return;
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}


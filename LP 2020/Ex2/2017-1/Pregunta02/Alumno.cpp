/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 3:54 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    nombre=NULL;
}

Alumno::Alumno(const Alumno& orig) {
    nombre=NULL;
}

Alumno::~Alumno() {
}

void Alumno::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad); 
}

void Alumno::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre); 
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:04 AM
 */

#include "Persona.h"

Persona::Persona() {
    nombre=NULL;
    distrito=NULL;
    codigo=-1;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

void Persona::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Persona::GetCodigo() const {
    return codigo;
}

void Persona::SetDistrito(const char* cad) {
    if (cad == NULL) return;
    if (distrito != NULL) delete distrito;
    distrito = new char[strlen(cad) + 1];
    strcpy(distrito, cad);
}

void Persona::GetDistrito(char* cad) const {
    if (distrito == NULL)
        return;
    strcpy(cad, distrito);
}

void Persona::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Persona::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre);
}


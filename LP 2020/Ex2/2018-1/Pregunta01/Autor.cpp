/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.cpp
 * Author: crimson
 * 
 * Created on July 18, 2020, 3:24 PM
 */

#include "Autor.h"

Autor::Autor() {
}

Autor::Autor(const Autor& orig) {
}

Autor::~Autor() {
}

void Autor::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Autor::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre);
}

void Autor::SetDni(int dni) {
    this->dni = dni;
}

int Autor::GetDni() const {
    return dni;
}

void Autor::operator=(const Autor&a){
    //
}

bool Autor::operator==(const Autor&a){
    return (GetDni()==a.GetDni());
}

bool Autor::operator>(const Autor&a){
    return (GetDni()>a.GetDni());
}

bool Autor::operator<(const Autor&a){
    return (GetDni()<a.GetDni());
}

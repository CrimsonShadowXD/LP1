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
    nombre=NULL;
}

Autor::Autor(const Autor& orig) {
    nombre=NULL;
    *this=orig;
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
    char cad[150];
    a.GetNombre(cad);
    SetNombre(cad);
    SetDni(a.GetDni());
}

bool Autor::operator==(const Autor&a){
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1,cad2)==0);
}

bool Autor::operator>(const Autor&a){
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1,cad2)>0);
}

bool Autor::operator<(const Autor&a){
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1,cad2)<0);
}

ofstream& operator<<(ofstream&out, Autor&a){ 
    char cad[150];
    a.GetNombre(cad);
    out<<a.GetDni()<<' '<<left<<setw(25)<<cad<<right;
    return out;
}

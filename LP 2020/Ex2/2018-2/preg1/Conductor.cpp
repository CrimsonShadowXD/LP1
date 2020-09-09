/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 5:53 AM
 */

#include "Conductor.h"

Conductor::Conductor() {
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {
}

void Conductor::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Conductor::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre);
}

void Conductor::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Conductor::GetTelefono() const {
    return telefono;
}

void Conductor::SetDni(int dni) {
    this->dni = dni;
}

int Conductor::GetDni() const {
    return dni;
}

void Conductor::leer(ifstream&in){
    int dni,tele;
    char cad[150];
    in>>dni;
    if(in.eof())return;
    in.get();
    SetDni(dni);
    in.getline(cad,150,',');
    SetNombre(cad);
    in>>tele; 
    in.get();
    in.ignore(200,'\n');
    SetTelefono(tele);
}

void Conductor::imprimir(ofstream&out){
    Conductor x;
    char cad[150];
    out<<GetDni()<<' ';
    GetNombre(cad);
    out<<cad<<' ';
    out<<GetTelefono()<<endl;
}
    
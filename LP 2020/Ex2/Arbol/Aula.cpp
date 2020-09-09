/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aula.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:52 AM
 */

#include "Aula.h"

Aula::Aula() {
    clave=NULL;
    nombre=NULL;
    tipo=NULL;
    capacidad=-1;
    codigo=-1;
    numero=-1;
}

Aula::Aula(const Aula& orig) {
    clave=NULL;
    nombre=NULL;
    tipo=NULL;
    *this=orig;
}

Aula::~Aula() {
}

void Aula::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Aula::GetCodigo() const {
    return codigo;
}

void Aula::SetCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

int Aula::GetCapacidad() const {
    return capacidad;
}

void Aula::SetTipo(const char* cad) {
    if (cad == NULL) return;
    if (tipo != NULL) delete tipo;
    tipo = new char[strlen(cad) + 1];
    strcpy(tipo, cad);
}

void Aula::GetTipo(char* cad) const {
    if (tipo == NULL)
        return;
    strcpy(cad, tipo);
}

void Aula::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Aula::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre);
}

void Aula::SetClave(const char* cad) {
    if (cad == NULL) return;
    if (clave != NULL) delete clave;
    clave = new char[strlen(cad) + 1];
    strcpy(clave, cad);
}

void Aula::GetClave(char* cad) const {
    if (clave == NULL)
        return;
    strcpy(cad, clave);
}

void Aula::leer(ifstream&in) {
    char cad[150];
    int cap;
    in.getline(cad, 150, ',');
    SetClave(cad);
    in>>cap;
    SetCapacidad(cap);
    in>>ws;
}

void Aula::imprimir(ofstream&out) {
    char cad[150];
    GetClave(cad);
    out << cad << ' '<<setw(10)<<GetCapacidad()<<endl;
}
void Aula::operator=(const Aula& a) {
    char cad[150];
    a.GetClave(cad);
    SetClave(cad);
    SetCapacidad(a.GetCapacidad());
    SetCodigo(a.GetCodigo());
    a.GetNombre(cad);
    SetNombre(cad);
    a.GetTipo(cad);
    SetTipo(cad);
}

bool Aula::operator==(const Aula&a) {
//    char cad1[150], cad2[150];
//    GetClave(cad1);
//    a.GetClave(cad2);
//    return (strcmp(cad1, cad2) == 0);
    return (GetNumero()==a.GetNumero());
}

bool Aula::operator>(const Aula&a) {
//    char cad1[150], cad2[150];
//    GetClave(cad1);
//    a.GetClave(cad2);
//    return (strcmp(cad1, cad2) > 0);
    return (GetNumero()>a.GetNumero());
}

bool Aula::operator<(const Aula&a) {
//    char cad1[150], cad2[150];
//    GetClave(cad1);
//    a.GetClave(cad2);
//    return (strcmp(cad1, cad2) < 0);
    return (GetNumero()<a.GetNumero());
}

void Aula::SetNumero(int numero) {
    this->numero = numero;
}

int Aula::GetNumero() const {
    return numero;
}

ofstream& operator<<(ofstream&out, Aula&a) {
    a.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Aula&a) {
    a.leer(in);
}
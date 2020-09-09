/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moneda.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 09:43 AM
 */

#include "Moneda.h"

Moneda::Moneda() {
    nombre=NULL;
}

Moneda::Moneda(const Moneda& orig) {
    nombre=NULL;
    *this=orig;
}

Moneda::~Moneda() {
    if (nombre != NULL) delete nombre;
}

void Moneda::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad); 
}

void Moneda::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre); 
}

void Moneda::SetEquivalencia(double equivalencia) {
    this->equivalencia = equivalencia;
}

double Moneda::GetEquivalencia() const {
    return equivalencia;
}

void Moneda::SetSimbolo(char simbolo) {
    this->simbolo = simbolo;
}

char Moneda::GetSimbolo() const {
    return simbolo;
}

void Moneda::leer(ifstream&in) { 
    char cad[150],T;
    double eq;
    in>>T;
    if(in.eof())return;
    SetSimbolo(T);
    in.get();
    in>>eq;
    SetEquivalencia(eq);
    in.get();
    in.getline(cad,150,'\n');
    SetNombre(cad);
    in>>ws;
}

void Moneda::imprimir(ofstream&out) { 
    char cad[150];
    out<<GetSimbolo()<<' '<<GetEquivalencia()<<' ';
    GetNombre(cad);
    out<<cad<<endl;
}

void Moneda::operator=(const Moneda& x) {
    char cad[150];
    x.GetNombre(cad);
    SetNombre(cad);
    SetEquivalencia(x.GetEquivalencia());
    SetSimbolo(x.GetSimbolo());
}

bool Moneda::operator==(const Moneda&x) { 
    return (GetSimbolo()==x.GetSimbolo());
}

bool Moneda::operator>(const Moneda&x) { 
    return (GetSimbolo()>x.GetSimbolo());
}

bool Moneda::operator<(const Moneda&x) { 
    return (GetSimbolo()<x.GetSimbolo());
}

ofstream& operator<<(ofstream&out, Moneda&x) {
    x.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Moneda&x) {
    x.leer(in);
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:05 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    escala=-1;
    especialidad=NULL;
    facultad=NULL;
}

Alumno::Alumno(const Alumno& orig) {
    especialidad=NULL;
    facultad=NULL;
    *this=orig;
}

Alumno::~Alumno() {
}

void Alumno::SetFacultad(const char* cad) {
    if (cad == NULL) return;
    if (facultad != NULL) delete facultad;
    facultad = new char[strlen(cad) + 1];
    strcpy(facultad, cad);
}

void Alumno::GetFacultad(char* cad) const {
    if (facultad == NULL)
        return;
    strcpy(cad, facultad);
}

void Alumno::SetEspecialidad(const char* cad) {
    if (cad == NULL) return;
    if (especialidad != NULL) delete especialidad;
    especialidad = new char[strlen(cad) + 1];
    strcpy(especialidad, cad);
}

void Alumno::GetEspecialidad(char* cad) const {
    if (especialidad == NULL)
        return;
    strcpy(cad, especialidad);
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::leer(ifstream&in) {
    char cad[150];
    int cod,esc;
    in.getline(cad, 150, ',');
    SetNombre(cad);
    in>>cod;
    SetCodigo(cod);
    in.get();
    in.getline(cad, 150, ',');
    SetDistrito(cad);
    in>>esc;
    SetEscala(esc);
    in.get();
    in.getline(cad, 150, ',');
    SetEspecialidad(cad);
    in.getline(cad, 150);
    SetFacultad(cad);
}

void Alumno::imprimir(ofstream&out) {
    char cad[150];
    GetNombre(cad);
    out<<setw(100)<<left<<cad<<right<<' ';
    out<<GetCodigo()<<' ';
    out<<GetEscala()<<' ';
    GetDistrito(cad);
    out<<cad<<' ';
    GetEspecialidad(cad);
    out<<cad<<' ';
    GetFacultad(cad);
    out<<cad<<endl;
}

void Alumno::operator=(const Alumno& a) {
    char cad[150];
    SetCodigo(a.GetCodigo());
    SetEscala(a.GetEscala());
    a.GetDistrito(cad);
    SetDistrito(cad);
    a.GetEspecialidad(cad);
    SetEspecialidad(cad);
    a.GetFacultad(cad);
    SetFacultad(cad);
    a.GetNombre(cad);
    SetNombre(cad);
}

bool Alumno::operator==(const Alumno& a) {
    return (GetCodigo() == a.GetCodigo());
}

bool Alumno::operator>(const Alumno&a) {
    return (GetCodigo() > a.GetCodigo());
}

bool Alumno::operator<(const Alumno&a) {
    return (GetCodigo() < a.GetCodigo());
}

ofstream& operator<<(ofstream&out, Alumno&a) {
    a.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Alumno&a) {
    a.leer(in);
}
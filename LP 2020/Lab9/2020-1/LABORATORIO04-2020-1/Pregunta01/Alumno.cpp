/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 10 de julio de 2020, 08:03 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    escala=-1;
    especialidad=NULL;
    facultad=NULL;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if (facultad != NULL) delete facultad;
    if (especialidad != NULL) delete especialidad;
    
}

void Alumno::SetFacultad(const char* cad) {
    if (cad == NULL) return;
    if (facultad != NULL) delete facultad;
    facultad = new char[strlen(cad) + 1];
    strcpy(facultad, cad);
    this->facultad = facultad;
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

void Alumno::leer(ifstream&in){
    char cad[150];
    int escala,cod;
    double creditaje,aprob;
    in.getline(cad,150,','); SetNombre(cad);
    in>>cod; SetCodigo(cod);
    in.get();
    in.getline(cad,150,','); SetDistrito(cad);
    in>>escala; SetEscala(escala);
    in.get();
    in.getline(cad,150,','); SetEspecialidad(cad);
    in.getline(cad,150); SetFacultad(cad);
    in>>ws;
}

void Alumno::imprimir(ofstream&out){
    char cad[150];
    out<<"Codigo: "<<GetCodigo()<<endl;
    GetNombre(cad);
    out<<"Nombre del alumno: "<<cad<<endl;
    GetDistrito(cad);
    out<<"Distrito: "<<cad<<endl;
    GetEspecialidad(cad);
    out<<"Especialidad: "<<cad<<endl;
    GetFacultad(cad);
    out<<"Facultad: "<<cad<<endl;
    out<<"Escala de pago: "<<GetEscala()<<endl;    
    out<<"=========================="<<endl;
}

int Alumno::getPrio(){
    return 4;
}


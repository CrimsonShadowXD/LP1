/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:06 AM
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
}

void Alumno::SetFacultad(char* cad) {
    if (cad==NULL) return;
    if(facultad!=NULL) 
            delete facultad;
    facultad = new char[strlen(cad)+1];
    strcpy(facultad,cad); 
}

void Alumno::GetFacultad(char* cad) const {
    if(facultad==NULL)
        return;
    strcpy(cad,facultad);
}

void Alumno::SetEspecialidad(char* cad) {
    if (cad==NULL) return;
    if(especialidad!=NULL) 
            delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void Alumno::GetEspecialidad(char* cad) const {
    if(especialidad==NULL)
        return;
    strcpy(cad,especialidad);
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}


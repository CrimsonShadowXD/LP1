/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 08:06 AM
 */

#include "Profesor.h"

Profesor::Profesor() {
}

Profesor::Profesor(const Profesor& orig) {
}

Profesor::~Profesor() {
}

void Profesor::SetGrado(char* cad) {
    if (cad==NULL) return;
    if(grado!=NULL) 
            delete grado;
    grado = new char[strlen(cad)+1];
    strcpy(grado,cad);
}

void Profesor::GetGrado(char* cad) const {
    if(grado==NULL)
        return;
    strcpy(cad,grado);
}

void Profesor::SetSeccion(char* cad) {
    if (cad==NULL) return;
    if(seccion!=NULL) 
            delete seccion;
    seccion = new char[strlen(cad)+1];
    strcpy(seccion,cad);
}

void Profesor::GetSeccion(char* cad) const {
    if(seccion==NULL)
        return;
    strcpy(cad,seccion);
}

void Profesor::SetDedicacion(char* cad) {
    if (cad==NULL) return;
    if(dedicacion!=NULL) 
            delete dedicacion;
    dedicacion = new char[strlen(cad)+1];
    strcpy(dedicacion,cad);
}

void Profesor::GetDedicacion(char* cad) const {
    if(dedicacion==NULL)
        return;
    strcpy(cad,dedicacion);
}

void Profesor::SetCategoria(char* cad) {
    if (cad==NULL) return;
    if(categoria!=NULL) 
            delete categoria;
    categoria = new char[strlen(cad)+1];
    strcpy(categoria,cad);
}

void Profesor::GetCategoria(char* cad) const {
    if(categoria==NULL)
        return;
    strcpy(cad,categoria);
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:05 AM
 */

#include "Profesor.h"

Profesor::Profesor() {
    categoria=NULL;
    dedicacion=NULL;
    seccion=NULL;
    grado=NULL;
}

Profesor::Profesor(const Profesor& orig) {
    categoria=NULL;
    dedicacion=NULL;
    seccion=NULL;
    grado=NULL;
    *this=orig;
}

Profesor::~Profesor() {
}

void Profesor::SetGrado(const char* cad) {
    if (cad == NULL) return;
    if (grado != NULL) delete grado;
    grado = new char[strlen(cad) + 1];
    strcpy(grado, cad);
}

void Profesor::GetGrado(char* cad) const {
    if (grado == NULL)
        return;
    strcpy(cad, grado);
}

void Profesor::SetSeccion(const char* cad) {
    if (cad == NULL) return;
    if (seccion != NULL) delete seccion;
    seccion = new char[strlen(cad) + 1];
    strcpy(seccion, cad);
}

void Profesor::GetSeccion(char* cad) const {
    if (seccion == NULL)
        return;
    strcpy(cad, seccion);
}

void Profesor::SetDedicacion(const char* cad) {
    if (cad == NULL) return;
    if (dedicacion != NULL) delete dedicacion;
    dedicacion = new char[strlen(cad) + 1];
    strcpy(dedicacion, cad);
}

void Profesor::GetDedicacion(char* cad) const {
    if (dedicacion == NULL)
        return;
    strcpy(cad, dedicacion);
}

void Profesor::SetCategoria(const char* cad) {
    if (cad == NULL) return;
    if (categoria != NULL) delete categoria;
    categoria = new char[strlen(cad) + 1];
    strcpy(categoria, cad);
}

void Profesor::GetCategoria(char* cad) const {
    if (categoria == NULL)
        return;
    strcpy(cad, categoria);
}

void Profesor::leer(ifstream&in) {
    char cad[150];
    int cod,esc;
    in.getline(cad, 150, ',');
    SetNombre(cad);
    in>>cod;
    SetCodigo(cod);
    in.get();
    in.getline(cad, 150, ',');
    SetDistrito(cad);
    
    in.getline(cad, 150, ',');
    SetCategoria(cad);
    in.getline(cad, 150, ',');
    SetDedicacion(cad);
    in.getline(cad, 150, ',');
    SetSeccion(cad);
    in.getline(cad, 150);
    SetGrado(cad);
}

void Profesor::imprimir(ofstream&out) {
    char cad[150];
    
    GetNombre(cad);
    out<<setw(100)<<left<<cad<<right<<' ';
    out<<GetCodigo()<<' ';
    GetDistrito(cad);
    out<<cad<<' ';
    GetCategoria(cad);
    out<<cad<<' ';
    GetDedicacion(cad);
    out<<cad<<' ';
    GetSeccion(cad);
    out<<cad<<' ';
    GetGrado(cad);
    out<<cad<<endl;
}

void Profesor::operator=(const Profesor& p) {
    char cad[150];
    SetCodigo(p.GetCodigo());
    p.GetDistrito(cad);
    SetDistrito(cad);
    p.GetCategoria(cad);
    SetCategoria(cad);
    p.GetDedicacion(cad);
    SetDedicacion(cad);
    p.GetSeccion(cad);
    SetSeccion(cad);
    p.GetGrado(cad);
    SetGrado(cad);
    p.GetNombre(cad);
    SetNombre(cad);
}

bool Profesor::operator>(const Profesor&p) {
    char cad1[150], cad2[150];
    GetNombre(cad1);
    p.GetNombre(cad2);
    return (strcmp(cad1, cad2) > 0);
}

bool Profesor::operator<(const Profesor&p) {
    char cad1[150], cad2[150];
    GetNombre(cad1);
    p.GetNombre(cad2);
    return (strcmp(cad1, cad2) < 0);
}

ofstream& operator<<(ofstream&out, Profesor&p) {
    p.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Profesor&p) {
    p.leer(in);
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 8:41 PM
 */

#include "Curso.h"

Curso::Curso() {
    codigo=NULL;
    nombre=NULL;
}

Curso::Curso(const Curso& orig) {
    codigo=NULL;
    nombre=NULL;
    *this=orig;
}

Curso::~Curso() {
}

void Curso::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Curso::GetCreditos() const {
    return creditos;
}

void Curso::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad); 
}

void Curso::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre); 
}

void Curso::SetCodigo(const char* cad) {
    if (cad == NULL) return;
    if (codigo != NULL) delete codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad); 
}

void Curso::GetCodigo(char* cad) const {
    if (codigo == NULL)
        return;
    strcpy(cad, codigo); 
}

void Curso::insertarReq(char*cad){
    requisitos.push_back(cad);
}

void Curso::imprimirReq(ofstream&out){
    for(int i=0;i<requisitos.size();i++){
        out<<requisitos[i]<<' ';
    }
    out<<endl;
}

void Curso::operator=(const Curso&x){
    char cad[150],*codR;
    x.GetNombre(cad);
    SetNombre(cad);
    x.GetCodigo(cad);
    SetCodigo(cad);
    SetCreditos(x.GetCreditos());
    for(int i=0;i<x.requisitos.size();i++){
        codR = new char[7];
        strcpy(codR,x.requisitos[i]);
        insertarReq(codR);
    }
}

bool Curso::operator==(const Curso&x){
    char cad1[150], cad2[150];
    x.GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)==0);
}

bool Curso::operator>(const Curso&x){
    char cad1[150], cad2[150];
    x.GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)>0);
}

bool Curso::operator<(const Curso&x){
    char cad1[150], cad2[150];
    x.GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)<0);
}


ofstream& operator<<(ofstream&out, Curso&x){
    char cad[150];
    x.GetCodigo(cad);
    out<<cad<<' ';
    x.GetNombre(cad);
    out<<cad<<' ';
    out<<x.GetCreditos()<<endl;
    x.imprimirReq(out);
    return out;
}

void operator>>(ifstream&, Curso&){

}

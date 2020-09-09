/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 7:26 AM
 */

#include "Infraccion.h"

Infraccion::Infraccion() {
    descripcion=NULL;
    gravedad=NULL;
}

Infraccion::Infraccion(const Infraccion& orig) {
    descripcion=NULL;
    gravedad=NULL;
    *this=orig;
}

Infraccion::~Infraccion() {
    if (descripcion != NULL) delete descripcion;
    if (gravedad != NULL) delete gravedad;
}

void Infraccion::SetMonto(double monto) {
    this->monto = monto;
}

double Infraccion::GetMonto() const {
    return monto;
}

void Infraccion::SetGravedad(const char* cad) {
    if (cad == NULL) return;
    if (gravedad != NULL) delete gravedad;
    gravedad = new char[strlen(cad) + 1];
    strcpy(gravedad, cad); 
}

void Infraccion::GetGravedad(char* cad) const {
    if (gravedad == NULL)
        return;
    strcpy(cad, gravedad); 
}

void Infraccion::SetDescripcion(const char* cad) {
    if (cad == NULL) return;
    if (descripcion != NULL) delete descripcion;
    descripcion = new char[strlen(cad) + 1];
    strcpy(descripcion, cad); 
}

void Infraccion::GetDescripcion(char* cad) const {
    if (descripcion == NULL)
        return;
    strcpy(cad, descripcion); 
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::leer(ifstream&in){
    int cod;
    char cad[200];
    double monto;
    in>>cod;
    if(in.eof())return;
    SetCodigo(cod);
    in.get();
    in.getline(cad,200,',');
    SetDescripcion(cad);
    in.getline(cad,200,',');
    SetGravedad(cad);
    in>>monto;
    in.get();
    SetMonto(monto);
}

void Infraccion::imprimir(ofstream&out){
    char cad[200];
    out<<GetCodigo()<<' ';
    GetDescripcion(cad);
    out<<setw(60)<<cad<<' ';
    GetGravedad(cad);
    out<<setw(10)<<cad<<' ';
    out<<GetMonto();
}



void Infraccion::operator=(const Infraccion&a) {
    char cad[200];
    SetCodigo(a.GetCodigo());
    a.GetDescripcion(cad);
    SetDescripcion(cad);
    a.GetGravedad(cad);
    SetGravedad(cad);
    SetMonto(a.GetMonto());
}

bool Infraccion::operator==(int v) {
    return ( GetCodigo()==v);
}

bool Infraccion::operator==(const Infraccion&a) {
    return ( GetCodigo()==a.GetCodigo());
}

bool Infraccion::operator>(const Infraccion&a) {
    return ( GetCodigo()>a.GetCodigo());
}

bool Infraccion::operator<(const Infraccion&a) {
    return ( GetCodigo()<a.GetCodigo());
}

double Infraccion::operator++(void){
    return GetMonto();
}

ofstream& operator<<(ofstream&out, Infraccion&c){
    c.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Infraccion&c){
    c.leer(in);
}

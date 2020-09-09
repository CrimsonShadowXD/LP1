/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: crimson
 * 
 * Created on July 12, 2020, 10:29 PM
 */

#include "Libro.h"

Libro::Libro() {
    codigo=nullptr;
    titulo=nullptr;    
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetMonto(double monto) {
    this->monto = monto;
}

double Libro::GetMonto() const {
    return monto;
}

void Libro::SetNVend(int nVend) {
    this->nVend = nVend;
}

int Libro::GetNVend() const {
    return nVend;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetTitulo(const char* cad) {
    if (cad == NULL) return;
    if (titulo != NULL) delete titulo;
    titulo = new char[strlen(cad) + 1];
    strcpy(titulo, cad);
}

void Libro::GetTitulo(char* cad) const {
    if (titulo == NULL)
        return;
    strcpy(cad, titulo);
}

void Libro::SetCodigo(const char* cad) {
    if (cad == NULL) return;
    if (codigo != NULL) delete codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Libro::GetCodigo(char* cad) const {
    if (codigo == NULL)
        return;
    strcpy(cad, codigo);
}

void Libro::operator ++(void){
    SetNVend(GetNVend()+1);
    SetMonto(GetPrecio()+GetMonto());
}

void Libro::operator ++(int){
    SetNVend(GetNVend()+1);
    SetMonto(GetPrecio()+GetMonto());
}

void Libro::operator=(const Libro&orig){
    char cad[150];
    SetMonto(orig.GetMonto());
    SetNVend(orig.GetNVend());
    SetPrecio(orig.GetPrecio());
    orig.GetTitulo(cad);
    SetTitulo(cad);
    orig.GetCodigo(cad);
    SetCodigo(cad);
    list<Autor>::iterator it;
}

ofstream& operator<<(ofstream&out, Libro&l){
    
}

void operator>>(ifstream&in, Libro&l){
    
}

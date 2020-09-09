/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: crimson
 * 
 * Created on July 18, 2020, 3:40 PM
 */

#include "Libro.h"

Libro::Libro() {
    codigo=NULL;
    titulo=NULL;
    nVend=0;
    precio=-1;
}

Libro::Libro(const Libro& orig) {
    codigo=NULL;
    titulo=NULL;
    precio=-1;
    *this=orig;
}

Libro::~Libro() {
}

void Libro::SetNVend(int nVend) {
    this->nVend = nVend;
}

int Libro::GetNVend() const {
    return nVend;
}

void Libro::SetMonto(double monto) {
    this->monto = monto;
}

double Libro::GetMonto() const {
    return monto;
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

void Libro::MeterLibro(const Autor&a){
    autores.push_back(a);
}

void Libro::ImprimirAutores(ofstream&out){
    if(autores.empty())out<<setw(15)<<"vacio"<<endl;
    list<Autor>::iterator it;
    for(it=autores.begin();it!=autores.end();it++){
        if(it==autores.begin()){
            out<<*it<<' ';
            out<<GetPrecio()<<setw(6)<<' '<<GetNVend()<<setw(6)<<' '<<GetMonto()<<endl;
        }
        else{
            out<<setw(68)<<' ';
            out<<*it<<endl;
        }
    }
    out<<endl;
}

void Libro::operator=(const Libro&a) {
    char cad[150],cad2[7];
    a.GetCodigo(cad2);
    SetCodigo(cad2);
    a.GetTitulo(cad);
    SetTitulo(cad);
    SetMonto(a.GetMonto());
    SetNVend(a.GetNVend());
    SetPrecio(a.GetPrecio());
    autores=a.autores;
    autores.sort();
}

void Libro::operator++(void) {
    SetMonto(GetMonto()+GetPrecio());
    SetNVend(GetNVend()+1);
}

bool Libro::operator==(const Libro&a) {
    char cad1[150], cad2[150];
    GetCodigo(cad1);
    a.GetCodigo(cad2);
    return (strcmp(cad1, cad2) == 0);
}

bool Libro::operator>(const Libro&a) {
    char cad1[150], cad2[150];
    GetCodigo(cad1);
    a.GetCodigo(cad2);
    return (strcmp(cad1, cad2) > 0);
}

bool Libro::operator<(const Libro&a) {
    char cad1[150], cad2[150];
    GetCodigo(cad1);
    a.GetCodigo(cad2);
    return (strcmp(cad1, cad2) < 0);
}

ofstream& operator<<(ofstream&out, Libro&l){
    char cad[150];
    l.GetCodigo(cad);
    out<<cad<<' ';
    l.GetTitulo(cad);
    out<<left<<setw(60)<<cad<<right<<' ';
    l.ImprimirAutores(out);
    out<<endl;
    return out;
}

void operator>>(ifstream&in, Libro&l){
    char cad[150];
    double p;
    in.getline(cad,150,',');
    l.SetCodigo(cad);
    in.getline(cad,150,',');
    l.SetTitulo(cad);
    in>>p;
    l.SetPrecio(p);
    in>>ws;
}

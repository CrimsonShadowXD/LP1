/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:30 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include "Libro.h"
#define N 256
using namespace std;

Libro::Libro() {
    nVend = 0;
    monto = 0;
    codigo = titulo = NULL;
}

Libro::Libro(const Libro& orig) {
    char cod[N], tit[N];
    nVend = 0;
    monto = 0;
    codigo = titulo = NULL;
    orig.GetCodigo(cod);
    orig.GetTitulo(tit);
    if(cod[0]!=0) //Se coloca solo si no devolvio cadena vacia
        SetCodigo(cod);
    SetMonto(orig.GetMonto());
    SetNVend(orig.GetNVend());
    SetPrecio(orig.GetPrecio());
    if(tit[0]!=0) //Se coloca solo si no devolvio cadena vacia 
        SetTitulo(tit);
}

Libro::~Libro() {
    if(codigo) delete[]codigo;
    if(titulo) delete[]titulo;
    nVend = 0;
    monto = 0;
    codigo = titulo = NULL;
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

void Libro::SetTitulo(const char* titulo) {
    if(this->titulo!=NULL) delete[]this->titulo;
    this->titulo = new char[strlen(titulo)+1];
    strcpy(this->titulo, titulo);
}

void Libro::GetTitulo(char * tit) const {
    if(titulo == NULL) tit[0] = 0; //Para saber que esta 'vacio' el objeto
    else strcpy(tit, titulo);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo!=NULL) delete[]this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void Libro::GetCodigo(char * cod) const {
    if(codigo == NULL) cod[0] = 0; //Para saber que esta 'vacio' el objeto
    else strcpy(cod, codigo);
}

void Libro::SetAutor(int dni, const char* nomb) {
    Autor autor; //Objeto autor auxiliar
    autor.SetDni(dni);
    autor.SetNombre(nomb);
    autores.push_back(autor); //Insertamos el nuevo autor
    autores.sort(); //Ordenamos la lista luego de insertar
}

void Libro::GetAutor(int& dni, char* nomb, int pos) {
    list < Autor >::iterator it;
    int i = 0;
    for(it = autores.begin(); it != autores.end(); it++){
        if(i == pos){
            dni = (*it).GetDni();
            (*it).GetNombre(nomb);
            return;
        }
        i++;
    }
    nomb[0] = 0; //No se encontro nada
}

bool Libro::operator<(const Libro& lib) {
    strcmp(codigo, lib.codigo) < 0;
}

bool Libro::operator==(const Libro& lib) {
    strcmp(codigo, lib.codigo) == 0;
}

bool Libro::operator>(const Libro& lib) {
    strcmp(codigo, lib.codigo) > 0;
}

void Libro::operator=(const Libro& orig) {
    char cod[N], tit[N];
    orig.GetCodigo(cod);
    orig.GetTitulo(tit);
    if(cod[0]!=0) //Se coloca solo si no devolvio cadena vacia
        SetCodigo(cod);
    SetMonto(orig.GetMonto());
    SetNVend(orig.GetNVend());
    SetPrecio(orig.GetPrecio());
    if(tit[0]!=0) //Se coloca solo si no devolvio cadena vacia 
        SetTitulo(tit);
}

ifstream & operator >>(ifstream & in, Libro & lib){
    char cod[N], tit[N];
    double precio;
    in.getline(cod, N , ',');
    if(in.eof()) return in;
    in.getline(tit, N, ',');
    in >> precio >> ws;
    lib.SetPrecio(precio);
    lib.SetTitulo(tit);
    lib.SetCodigo(cod);
    return in;
}

void Libro::operator++() {
    SetNVend(GetNVend()+1);
    SetMonto(GetPrecio()+GetMonto());
}

void Libro::operator++(int) {
    SetNVend(GetNVend()+1);
    SetMonto(GetPrecio()+GetMonto());
}

ofstream & operator <<(ofstream &out, Libro &lib){
    char tit[N], cod[N];
    list < Autor >::iterator it;
    int i = 0;
    lib.GetTitulo(tit);
    lib.GetCodigo(cod);
    out << left << setw(10) << cod << setw(60) << tit;
    //Imprimiremos la lista de autores
    for(it = lib.autores.begin(); it != lib.autores.end(); it++){
        if (i==0){
            out << setw(4) << ' ';
            out << (*it); //Imprimimos el autor
            out << setprecision(2) << fixed << setw(10) << lib.GetPrecio()
                << setw(10) << lib.GetNVend() << setw(10) << lib.GetMonto()
                << endl;
        }
        else{
            out << setw(74) << ' ';
            out << (*it); //Imprimimos el autor sin imprimir los datos de libro
            out << endl;
        }
        i++;
    }
    if(lib.autores.size()==0) //Lista vacia
        out << right << setw(56) << lib.GetPrecio() << setw(10) 
            << lib.GetNVend() << setw(10) << lib.GetMonto() << endl;
    return out;
}
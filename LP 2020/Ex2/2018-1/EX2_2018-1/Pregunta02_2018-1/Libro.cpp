/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Libro.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 02:40 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Libro.h"

Libro::Libro() {
     codigo = nullptr;
     titulo = nullptr;
     precio= 0;
     nVend = 0;
     monto= 0;
}

Libro::Libro(const Libro& orig) {
    codigo = nullptr;
    titulo = nullptr;
    *this = orig;
}

Libro::~Libro() {
    if (codigo) delete codigo;
    if (titulo) delete titulo;
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
    if (titulo) delete titulo;
    titulo = new char[strlen(cad)+1];  
    strcpy(titulo,cad);

}

void Libro::GetTitulo(char*cad) const {
    if (titulo == nullptr) cad[0] = 0;
    else strcpy(cad,titulo);
}

void Libro::SetCodigo(const char* cad) {
    if (codigo) delete codigo;
    codigo = new char[strlen(cad)+1];  
    strcpy(codigo,cad);

}

void Libro::GetCodigo(char*cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else strcpy(cad,codigo);

}

void Libro::SetAutor(const int dni, const char* nombre) {
    class Autor a;
    a.SetDni(dni);
    a.SetNombre(nombre);
    autores.push_back(a);
    autores.sort();
}

void Libro::GetAutor(int n, int& dni, char* nombre) {
    list <Autor>::iterator it = autores.begin();
    int i = 0; //buscamos el n-ésimo elemento
    for ( ; it != autores.end() && i<n; i++, it++ );
    if (it != autores.end()){ //significa que encontro el n-esimo elemento
        dni = it->GetDni();
        it->GetNombre(nombre);
    }
    else{
        dni = -1; //indica que no hay tantos autores como n
        nombre[0] = 0;
    }
}

void Libro::EliminaAutores() {
    autores.clear();
}

void Libro::operator++() {
    nVend++;
    monto+=precio;
}

void Libro::imprime(ofstream& arch) {
    arch.precision(2);
    arch<<fixed;
    //datos del libro
    list<Autor>::iterator it = autores.begin();
    arch<<left<<setw(10)<<codigo<<setw(30)<<titulo;
    
    //datos de los autores
    if (autores.size()>0) arch<<*it;
    else arch<<setw(40)<<" ";
      
    //datos relacionado a costos y ventas del libro
    arch<<setw(10)<<precio<<setw(10)<<nVend<<setw(6)<<monto<<endl;
    //resto de los autores
    it++;
    for ( ;  it !=autores.end(); ++it) {
        arch<<left<<setw(50)<<" ";
        arch<<*it;
        arch<<endl;

    }
    for (int i = 0; i < 100; i++) 
        arch<<'-';
    arch<<endl;

}

void operator>>(ifstream & arch,class Libro & lb){
    char cod[10], titulo[100];
    double precio;
    arch.getline(cod,10,',');
    if (arch.eof()) return;
    arch.getline(titulo,100,',');
    arch>>precio;
    arch.get();
    
    lb.SetCodigo(cod);
    lb.SetTitulo(titulo);
    lb.SetPrecio(precio);
}
void operator<<(ofstream &arch,  class Libro & lb){
    lb.imprime(arch);   
}
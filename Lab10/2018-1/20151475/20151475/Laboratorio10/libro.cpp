/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libro.cpp
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:02 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "libro.h"
#include "ArbolBinario.h"

#define N 256
using namespace std;

libro::libro() {
    autor = codigo = titulo = NULL;
    monto = precio = 0;
    nVend = 0;
}


libro::~libro() {
    /*Si existen los atributos que son punteros, se los borra y pone a NULL*/
    if(autor) delete[]autor;
    if(codigo) delete[]codigo;
    if(titulo) delete[]titulo;
    monto = precio = 0;
    nVend = 0;
    /*El profesor dijo que no era necesario, pero en en internet encontre que
     esto era recomendado cada vez que se trabaja con punteros, para evitar
     que hagan caer el programa de maneras extranhas*/
    autor = codigo = titulo = NULL;
}

void libro::SetMonto(double monto) {
    this->monto = monto;
}

double libro::GetMonto() const {
    return monto;
}

void libro::SetNVend(int nVend) {
    this->nVend = nVend;
}

int libro::GetNVend() const {
    return nVend;
}

void libro::SetPrecio(double precio) {
    this->precio = precio;
}

double libro::GetPrecio() const {
    return precio;
}

void libro::SetAutor(const char* autor) {
    if(this->autor!=NULL) delete[]this->autor;
    this->autor = new char[strlen(autor)+1];
    strcpy(this->autor, autor);
}

void libro::GetAutor(char *aut) const {
    if(autor==NULL) aut[0] = 0; //Para saber si el nodo esta vacio
    else strcpy(aut, autor);
}

void libro::SetTitulo(const char* titulo) {
    //Borramos si fue inicializado (en el caso de leer de un archivo a un objeto libro temporal
    if(this->titulo!=NULL) delete[]this->titulo;
    this->titulo = new char[strlen(titulo)+1];
    strcpy(this->titulo, titulo);
}

void libro::GetTitulo(char *tit) const {
    if(titulo==NULL) tit[0] = 0; //Para saber si el nodo esta vacio
    else strcpy(tit, titulo);
}

void libro::SetCodigo(const char* codigo) {
    //Borramos si fue inicializado (en el caso de leer de un archivo a un objeto libro temporal
    if(this->codigo!=NULL) delete[]this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void libro::GetCodigo(char *cod) const {
    if(codigo==NULL) cod[0] = 0;//Para saber si el nodo esta vacio
    else strcpy(cod, codigo);
}

/*Metodos extra*/
void libro::imprimir(ofstream& out) {
    /*Dando formato a la impresion del nodo*/
    out << setprecision(2) << fixed;
    out << setw(10) << codigo << left << setw(4) << ' ' << setw(60) << titulo
        << setw(35) << autor << right << setw(10) << precio << setw(15) << monto
        << setw(10) << nVend << endl;
}

void libro::leerDatos(ifstream& in) {
    char cod[N], tit[N], aut[N];
    double prec;
    in.getline(cod,N,',');//Leemos el codigo del libro
    in.getline(tit,N,',');//Leemos el titulo del libro
    in.getline(aut,N,',');//Leemos el autor del libro
    in >> prec >> ws;//Leemos el precio del libro
    /*Mediante los metodos selectores los copiamos en el objeto apuntado por
     this*/
    SetAutor(aut);
    SetCodigo(cod);
    SetPrecio(prec);
    SetTitulo(tit);
}

/*Sobrecarga de operadores*/
void libro::operator++(int i) {
    SetNVend(GetNVend()+1);//nVend++
    SetMonto(GetMonto()+GetPrecio()); //monto += precio;   
}

ofstream& operator<<(ofstream& out, libro& lib) {
    lib.imprimir(out);//Llamamos al metodo imprimir de libro
    return out;
}

ifstream& operator>>(ifstream& in, libro& lib) {
    lib.leerDatos(in); //Llamamos al metodo leer de libro
    return in;
}

bool libro::operator<(const libro& lib) {
    return strcmp(codigo, lib.codigo)<0;//Ordenado de menor a mayor
}

void libro::operator=(const libro& lib) {
    //Se sobrecargara para poder asignar a un nodo
    char cod[N], tit[N], aut[N];
    lib.GetAutor(aut);//obtenemos el nombre del autor
    lib.GetCodigo(cod);//obtenemos el codigo del libro
    lib.GetTitulo(tit);//obtenemos el titulo del libro
    /*Mediante los metodos selectores los copiamos en el objeto apuntado por 
     * this*/
    SetAutor(aut);
    SetCodigo(cod);
    SetMonto(lib.GetMonto());
    SetNVend(lib.GetNVend());
    SetPrecio(lib.GetPrecio());
    SetTitulo(tit);
}

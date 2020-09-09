/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:12 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Autor.h"
#define N 256
using namespace std;

Autor::Autor() {
    nombre = NULL;
}

Autor::Autor(const Autor& orig) {
    char nomb[N];
    nombre = NULL;
    orig.GetNombre(nomb);
    SetDni(orig.GetDni());
    if(nomb[0]!=0) //Solo se coloca el nombre si no devolvio cadena vacia
        SetNombre(nomb);
}

Autor::~Autor() {
    if(nombre) delete[]nombre;
    nombre = NULL;
}

void Autor::SetNombre(const char* nombre) {
    if(this->nombre!=NULL) delete[]this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Autor::GetNombre(char *nomb) const {
    if(nombre==NULL) nomb[0] = 0; //Para ver si el nodo esta 'vacio' o no;
    else strcpy(nomb, nombre);
}

void Autor::SetDni(int dni) {
    this->dni = dni;
}

int Autor::GetDni() const {
    return dni;
}

/*operadores sobrecargados*/
bool Autor::operator<(const Autor& aut) {
    return strcmp(nombre, aut.nombre)<0;
}

bool Autor::operator==(const Autor& aut) {
   return strcmp(nombre, aut.nombre)==0;
}

bool Autor::operator>(const Autor& aut) {
   return strcmp(nombre, aut.nombre)>0;
}

ifstream& operator>>(ifstream& in, Autor& aut) {
    int dni;
    char nomb[N];
    in >> dni; 
    if(in.eof()) return in;
    in.get(); //Leemos la coma
    in.getline(nomb, N, ',');
    //Devovlemos la coma para usarla en la lectura de los codigos de los libros creados
    in.unget();
    aut.SetDni(dni);
    aut.SetNombre(nomb);
    return in;
}

ofstream& operator<<(ofstream& out, const Autor& aut) {
    char nomb[N];
    aut.GetNombre(nomb);
    out << left << setw(12) << aut.GetDni() << setw(30) << nomb << right;
    return out;
}

void Autor::operator=(const Autor& orig) {
    char nomb[N];
    orig.GetNombre(nomb);
    SetDni(orig.GetDni());
    if(nomb[0]!=0) //Solo se coloca el nombre si no devolvio cadena vacia
        SetNombre(nomb);
}

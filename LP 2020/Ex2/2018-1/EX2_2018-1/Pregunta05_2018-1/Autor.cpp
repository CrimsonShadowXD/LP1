/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Autor.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 02:32 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Autor.h"

Autor::Autor() {
    dni = 0;
    nombre = nullptr;
}

Autor::Autor(const Autor& orig) {
    nombre = nullptr;
    *this = orig;
}

Autor::~Autor() {
    if (nombre)delete nombre;
}

void Autor::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];  
    strcpy(nombre,cad);
}

void Autor::GetNombre(char*cad ) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad,nombre);
}

void Autor::SetDni(int dni) {
    this->dni = dni;
}

int Autor::GetDni() const {
    return dni;
}

void Autor::operator=(const class Autor& au) {
    char nombre[100];
    au.GetNombre(nombre);
    SetDni(au.GetDni());
    SetNombre(nombre);
}
void operator>>(ifstream &arch,class Autor & au){
    int dni;
    char nom[100];
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nom,100,',');
    while (arch.get()!= '\n');
    au.SetNombre(nom);
    au.SetDni(dni);
}
void operator<<(ofstream &arch, const class Autor &au){
    char nom[100];
    au.GetNombre(nom);
    arch<<left<<setw(15)<<au.GetDni();
    arch<<setw(30)<<nom<<endl;
    
}
bool Autor::operator<(const class Autor& au){
    return (dni < au.GetDni());
}
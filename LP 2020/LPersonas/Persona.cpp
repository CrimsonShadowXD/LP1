/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: cueva
 * 
 * Created on 5 de julio de 2020, 08:08 PM
 */
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Persona.h"

using namespace std;


Persona::Persona() {
    nombre = NULL;

}

Persona::Persona(const Persona &p){
    nombre = NULL;
    *this = p;
}

Persona::~Persona() {
    if (nombre)delete nombre;
}

void Persona::SetNombre(char* nomb) {
    if (nombre)delete nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Persona::GetNombre(char*nomb) const {
    strcpy(nomb, nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}
/*
void Persona::lee(ifstream& arch){
    char buff[100];
    arch >> dni;
    arch.get();
    arch.getline(buff,100,';');
    nombre = new char[strlen(buff)+1];
    strcpy(nombre,buff);
}


void Persona::imprime(ofstream& arch){
    arch << "DNI:"<<dni<<setw(30)<<"Nombre:"<<nombre<<endl;
    
}
*/
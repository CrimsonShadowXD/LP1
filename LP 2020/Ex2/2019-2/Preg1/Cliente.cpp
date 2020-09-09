/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 10:57 AM
 */

#include "Cliente.h"

Cliente::Cliente() {
    nombre=NULL;
    dni=-1;
}

Cliente::Cliente(const Cliente& orig) {
    nombre=NULL;
    dni=-1;
    *this=orig;
}

Cliente::~Cliente() {
    if(nombre!=NULL)delete nombre;
}

void Cliente::SetTiempo(double tiempo) {
    this->tiempo = tiempo;
}

double Cliente::GetTiempo() const {
    return tiempo;
}

void Cliente::SetNombre(const char* cad) {
    if (cad == NULL) return;
    if (nombre != NULL) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad); 
}

void Cliente::GetNombre(char* cad) const {
    if (nombre == NULL)
        return;
    strcpy(cad, nombre); 
}

void Cliente::SetHorallegada(int horallegada) {
    this->horallegada = horallegada;
}

int Cliente::GetHorallegada() const {
    return horallegada;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::leer(ifstream&in){ 
    int n,hh,mm,ss;
    char cad[150],c;
    double m;
    in>>n;
    if(in.eof())return;
    SetDni(n);
    in.get();
    in.getline(cad,150,',');
    SetNombre(cad); 
    in>>hh>>c;
    in>>mm>>c;
    in>>ss>>c;
    SetHorallegada(hh*10000+mm*100+ss);
    in>>m;
    SetTiempo(m);
    in>>ws;
}

void Cliente::imprimir(ofstream&out){
    char cad[150];
    out<<left<<setw(10)<<GetDni();
    GetNombre(cad);
    int n=GetHorallegada();
    out<<setw(50)<<cad<<n/10000<<':'<<(n%10000)/100<<':'<<n%100<<setw(10)<<' '<<GetTiempo()<<endl;
}


void Cliente::operator=(const Cliente&a) {
    char cad[150];
    a.GetNombre(cad);
    SetNombre(cad);
    SetDni(a.GetDni());
    SetHorallegada(a.GetHorallegada());
    SetTiempo(a.GetTiempo());
}

bool Cliente::operator==(const Cliente&a) {
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1, cad2) == 0);
}

bool Cliente::operator>(const Cliente&a) {
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1, cad2) > 0);
}

bool Cliente::operator<(const Cliente&a) {
    char cad1[150], cad2[150];
    GetNombre(cad1);
    a.GetNombre(cad2);
    return (strcmp(cad1, cad2) < 0);
}

ofstream& operator<<(ofstream&out, Cliente&c) {
    c.imprimir(out);
    return out;
}

void operator>>(ifstream&in, Cliente&c) {
    c.leer(in);
}


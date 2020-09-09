/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 4:57 PM
 */

#include "Conductor.h"

Conductor::Conductor() {
    nombre=NULL;
    telefono=-1;
    dni=-1;
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {
}

void Conductor::setTelefono(int telefono) {
    this->telefono = telefono;
}

int Conductor::getTelefono() const {
    return telefono;
}

void Conductor::setNombre(char* cad) {
    if (cad==NULL) return;
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Conductor::getNombre(char* cad) const {
   if(nombre==NULL)
        return;
    strcpy(cad,nombre);
}

void Conductor::setDni(int dni) {
    this->dni = dni;
}

int Conductor::getDni() const {
    return dni;
}

void Conductor::leer(ifstream&in){
    char buff[500];
    int dni,tele;
    in>>dni;
    if(in.eof()){
        return;
    }
    in.get();
    in.getline(buff,500,',');
    in>>tele;
    in.get();
    
    setNombre(buff);
    setDni(dni);
    setTelefono(tele);
    
    this->vehiculos.crear(in);
}

void Conductor::imprimir(ofstream&out){
    out<<nombre<<endl;
    out<<dni<<endl;
    out<<telefono<<endl;
    this->vehiculos.imprimir(out);
    
}

bool Conductor::operator >(Conductor v){
    return(dni>v.dni);
}

void Conductor::cargaInfracc(char *cad,int infr){
    vehiculos.cargarinfr(cad,infr);
}

void Conductor::ObtenerM(){
    
}
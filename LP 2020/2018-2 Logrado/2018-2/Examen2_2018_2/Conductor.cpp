/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Rodrigo
 * 
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include "Conductor.h"
#include <cstring>
#include <iostream>
using namespace std;

Conductor::Conductor() {
    nombre=NULL;
    dni=0;
    telefono=0;
}


Conductor::~Conductor(){
    
}
    
    void Conductor::setNombre(char* entrada){
        nombre = new char [strlen(entrada)+1];
        strcpy(nombre,entrada);
    }   
    
    char* Conductor::getNombre(){
        char *aux;
        aux = new char [strlen(nombre)+1];
        strcpy(aux,nombre);
        return aux;
    }
    void Conductor::setDni(int entrada){
        dni = entrada;
    }
    
    int Conductor::getDni(){
        return dni;        
    }
    
    void Conductor::setTelefono(int entrada){
        telefono = entrada;
    }
    int Conductor::getTelefono(){
        return telefono;        
    }
    
    void Conductor::multar(char* placa, int codigo){
        vehiculos.multar(placa,codigo);        
    }
    
    bool Conductor::operator >(Conductor b){
        return (dni>b.dni);
    }
    
    void Conductor::leer(ifstream &in){
        char buff[500]; int dni,telefono;
        in>>dni; if(in.eof()) return;     
        in.get();
        in.getline(buff,500,',');
        in>>telefono; in.get(); 
        
        setDni(dni); setTelefono(telefono); setNombre(buff);
        this->vehiculos.crear(in);
    }
    
    void Conductor::imprimir(ofstream &out){
        out<<"Nombre: "<<nombre<<endl;
        out<<"DNI: "<<dni<<" | Telefono: "<<telefono<<endl;
        vehiculos.imprimir(out);
    }

    int* Conductor::obtenerMultas(){
        return vehiculos.obtenerMultas();
    }
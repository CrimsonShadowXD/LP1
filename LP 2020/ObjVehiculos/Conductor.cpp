/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: cueva
 * 
 * Created on 24 de junio de 2020, 12:28 PM
 */
#include <iostream>
#include <cstring>
#include "Conductor.h"

Conductor::Conductor() {
    nombre = NULL;  //No olvidar inicializar
    cantfaltas = 0;
}

Conductor::Conductor(const Conductor& orig) {
    
}

Conductor::~Conductor() {
}

void Conductor::SetCantfaltas(int cantfaltas) {
    this->cantfaltas = cantfaltas;
}

int Conductor::GetCantfaltas() const {
    return cantfaltas;
}

void Conductor::SetBrevete(int brevete) {
    this->brevete = brevete;
}

int Conductor::GetBrevete() const {
    return brevete;
}

void Conductor::SetNombre(char* cad) {
    if(nombre !=NULL ) delete[] nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Conductor::GetNombre(char *nom) const {
    strcpy(nom,nombre);
}

void Conductor::SetDni(int dni) {
    this->dni = dni;
}

int Conductor::GetDni() const {
    return dni;
}

void Conductor::insfaltas(const Faltas &f){ //inserntando nueva falta al arreglo
    lfaltas[cantfaltas] = f;
    cantfaltas++;
}

void Conductor::operator +(const Faltas &f){
    insfaltas(f);
}

float Conductor::operator ++ (int){
    float suma=0;
    for(int i=0;i<cantfaltas;i++)
        suma =suma +lfaltas[i].GetMulta();
    return suma;
}
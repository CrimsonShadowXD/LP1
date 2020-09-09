/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculos.cpp
 * Author: crimson
 * 
 * Created on July 20, 2020, 6:23 AM
 */

#include "Vehiculos.h"

Vehiculos::Vehiculos() {
    placa=NULL;
}

Vehiculos::Vehiculos(const Vehiculos& orig) {
}

Vehiculos::~Vehiculos() {
}

void Vehiculos::SetPlaca(const char* cad) {
    if (cad == NULL) return;
    if (placa != NULL) delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Vehiculos::GetPlaca(char* cad) const {
    if (placa == NULL)
        return;
    strcpy(cad, placa);
}

void Vehiculos::leer(ifstream&in){
    char cad[8];
    in.get(cad,8);
    SetPlaca(cad);
}

void Vehiculos::imprimir(ofstream&out){ 
    char cad[8];
    GetPlaca(cad);
    out<<cad<<' ';
}

int* Vehiculos::DevolverFaltas(){
    int *aux,i=0;
    aux=new int[infracciones.size()+2];
    list<int>::iterator it;
    for(it=infracciones.begin();it!=infracciones.end();it++){
        aux[i]=*it;
        i++;
    }
    aux[i]=-1;
    return aux;
}
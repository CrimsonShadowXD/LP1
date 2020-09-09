/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 4:58 PM
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa=NULL;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetPlaca(char* cad) {
    if (cad==NULL) return;
    if(placa!=NULL) delete placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Vehiculo::GetPlaca(char* cad) const {
    if(placa==NULL)
        return;
    strcpy(cad,placa);
}

void Vehiculo::leer(ifstream&in){
    char *plac=new char[8];
    in.get(plac,8);
    SetPlaca(plac);
}

void Vehiculo::imprimir(ofstream&out){
    out<<placa<<endl;
    if(infracciones.empty()){
        out<<"Vacio"<<endl;
    }
    else{
        list<int>::iterator it;
        for(it=infracciones.begin();it!=infracciones.end();it++){
            out<<*it<<' ';
        }
        out<<endl;
    }
}

bool Vehiculo::operator >(Vehiculo v){
    return(strcmp(placa,v.placa)>0);
}

void Vehiculo::anadir(int infr){
    infracciones.push_back(infr);
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infracciones.cpp
 * Author: crimson
 * 
 * Created on July 5, 2020, 11:10 PM
 */

#include "Infracciones.h"

Infracciones::Infracciones() {
    cod=-1;
    Desc=NULL;
    Grav=NULL;
    monto=-0.1;
}

Infracciones::Infracciones(const Infracciones& orig) {
}

Infracciones::~Infracciones() {
}

void Infracciones::setMonto(float monto) {
    this->monto = monto;
}

float Infracciones::getMonto() const {
    return monto;
}

void Infracciones::setGrav(char* cad) {
    if (cad==NULL) return;
    if(Grav!=NULL) delete Grav;
    Grav = new char[strlen(cad)+1];
    strcpy(Grav,cad);
}

void Infracciones::getGrav(char* cad) const {
    if(Grav==NULL)
        return;
    strcpy(cad,Grav);
}

void Infracciones::setDesc(char* cad) {
    if (cad==NULL) return;
    if(Desc!=NULL) delete Desc;
    Desc = new char[strlen(cad)+1];
    strcpy(Desc,cad);
}

void Infracciones::getDesc(char* cad) const {
    if(Desc==NULL)
        return;
    strcpy(cad,Desc);
}

void Infracciones::setCod(int cod) {
    this->cod = cod;
}

int Infracciones::getCod() const {
    return cod;
}

void Infracciones::leer(ifstream&in){
    int cod;
    char cad[500];
    float monto;
    
    in>>cod;
    setCod(cod);
    in.get();
    
    in.getline(cad,500,',');
    setDesc(cad);
    
    in.getline(cad,500,',');
    setGrav(cad);
    
    in>>monto;
    setMonto(monto);
}

void Infracciones::imprimir(ofstream&out){
    cout<<cod<<' ';
    cout<<Desc<<' ';
    cout<<Grav<<' ';
    cout<<monto<<endl;
}

bool Infracciones::operator >(Infracciones infr){
    return (cod>infr.cod);
}
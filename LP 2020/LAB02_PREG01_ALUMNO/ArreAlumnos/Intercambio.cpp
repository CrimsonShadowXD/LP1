/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.cpp
 * Author: cueva
 * 
 * Created on 1 de julio de 2020, 12:58 PM
 */

#include <iostream>
#include <cstring>
#include "Intercambio.h"

Intercambio::Intercambio() {
    pais=NULL;
    idioma=NULL;
    tiempo=0;
}

Intercambio::Intercambio(const Intercambio& orig) {
}

Intercambio::~Intercambio() {
}

void Intercambio::SetTiempo(int tiempo) {
    this->tiempo = tiempo;
}

int Intercambio::GetTiempo() const {
    return tiempo;
}

void Intercambio::SetIdioma(char* cad) {
    if (cad==NULL) return;
    if(idioma!=NULL) delete idioma;
    idioma = new char[strlen(cad)+1];
    strcpy(idioma,cad);
}

void Intercambio::GetIdioma(char *cad) const {
    strcpy(cad,idioma);
}

void Intercambio::SetPais(char* cad) {
    if (cad==NULL) return;
    if(pais!=NULL) delete pais;
    pais = new char[strlen(cad)+1];
    strcpy(pais,cad);
}

void Intercambio::GetPais(char *cad) const {
    
    strcpy(cad,pais);
}


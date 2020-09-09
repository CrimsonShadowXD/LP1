/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: crimson
 * 
 * Created on July 16, 2020, 1:26 PM
 */

#include "Persona.h"

Persona::Persona() {
    nom=NULL;
    dist=NULL;
    cod=-1;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

void Persona::SetCod(int cod) {
    this->cod = cod;
}

int Persona::GetCod() const {
    return cod;
}

void Persona::SetDist(const char* cad) {
    if (cad == NULL) return;
    if (dist != NULL) delete dist;
    dist = new char[strlen(cad) + 1];
    strcpy(dist, cad);
}

void Persona::GetDist(char* cad) const {
    if (dist == NULL)
        return;
    strcpy(cad, dist);
}

void Persona::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Persona::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}


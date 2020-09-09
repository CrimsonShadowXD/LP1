/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autor.cpp
 * Author: crimson
 * 
 * Created on July 12, 2020, 9:50 PM
 */

#include "Autor.h"

Autor::Autor() {
}

Autor::Autor(const Autor& orig) {
}

Autor::~Autor() {
}

void Autor::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Autor::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void Autor::SetDni(int dni) {
    this->dni = dni;
}

int Autor::GetDni() const {
    return dni;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 4:48 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    nom=NULL;
}

Alumno::Alumno(const Alumno& orig) {
    nom=NULL;
    *this=orig;
}

Alumno::~Alumno() {
}

void Alumno::SetNom(const char* cad) {
    if (cad == NULL) return;
    if (nom != NULL) delete nom;
    nom = new char[strlen(cad) + 1];
    strcpy(nom, cad);
}

void Alumno::GetNom(char* cad) const {
    if (nom == NULL)
        return;
    strcpy(cad, nom);
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetCod(int cod) {
    this->cod = cod;
}

int Alumno::GetCod() const {
    return cod;
}

void Alumno::operator=(const Alumno&a){
    char cad[150];
    a.GetNom(cad);
    SetNom(cad);
    SetCod(a.GetCod());
    SetEscala(a.GetEscala());
}

ofstream& operator<<(ofstream&out, Alumno&a){
    char cad[150];
    a.GetNom(cad);
    out<<cad<<' ';
    out<<a.GetCod()<<' '<<a.GetEscala()<<endl;
    return out;
}

void operator>>(ifstream&in, Alumno&a){
    char cad[150];
    int cod,escala;
    in.getline(cad,150,',');a.SetNom(cad);
    in>>cod;a.SetCod(cod);
    in.get();
    in.getline(cad,150,',');
    in>>escala;a.SetEscala(escala);
    in.getline(cad,150);
}

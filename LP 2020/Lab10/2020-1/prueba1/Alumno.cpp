/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 16, 2020, 1:26 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    esp=NULL;
    fac=NULL;    
    escala=-1;
}

Alumno::Alumno(const Alumno& orig) {
    esp=NULL;
    fac=NULL;    
    escala=-1;
    *this=orig;
}

Alumno::~Alumno() {
    
}

void Alumno::SetFac(const char* cad) {
    if (cad == NULL) return;
    if (fac != NULL) delete fac;
    fac = new char[strlen(cad) + 1];
    strcpy(fac, cad);
}

void Alumno::GetFac(char* cad) const {
    if (fac == NULL)
        return;
    strcpy(cad, fac);
}

void Alumno::SetEsp(const char* cad) {
    if (cad == NULL) return;
    if (esp != NULL) delete esp;
    esp = new char[strlen(cad) + 1];
    strcpy(esp, cad);
}

void Alumno::GetEsp(char* cad) const {
    if (esp == NULL)
        return;
    strcpy(cad, esp);
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::operator=(const Alumno&a){
    char cad[150];
    a.GetNom(cad);
    SetNom(cad);
    a.GetDist(cad);
    SetDist(cad);
    a.GetEsp(cad);
    SetEsp(cad);
    a.GetFac(cad);
    SetFac(cad);
    SetCod(a.GetCod());
    SetEscala(a.GetEscala());
}

bool Alumno::operator>(const Alumno&a){
    char cad1[150],cad2[150];
    GetNom(cad1);
    a.GetNom(cad2);
    return (strcmp(cad1,cad2)>0);
}

bool Alumno::operator<(const Alumno&a){
    char cad1[150],cad2[150];
    GetNom(cad1);
    a.GetNom(cad2);
    return (strcmp(cad1,cad2)<0);
}

ofstream& operator<<(ofstream&out, Alumno&a){
    char cad[150];
    a.GetNom(cad);
    out<<cad<<' '<<a.GetCod()<<' ';
    a.GetDist(cad);
    out<<cad<<' '<<a.GetEscala()<<' ';
    a.GetEsp(cad);
    out<<cad<<' ';
    a.GetFac(cad);
    out<<cad<<endl;
    return out;
}

void operator>>(ifstream&in, Alumno&a){
    char cad[150];
    int escala,cod;
    
    in.getline(cad,150,',');
    a.SetNom(cad);
    in>>cod;
    in.get();
    a.SetCod(cod);
    in.getline(cad,150,',');
    a.SetDist(cad);
    in>>escala;
    in.get();
    in.getline(cad,150,',');
    a.SetEsp(cad);
    in.getline(cad,150);
    a.SetFac(cad);
    a.SetEscala(escala);
}

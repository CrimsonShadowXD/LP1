/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Profesor.cpp
 * Author: crimson
 * 
 * Created on July 16, 2020, 1:26 PM
 */

#include "Profesor.h"

Profesor::Profesor() {    
    cate=NULL;
    dedi=NULL;
    secc=NULL;
    grado=NULL;
}

Profesor::Profesor(const Profesor& orig) {
   cate=NULL;
    dedi=NULL;
    secc=NULL;
    grado=NULL;
    *this=orig;
}

Profesor::~Profesor() {
}

void Profesor::SetGrado(const char* cad) {
    if (cad == NULL) return;
    if (grado != NULL) delete grado;
    grado = new char[strlen(cad) + 1];
    strcpy(grado, cad);
}

void Profesor::GetGrado(char* cad) const {
    if (grado == NULL)
        return;
    strcpy(cad, grado);
}

void Profesor::SetSecc(const char* cad) {
    if (cad == NULL) return;
    if (secc != NULL) delete secc;
    secc = new char[strlen(cad) + 1];
    strcpy(secc, cad);
}

void Profesor::GetSecc(char* cad) const {
    if (secc == NULL)
        return;
    strcpy(cad, secc);
}

void Profesor::SetDedi(const char* cad) {
    if (cad == NULL) return;
    if (dedi != NULL) delete dedi;
    dedi = new char[strlen(cad) + 1];
    strcpy(dedi, cad);
}

void Profesor::GetDedi(char* cad) const {
    if (dedi == NULL)
        return;
    strcpy(cad, dedi);
}

void Profesor::SetCate(const char* cad) {
    if (cad == NULL) return;
    if (cate != NULL) delete cate;
    cate = new char[strlen(cad) + 1];
    strcpy(cate, cad);
}

void Profesor::GetCate(char* cad) const {
    if (cate == NULL)
        return;
    strcpy(cad, cate);
}

void Profesor::operator=(const Profesor&p){
    char cad[150];
    p.GetNom(cad);
    SetNom(cad);
    p.GetDist(cad);
    SetDist(cad);
    SetCod(p.GetCod());
    p.GetCate(cad);
    SetCate(cad);
    p.GetDedi(cad);
    SetDedi(cad);
    p.GetGrado(cad);
    SetGrado(cad);
    p.GetSecc(cad);
    SetSecc(cad);
}

bool Profesor::operator>(const Profesor&p){
    char cad1[150],cad2[150];
    GetNom(cad1);
    p.GetNom(cad2);
    return (strcmp(cad1,cad2)>0);

}

bool Profesor::operator<(const Profesor&p){
    char cad1[150],cad2[150];
    GetNom(cad1);
    p.GetNom(cad2);
    return (strcmp(cad1,cad2)<0);
}

ofstream& operator<<(ofstream&out, Profesor&p){
    char cad[150];
    p.GetNom(cad);
    out<<cad<<' '<<p.GetCod()<<' ';
    p.GetDist(cad);
    out<<cad<<' ';
    p.GetCate(cad);
    out<<cad<<' ';
    p.GetDedi(cad);
    out<<cad<<' ';
    p.GetGrado(cad);
    out<<cad<<endl;
    return out;
}

void operator>>(ifstream&in, Profesor&p){
    char cad[150];
    int escala,cod;
    
    in.getline(cad,150,',');
    p.SetNom(cad);
    in>>cod;
    in.get();    
    p.SetCod(cod);
    in.getline(cad,150,',');
    p.SetDist(cad);    
    in.getline(cad,150,',');
    p.SetCate(cad);
    in.getline(cad,150,',');
    p.SetDedi(cad);
    in.getline(cad,150,',');
    p.SetSecc(cad);
    in.getline(cad,150);
    p.SetGrado(cad);
}

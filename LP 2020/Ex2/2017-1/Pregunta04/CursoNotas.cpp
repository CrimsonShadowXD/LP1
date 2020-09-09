/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoNotas.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 7:03 PM
 */

#include "CursoNotas.h"

CursoNotas::CursoNotas() {
    codigo=NULL;
}

CursoNotas::CursoNotas(const CursoNotas& orig) {
    codigo=NULL;
    *this=orig;
}

CursoNotas::~CursoNotas() {
}

void CursoNotas::SetNota(int nota) {
    this->nota = nota;
}

int CursoNotas::GetNota() const {
    return nota;
}

void CursoNotas::SetCodigo(const char* cad) {
    if (cad == NULL) return;
    if (codigo != NULL) delete codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad); 
}

void CursoNotas::GetCodigo(char* cad) const {
    if (codigo == NULL)
        return;
    strcpy(cad, codigo); 
}

void CursoNotas::operator=(const CursoNotas&x ){
    char cad[150];
    x.GetCodigo(cad);
    SetCodigo(cad);
    SetNota(x.GetNota());
}

bool CursoNotas::operator==(const CursoNotas&x){
    char cad2[20],cad1[20];
    GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)==0);
}

bool CursoNotas::operator>(const CursoNotas&x){
    char cad2[20],cad1[20];
    GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)>0);
}

bool CursoNotas::operator<(const CursoNotas&x){
    char cad2[20],cad1[20];
    GetCodigo(cad1);
    x.GetCodigo(cad2);
    return (strcmp(cad1,cad2)<0);
}

ofstream& operator<<(ofstream&out, CursoNotas&x){
    char cad[20];
    x.GetCodigo(cad);
    out<<cad<<' '<<x.GetNota()<<endl;
    return out;
}


void operator>>(ifstream&in, CursoNotas&x){
    char cad[20];
    int n;
    in.getline(cad,20,',');
    x.SetCodigo(cad);
    in>>n;
    x.SetNota(n);
    in>>ws;
}


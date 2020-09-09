/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 8:41 PM
 */

#include "Curso.h"

Curso::Curso() {
    codigo=NULL;
    nombre = NULL;
}

Curso::Curso(const Curso& orig) {
}

Curso::~Curso() {
    if(codigo) delete codigo;
    if(nombre) delete nombre; 
}

void Curso::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Curso::GetCreditos() const {
    return creditos;
}

void Curso::SetNombre(const char* nom) {
    if(nombre) delete nombre;
    nombre = new char[strlen(nom)+1];
    strcpy(nombre,nom);
}

void Curso::GetNombre(char* nom) const {
    strcpy(nom,nombre);
}

void Curso::SetCodigo(const char* cod) {
    if(codigo) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Curso::GetCodigo(char* cod) const {
    strcpy(cod,codigo);
}

void Curso::leer(ifstream&archCur) {
    char cod[10],nom[100],c,cadena[500],*codReq;
    double cred;
    c=archCur.peek();
    archCur.getline(cod,10,',');
    archCur.getline(nom,100,',');
    archCur>>cred;
    c= archCur.get();
    archCur.getline(cadena,500);
    
    SetCodigo(cod);
    SetCreditos(cred);
    SetNombre(nom);
    int lon = strlen(cadena);
    for(int i=0;i<lon;i+=7){
        cadena[i+6] = 0;
        codReq = new char[7];
        strcpy(codReq,&cadena[i]);
        requisitos.push_back(codReq);
    }
    c=archCur.peek();
}

void Curso::imprimir(ofstream&out) {
    char cod[10],nom[100],codReq[500];
    double cred;
    out.precision(2);
    out<<fixed;
    
    this->GetCodigo(cod);
    cred = this->GetCreditos();
    this->GetNombre(nom);
    
    strcpy(codReq,requisitos[0]);
    for(int i=1;i<requisitos.size();i++){
        strcat(codReq,"/");
        strcat(codReq,requisitos[i]);        
    }
    
    out<<left<<setw(10)<<cod<<setw(60)<<nom<<setw(10)<<cred<<codReq<<endl;
}

void Curso::operator=(const class Curso& orig) {
    char cod[10],nom[100],*codR;
    double cre;
    orig.GetCodigo(cod);
    this->SetCodigo(cod);
    orig.GetNombre(nom);
    this->SetNombre(nom);
    cre = orig.GetCreditos();
    this->SetCreditos(cre);
    
    for(int i=0;i<orig.requisitos.size();i++){
        codR = new char[7];
        strcpy(codR,orig.requisitos[i]);
        requisitos.push_back(codR);
    }
}
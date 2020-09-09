/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:02 AM
 */

#include "Curso.h"

Curso::Curso() {
    ccurso=NULL;
    ciclo=0;
    nota=0;
    credito=0;
}

Curso::Curso(const Curso& orig) {
    char cod[10];
    orig.GetCodigo(cod);
    this->SetCodigo(cod);
    this->SetCiclo(orig.GetCiclo());
    this->SetCredito(orig.GetCredito());
    this->SetNota(orig.GetNota());
}

Curso::~Curso() {
    
}

void Curso::SetCodigo(char* cad) {
    if(ccurso !=NULL ) 
        delete []ccurso;
    this->ccurso = new char[strlen(cad)+1];
    strcpy(ccurso,cad);
}

void Curso::GetCodigo(char *cod) const {
    if(ccurso==NULL){
        cout<<"ouch"<<endl;
        exit(1);
    }
    strcpy(cod,ccurso);
}

void Curso::SetCredito(float credito) {
    this->credito = credito;
}

float Curso::GetCredito() const {
    return credito;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::GetCiclo() const {
    return ciclo;
}

void Curso::asignar(const Curso &curso){
    char buffCod[10],*PcodCur;
    
    curso.GetCodigo(buffCod);  // error se necesita espacio de memoria o un arreglo
    SetCodigo(buffCod);
    ciclo = curso.ciclo;
    nota = curso.nota;
    credito = curso.credito;
    
}

Curso Curso::operator =(const Curso &curso){
 /*   char buffCod[10],*PcodCur;
    curso.GetCodigo(PcodCur);
    strcpy(buffCod,PcodCur);
    ciclo = curso.ciclo;
    nota = curso.nota;
    credito = curso.credito;
    SetCodigo(buffCod); mejor llamar al anterior que es igual*/ 
    asignar(curso);
    
}

bool Curso::compare(const Curso &curso){
    if(ciclo == curso.ciclo){
        return true;
    }   
    return false;
    
}

bool Curso::operator ==(const Curso &curso){
    if(ciclo == curso.ciclo){
        if(strcmp(ccurso,curso.ccurso)){
            return true;
        }
        else
            return false;
    }
    return false;  
}


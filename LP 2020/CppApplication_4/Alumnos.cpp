/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumnos.cpp
 * Author: crimson
 * 
 * Created on July 2, 2020, 7:33 PM
 */

#include "Alumnos.h"
#include "ACurso.h"

Alumnos::Alumnos() {
    nombre=NULL;
    codigo=-1;
    numcur=0;
}

Alumnos::~Alumnos() {
}

void Alumnos::SetNumcur(int numcur) {
    this->numcur = numcur;
}

int Alumnos::GetNumcur() const {
    return numcur;
}

void Alumnos::SetNombre(char* cad) {
    if(nombre !=NULL ) 
        delete[] nombre;
    this->nombre = new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

void Alumnos::GetNombre(char* cad) const {
    if(nombre==NULL){
        return;
    }
    strcpy(cad,this->nombre);
}

void Alumnos::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Alumnos::GetTipo() const {
    return tipo;
}

void Alumnos::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumnos::GetCodigo() const {
    return codigo;
}

void Alumnos::operator +(const ACurso &clase){
    char cod[10];
    int nota, ciclo;
    float credito;
    
    clase.ObtenerCurso(cod);
    nota=clase.ObtenerNota();
    ciclo=clase.ObtenerCiclo();
    credito=clase.ObtenerCredito();
    
    Curso aux;
    aux.SetCcurso(cod);
    aux.SetCiclo(ciclo);
    aux.SetCredito(credito);
    aux.SetNota(nota);
    lcurso[numcur]=aux;
    numcur++;
}

void Alumnos::operator *(const ACurso &clase){
    char cod[10];
    int nota, ciclo;
    float credito;
    
    clase.ObtenerCurso(cod);
    nota=clase.ObtenerNota();
    ciclo=clase.ObtenerCiclo();
    credito=clase.ObtenerCredito();
    
    Curso aux;
    aux.SetCcurso(cod);
    aux.SetCiclo(ciclo);
    aux.SetCredito(credito);
    aux.SetNota(nota);
    for(int i=0;i<numcur;i++){
        if(lcurso[i]==aux){
            lcurso[i].SetNota(nota);
        }
    }
}

void Alumnos::operator -(const ACurso &clase){
        char cod[10];
    int nota, ciclo;
    float credito;
    
    clase.ObtenerCurso(cod);
    nota=clase.ObtenerNota();
    ciclo=clase.ObtenerCiclo();
    credito=clase.ObtenerCredito();
    
    Curso aux;
    aux.SetCcurso(cod);
    aux.SetCiclo(ciclo);
    aux.SetCredito(credito);
    aux.SetNota(nota);
    int i=0, encontrado=0;
    while(i<numcur && !encontrado){
        if(lcurso[i]==aux){
            for(int j=i;j<numcur;j++){
                lcurso[j]=lcurso[j+1];
            }
            numcur--;
            encontrado=1;
        }
        i++;
    }
}

float Alumnos::operator /(int cicloDato){
    int total=0, cantCur=0;
    for(int i=0;i<numcur;i++){
        if(lcurso[i].GetCiclo()==cicloDato){
            total+=lcurso[i].GetNota();
            cantCur++;
        }
    }  
    if(cantCur){
        return (total/cantCur);
    }
    else return 0;
}

float Alumnos::operator --(int){
    float cred;
    for(int i=0;i<numcur;i++){
        cred+=lcurso[i].GetCredito();
    }
    return cred;
}

float Alumnos::operator ++(int){
    float cred;
    for(int i=0;i<numcur;i++){
        if(lcurso[i].GetNota()>10){
            cred+=lcurso[i].GetCredito();
        }
    }
    return cred;    
}
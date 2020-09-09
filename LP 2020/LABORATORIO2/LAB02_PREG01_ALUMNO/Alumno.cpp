/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:02 AM
 */

#include "Alumno.h"

Alumno::Alumno(){
    codigo=0;
    nombre=NULL;
    numcur=0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}


void Alumno::SetNumcur(int numcur) {
    this->numcur = numcur;
}

int Alumno::GetNumcur() const {
    return numcur;
}

void Alumno::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Alumno::GetTipo() const {
    return tipo;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::operator +(const Acurso &Nuevo){
    Curso AuxCurso;
    AuxCurso=Nuevo.GetClcurso();
    lcurso[numcur] = AuxCurso;
    numcur++;
}

void Alumno::operator *(const Acurso &Nuevo){
    Curso AuxCurso;
    AuxCurso=Nuevo.GetClcurso();
    for (int i=0;i<numcur;i++){
        if(lcurso[i]==AuxCurso){
            lcurso[i]=AuxCurso;
        }
    }
}

void Alumno::operator -(const Acurso &Nuevo){
    Curso AuxCurso;
    AuxCurso=Nuevo.GetClcurso();
    int i=0, encontrado=0;
    while(i<numcur && !encontrado){
        if(lcurso[i]==AuxCurso){
            encontrado=1;
            for(int j=i;j<numcur;j++){
                lcurso[j]=lcurso[j+1];
            }
            numcur--;
        }
        i++;
    }
}

float Alumno::operator /(int ciclo){
    int cant_notas=0, nota_acum=0, aux_ciclo;
    for (int i=0;i<numcur;i++){
        aux_ciclo==lcurso[i].GetCiclo();
        if(aux_ciclo==ciclo){
            nota_acum+=lcurso[i].GetNota();
            cant_notas++;
        }
    }
    if(cant_notas){
        return nota_acum/cant_notas;
    }
    else{
        return 0;
    }
            
}

float Alumno::operator --(int){
    float creditos_tot=0;
    for(int i=0;i<numcur;i++)
        creditos_tot =creditos_tot +lcurso[i].GetCredito();
    return creditos_tot;        
}

float Alumno::operator ++(int){
    float creditos_ap=0;
    for(int i=0;i<numcur;i++)
        if(lcurso[i].GetNota()>10)
            creditos_ap =creditos_ap +lcurso[i].GetCredito();
    return creditos_ap;    
}
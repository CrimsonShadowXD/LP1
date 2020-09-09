/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: crimson
 * 
 * Created on July 2, 2020, 7:34 PM
 */

#include "Curso.h"

Curso::Curso() {
    ccurso=NULL;  
    ciclo=-1;
}

Curso::~Curso() {
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

void Curso::SetCcurso(char *cad) {
    if(ccurso !=NULL ) 
        delete[] ccurso;
    this->ccurso = new char[strlen(cad)+1];
    strcpy(this->ccurso,cad);
}

void Curso::GetCcurso(char *cad) const {
    if(ccurso==NULL){
        return;
    }
    strcpy(cad,this->ccurso);
}

Curso Curso::operator =(const Curso &curso){
    asignar(curso);    
}

void Curso::asignar(const Curso &curso){
    cout<<"entra asiganar"<<endl;
    char aux[10];
    curso.GetCcurso(aux);
    this->SetCcurso(aux);
    this->SetCiclo(curso.GetCiclo());
    this->SetNota(curso.GetNota());
    this->SetCredito(curso.GetCredito());
}

bool Curso::operator ==(const Curso &curso){
    return compare(curso);
}

bool Curso::compare(const Curso &curso){
    cout<<"entra comp"<<endl;
    char cod1[10],cod2[10];
    int ciclo1,ciclo2;
    GetCcurso(cod1);
    curso.GetCcurso(cod2);
    ciclo1=GetCiclo();
    ciclo2=curso.GetCiclo();
    
//    cout<<cod1<<' '<<cod2<<endl;
//    cout<<ciclo1<<' '<<ciclo2<<' '<<ciclo1-ciclo2<<endl;
//    cout<<strcmp(cod1,cod2)<<endl;
    return (strcmp(cod1,cod2)==0 && ciclo1==ciclo2);
}

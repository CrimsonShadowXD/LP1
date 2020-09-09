/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: crimson
 * 
 * Created on July 15, 2020, 9:34 AM
 */

#include "Curso.h"

Curso::Curso() {
    ccurso=NULL;
    nota=-1;
    ciclo=-1;
    credito=-0.1;
}

Curso::Curso(const Curso& orig) {
    ccurso=NULL;
    *this = orig;
}

Curso::~Curso() {
}

void Curso::SetCredito(double credito) {
    this->credito = credito;
}

double Curso::GetCredito() const {
    return credito;
}

void Curso::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::GetCiclo() const {
    return ciclo;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetCcurso(const char* cad) {
    if (cad == NULL) return;
    if (ccurso != NULL) delete ccurso;
    ccurso = new char[strlen(cad) + 1];
    strcpy(ccurso, cad);
}

void Curso::GetCcurso(char* cad) const {
    if (ccurso == NULL)
        return;
    strcpy(cad, ccurso);
}

void Curso::operator=(const Curso&c){
    char cad[10];
    c.GetCcurso(cad);
    SetCcurso(cad);
    SetCiclo(c.GetCiclo());
    SetCredito(c.GetCredito());
    SetNota(c.GetNota());
}

ofstream& operator<<(ofstream&out, Curso&c){
    char cad[10];
    c.GetCcurso(cad);
    out<<cad<<' '<<c.GetNota()<<' '<<c.GetCiclo()/10<<'-'<<c.GetCiclo()%10<<' '<<c.GetCredito();
    return out;
}
void operator>>(ifstream&in, Curso&c){
    //
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 4:32 AM
 */

#include "Nota.h"

Nota::Nota() {
    codcur=NULL;
    nota=-1;
    sem=NULL;
}

Nota::Nota(const Nota& orig) {
}

Nota::~Nota() {
}

void Nota::setSem(char* cad) {
    if (cad==NULL) return;
    if(sem!=NULL) delete sem;
    sem = new char[strlen(cad)+1];
    strcpy(sem,cad);
}

void Nota::getSem(char* cad) const {
    if(sem==NULL)
        return;
    strcpy(cad,sem);
}

void Nota::setNota(int nota) {
    this->nota = nota;
}

int Nota::getNota() const {
    return nota;
}

void Nota::setCodcur(char* cad) {
    if (cad==NULL) return;
    if(codcur!=NULL) delete codcur;
    codcur = new char[strlen(cad)+1];
    strcpy(codcur,cad);
}

void Nota::getCodcur(char*cad) const {
    if(codcur==NULL)
        return;
    strcpy(cad,codcur);
}

void Nota::leerNota(ifstream&in){
    int codAl,n;
    char cad[10],semes[10];
    in>>codAl;
    in.get();
    in.getline(cad,10,',');
    in>>n;
    in.get();
    in.getline(semes,10);
    
    setSem(semes);
    setNota(n);
    setCodcur(cad);
}

void Nota::imprimirNota(ofstream&out){
    char semes[10],cad[10];
    getSem(semes);
    getCodcur(cad);
    out<<semes<<endl;
    out<<getNota()<<endl;
    out<<cad<<endl;
    out<<"==================="<<endl;
}

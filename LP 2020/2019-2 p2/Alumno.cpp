/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: crimson
 * 
 * Created on July 7, 2020, 5:19 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    elem=NULL;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::leerAl(ifstream&in){
    char tipo;
    in>>tipo; 
    if (in.eof()) return;
    in.get();

    if (tipo=='I') 
        elem = new AlIntercambio;
    else if (tipo=='R') 
        elem = new AlRegular;

    elem->leer(in);
}

void Alumno::imprimirAl(ofstream&out){
    cout<<this->elem->GetCodigo()<<endl;;
    this->elem->imprimir(out);
}
